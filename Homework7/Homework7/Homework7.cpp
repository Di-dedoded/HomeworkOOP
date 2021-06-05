#include <iostream>
#include <memory>

using namespace std;

class Date
{
private:
    int m_day;
    int m_month;
    int m_year;
public:
    Date()
        :m_day(1), m_month(1), m_year(1990) { }
    Date(int day, int month, int year)
        :m_day(day), m_month(month), m_year(year)
    {

    }
    ~Date() {}
    int getDay() const
    {
        return m_day;
    }
    int getMonth() const
    {
        return m_month;
    }
    int getYear() const
    {
        return m_year;
    }
    friend ostream& operator<<(ostream& out, Date& date);

};

ostream& operator<<(ostream& out, Date& date)
{
    out << date.m_day << '-' << date.m_month << '-' << date.m_year;
    return out;
}


Date compareDate(unique_ptr<Date>& ptr1, unique_ptr<Date>& ptr2)
{
	if (ptr1->getYear() < ptr2->getYear())
	{
		return *ptr2;
	}
	else if (ptr1->getYear() == ptr2->getYear())
	{
		if (ptr1->getMonth() < ptr2->getMonth())
		{
			return *ptr2;
		}
		else if (ptr1->getMonth() == ptr2->getMonth())
		{
            if (ptr1->getDay() < ptr2->getDay())
            {
                return *ptr2;
            }
            else if (ptr1->getDay() == ptr2->getDay())
            {
                cout << "The dates are the same" << endl;
                return *ptr2;
            }
            else
            {
                return *ptr1;
            }
		}
        else
        {
            return *ptr1;
        }
	}
    else
    {
        return *ptr1;
    }
}

int main()
{
    unique_ptr<Date> today = make_unique<Date>(05, 06, 2021);
    cout << "Day: " << today->getDay() << endl;
    cout << "Month: " << today->getMonth() << endl;
    cout << "Year: " << today->getYear() << endl;
    cout << *today << endl;

    unique_ptr<Date> date = move(today);

    if (today == nullptr)
        cout << "today is nullptr" << endl;  
    else 
        cout << "today is not nullptr" << endl;

    if (date == nullptr)    
        cout << "date is nullptr" << endl;    
    else
        cout << "date is not nullptr" << endl;

    unique_ptr<Date> date1 = make_unique<Date>(04, 02, 2021);
    unique_ptr<Date> date2 = make_unique<Date>(05, 06, 2019);

    cout << endl;

    today = make_unique<Date>(compareDate(date1, date2));
    cout << "is today " << *today << endl;
    cout << endl;
    cout << "is date1 " << *date1 << endl;
    cout << "is date2 " << *date2 << endl;
    cout << endl;
    date1.swap(date2);
    cout << "is swap date1 " << *date1 << endl;
    cout << "is swap date2 " << *date2 << endl;


    //cout << compareDate(date1, date2) << endl;

}
