#include <iostream>
#include <clocale>
#include <cmath>
#include <string>


using namespace std;

class Figure
{
public:    
    virtual double area() = 0;
    virtual ~Figure() {}
};

class Parallelogram : public Figure
{
private:
    double S;
    double side_a;
    double side_b;
    double alpha;
public:
    Parallelogram() = default;
	Parallelogram(double a, double b, double al)
		:side_a(a), side_b(b), alpha(al) {}
	double area() override
	{
		S = (side_a * side_b) * sin(alpha);
		return S;
	}
};

class Circle : public Figure
{
private:
    double S;
    double pi = 3.14;
    double rad;
public:
    Circle(double radius)
        :rad(radius) {}
    double area() override
    {
        S = pi * pow(rad, 2);
        return S;
    }
};

class Rectangle : public Parallelogram
{
private:
    double S;
    double side_a;
    double side_b;
public:
    Rectangle(double a, double b)
        :side_a(a), side_b(b) {}
    double area() override
    {
        S = side_a * side_b;
        return S;
    }
};

class Square : public Parallelogram
{
private:
    double S;
    double side_a;
public:
    Square(double a)
        :side_a(a) {}
     double area() override
    {
        S = pow(side_a, 2);
        return S;
    }
};

class Rhombus : public Parallelogram
{
private:
    double S;
    double side_a;
    double alpha;
public:
    Rhombus(double a, double al)
        : side_a(a), alpha(al) {}
    double area() override
    {
        S = pow(side_a, 2) * sin(alpha);;
        return S;
    }
};

void print(double S)
{
    cout << "Площадь равна = " << S << endl;
}

class Car
{
private:
    string company;
    string model;
public:
    Car()
    {
        cout << "Car default" << endl;
    }
    Car(string& comp, string& mod)
        :company(comp), model(mod) 
    {
        //cout << "Car: " << company << " " << model << endl;
        cout << company << " " << model << " ";
    }
    virtual ~Car()
    {
        cout << "Car destruct" << endl;
    }

};

class PassengerCar : virtual public Car
{
public:
    PassengerCar() {}
    PassengerCar(string comp, string mod)
        :Car(comp, mod) 
    {
        cout << "is PassengerCar"<< endl;
    }
};

class Bus : virtual public Car
{
public:
    Bus() {}
    Bus(string comp, string mod)
        :Car(comp, mod)
    {
        cout << "is Bus" << endl;
    }
};

class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(string comp, string mod)
        :Car(comp, mod)
    {
        cout << "is Minivan" << endl;
    }
};

class Fraction
{
private:
     int numerator;
     int denominator;
public:
    Fraction( int x,  int y)
    {
        if (y != 0)
        {
            numerator = x;
            denominator = y;
        }
        else
        {
            cout << "Введено неверное значение знаменателя. Будет использовано стандартное значение = 1." << endl;
            numerator = x;
            denominator = 1;
        }
    }
    Fraction operator+(const Fraction& frac) const
    {
        return Fraction(numerator + frac.numerator, denominator + frac.denominator);
    }
    Fraction operator-(const Fraction& frac) const
    {
        return Fraction(numerator - frac.numerator, denominator - frac.denominator);
    }
    Fraction operator-() const
    {
        return Fraction(-numerator, -denominator);
    }
    bool operator!() const
    {
        return (numerator == 1 && denominator == 1);
    }

    friend bool operator<(const Fraction& frac1, const Fraction& frac2);
    int getNum()
    {
        return numerator;
    }
    int getDenom()
    {
        return denominator;
    }
    void print()
    {
        cout << "числитель= " << numerator << " знаменатель= " << denominator << endl;
    }

};

bool operator<(const Fraction& frac1, const Fraction& frac2)
{
    return (frac1.numerator > frac2.numerator && frac1.denominator < frac2.denominator);
}

enum class CARD_SUIT
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHTH,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

enum class CARD_VALUE
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHTH,
    NINE,
    TEN
};

class Card 
{
private:
    CARD_SUIT c_suit;
    CARD_VALUE c_val;
    bool condition = false;
public:
    bool Flip()
    {
        if (condition == false)
            condition = true;
        else 
            condition = false;
    }
    CARD_VALUE GetValue()
    {
        return c_val;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    {
        Figure* a = nullptr;
        a = new Parallelogram(5, 5, 83);
        cout << "Параллелограмм" << endl;
        print(a->area());
        delete a;

        a = new Circle(5);
        cout << "Круг" << endl;
        print(a->area());
        delete a;

        a = new Rectangle(5, 6);
        cout << "Прямоугольник" << endl;
        print(a->area());
        delete a;

        a = new Square(6);
        cout << "Квадрат" << endl;
        print(a->area());
        delete a;

        a = new Rhombus(6, 63);
        cout << "Ромб" << endl;
        print(a->area());
        delete a;

        cout << endl;
    }

    {
        Car* c = nullptr;
        c = new PassengerCar("Toyaota", "Corolla");
        delete c;
        c = new Bus("Scania", "Touring");
        delete c;
        c = new Minivan("Hyundai", "Staria");
        delete c;

    }

    {
        Fraction fr1(1, 1);
        Fraction fr2(2, 3);
        Fraction fr3 = fr1 + fr2;
        Fraction fr4 = fr3 + fr2 - fr1;
        Fraction fr5(1, 1);
        fr1.print();
        fr2.print();
        fr3.print();
        fr4.print();
        cout << "числитель= " << -fr1.getNum() << " знаменатель= " << -fr1.getDenom() << endl;
        cout << endl;
        if (!fr5)
        {
            cout << "числитель= " << fr5.getNum() << " знаменатель= " << fr5.getDenom() << endl;
        }
        else
        {
            cout << "числитель= " << -fr5.getNum() << " знаменатель= " << -fr5.getDenom() << endl;
        }
        cout << endl;

        if (fr2 < fr3)
        {
            cout << "fr2 < fr3" << endl;
        }
        else
        {
            cout << "fr2 > fr3" << endl;
        }
    }

    {

    }
}
