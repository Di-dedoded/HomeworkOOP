#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
int div(T a, T b)
{
    if (b == 0)
    {
        throw overflow_error("Divide by zero exception");
    }
    else
    {
        return a / b;
    }    
}

class Ex
{
private:
    float x;
public:
    Ex(float _x) :x(_x) {}
    float getX()
    {
        return x;
    }
};

class Bar
{
private:
    float y;
public:
    Bar() :y(0) {}

    void setY(float a)
    {
        if ((y + a) > 100)
        {
            throw Ex(y * a);
        }
        else
        {
            y = a;
        }
    }
};

class OffTheField
{
public:
    OffTheField(int x, int y, int _x, int _y)
    {
        cout << "Robot off the border field! \n" \
            << "entered coord x = " << x << "\n"\
            << "entered coord y = " << y << endl;

        cout << "current coord x = " << _x << " "\
            << "current coord y = " << _y << endl;
    }
};

class IllegalCommand
{
public:
    IllegalCommand(int x, int y, int _x, int _y)
    {
        cout << "Illegal Command \n" \
            << "entered coord x = " << x << "\n"\
            << "entered coord y = " << y << endl;

        cout << "current coord x = " << _x << "\n"\
            << "current coord y = " << _y << endl;
    }
};

class Robot
{
private:
    int _x = 0;
    int _y = 0;
public:
	void move(int x, int y)
	{
		if (x > 10 || y > 10)
		{
            throw OffTheField(x, y, _x, _y);
		}
        else if ((x == (_x + 1) || x == (_x - 1) || x == _x) && (y == (_y + 1) || y == (_y - 1) || y == _y))
        {
            _x = x;
            _y = y;

            cout << "current coord x = " << _x << "\n" \
                << "current coord y = " << _y << endl;
        }
        else
        {
            throw IllegalCommand(x, y, _x, _y);
        }
	}

};

int main()
{
    {
        try
        {
            cout << div<int>(2, 1);
        }
        catch (overflow_error& exception)
        {
            cout << exception.what();
        }
        catch (exception& exception)
        {
            cout << exception.what();
        }
    }

    cout << endl;

    {
        Bar b;
        try {
            int n;
            do
            {
                cout << "Input n: ";
                while (true)
                {                    
                    cin >> n;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                    }
                    else
                    {
                        break;
                    }
                }
                b.setY(n);

            } while (n != 0);
            
        }
        catch (Ex ex)
        {
            cout << "y * n = " << ex.getX() << endl;
        }
    }

    cout << endl;

    {
        Robot rob;
        try
        {
            int x,y;
            do
            {
                cout << "Input x: ";
                while (true)
                {                    
                    cin >> x;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                    }
                    else
                    {
                        break;
                    }
                }
                cout << "Input y: ";
                while (true)
                {                    
                    cin >> y;
                    if (std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                    }
                    else
                    {
                        break;
                    }
                }                
                rob.move(x, y);

            } while (0 < x < 10 || 0 < y < 10);
        }
        catch (IllegalCommand)
        {

        }
        catch (OffTheField)
        {

        }
    }
}
