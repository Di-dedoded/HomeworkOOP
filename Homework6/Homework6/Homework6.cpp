#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

namespace myspace
{
    ostream& endll(ostream& out)
    {
        out.put('\n');
        out.put('\n');
        out.flush();
        return out;
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");

    {
        cout << '|' << setfill('*') << setw(14) << "Задание 1" << setw(5) << '|' << endl;
        int num;
        while (true) 
        {
            cout << "Введите целое число: ";
            cin >> num;
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
        cout << num << myspace::endll;
    }

    {
        cout << '|' << setfill('*') << setw(14) << "Задание 2" << setw(5) << '|' << endl;
        cout << "1" << myspace::endll;
        cout << "2" << myspace::endll;   
    }
    
}

