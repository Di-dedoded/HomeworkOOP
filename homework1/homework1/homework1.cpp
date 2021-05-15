#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

class Power {
	int _st = 2;
	int _multi = 4;

public:
	void set(float st, float multi)
	{
		_st = st;
		_multi = multi;
	}
	void calculate()
	{
		cout << "pow =  " << pow(_st, _multi) << endl;
	}
	~Power() {}

};

class RGBA
{
	uint8_t m_red = 0;
	uint8_t m_green = 0;
	uint8_t m_blue = 0;
	uint8_t m_alpha = 255;
public:
	RGBA()
	{
	}

	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
		:m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{
	}
	void print()
	{
		cout << "m_red = " << unsigned(m_red) << endl;
		cout << "m_green = " << unsigned(m_green) << endl;
		cout << "m_blue = " << unsigned(m_blue) << endl;
		cout << "m_alpha = " << unsigned(m_alpha) << endl;
		cout << endl;
	}

	~RGBA()
	{
	}
};

class Stack
{
private:
	int arr[10] = { 0 };
	int len = 0;
public:
	void reset()
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
		len = 0;
	}
	bool push(int num)
	{	
		if (len > 9)
		{
			return false;
		}
		else
		{
			arr[len] = num;
			len++;
		}

		return true;
	}
	void pop()
	{
		if (len <= 0)
		{
			cout << "stack not have values" << endl;
		}
		else
		{
			arr[len - 1] = 0;
			len--;
		}

	}
	void print()
	{
		cout << "( ";
		for (int i = 0; i < 10; i++)
		{
			if (arr[i] != 0)
			{
				cout << arr[i] << " ";
			}			
		}
		cout << ")";
		cout << endl;
	}
};

int main()
{
	Power p;
	RGBA r;
	RGBA rg(255, 255, 255, 0);
	Stack stack;

	p.calculate();
	p.set(3, 3);
	p.calculate();
	cout << endl;
	r.print();	
	rg.print();
	cout << endl;

	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

}

