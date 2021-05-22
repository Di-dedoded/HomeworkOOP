#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>

using namespace std;

enum Gender { NONE, MALE, FEMALE };

string& f_name()
{
	static string name;
	cout << "Введите имя: ";
	cin >> name;
	return name;
}

int& f_age()
{
	int age = 0;
	cout << "Введите возраст: ";
	cin >> age;
	return age;
}

Gender f_gender()
{
	Gender gender;
	int gen;
	cout << "Введите ваш пол 1 = Мужской, 2 = Женский: ";
	cin >> gen;
	if (gen == 1) gender = MALE;
	else if (gen == 2) gender = FEMALE;
	return gender;
}

double& f_weight()
{
	double weight = 0.0;
	cout << "Введите вес: ";
	cin >> weight;
	return weight;
}

int& f_year()
{
	int year;
	cout << "Введите год обучения: ";
	cin >> year;
	return year;
}


class Person
{
protected:
	string Name;
	int Age;
	Gender m_gender = NONE;
	double Weight;

public:
	Person(string& name, int age, Gender gender, double weight)
		:Name(name), Age(age), m_gender(gender), Weight(weight)
	{
	}
	Person(string& name, int age)
		:Name(name), Age(age)
	{
	}
	Person(string& name)
		:Name(name)
	{
	}
	void setName(string& name)
	{
		Name = name;
	}
	void setAge(int age)
	{
		Age = age;
	}
	void setWeight(double weight)
	{
		Weight = weight;
	}

};

static int quantity = 0;

class Student : Person
{
private:
	int YearOfStudy;
	
public:	
	//Student()
	//{
	//}
	Student(string& name, int age, Gender gender, double weight, int year)
		: Person(name, age, gender, weight), YearOfStudy(year)
	{
		quantity++;
	}
	Student(string& name, int year)
		: Person(name), YearOfStudy(year)
	{
		quantity++;
	}
	Student(string& name, int age, int year)
		: Person(name, age), YearOfStudy(year)
	{
		quantity++;
	}
	string& getName()
	{
		return Name;
	}
	int getAge()
	{
		return Age;
	}
	double getWeight()
	{
		return Weight;
	}
	Gender getGender()
	{
		return m_gender;
	}
	int getYear()
	{
		return YearOfStudy;
	}

};

class Fruit
{
protected:
	string Name;
	string Color;
	
public:
	Fruit() {}	
	Fruit(string name) :Name(name) {}
	Fruit(string& color) :Color(color) {}
	Fruit(string name, string color) :Name(name), Color(color) {}
	
};

class Apple : Fruit
{
public:	
	Apple() :Fruit("Apple") {}
	Apple(string color) :Fruit("Apple",color)
	{
	}
	Apple(string name, string color) : Fruit(name, color)
	{
	}
	string getName()
	{
		return Name;
	}
	string getColor()
	{
		return Color;
	}
};

class Banana : Fruit
{
public:
	Banana() :Fruit("Banana", "Yellow") {}
	Banana(string color) :Fruit("Banana", color)
	{
	}
	Banana(string name, string color) :Fruit(name, color)
	{
	}
	string getName()
	{
		return Name;
	}
	string getColor()
	{
		return Color;
	}
};

class GrannySmith : Apple
{
private:	
	string Name = Apple::getName();
	string Color = Apple::getColor();
public:
	GrannySmith() :Apple("GrannySmith", "Green") {}
	GrannySmith(string color) :Apple("GrannySmith", color)
	{
	}
	string getName()
	{		
		return Name;
	}
	string getColor()
	{		
		return Color;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	
	{
		Student Stud(f_name(), f_age(), f_gender(), f_weight(), f_year());
		cout << endl;
		Student Stud1(f_name(), f_age(), f_gender(), f_weight(), f_year());
		cout << endl;
		Student Stud2(f_name(), f_age(), f_gender(), f_weight(), f_year());
		cout << endl;

		string search;
		cout << "Введите имя для поиска: ";
		cin >> search;
		if (search == Stud.getName())
		{
			cout << "Имя: " << Stud.getName() << endl;
			cout << "Возраст: " << Stud.getAge() << endl;
			cout << "Пол: " << Stud.getGender() << endl;
			cout << "Вес: " << Stud.getWeight() << endl;
			cout << "Год обучения: " << Stud.getYear() << endl;
		}
		else if (search == Stud1.getName())
		{
			cout << "Имя: " << Stud1.getName() << endl;
			cout << "Возраст: " << Stud1.getAge() << endl;
			cout << "Пол: " << Stud1.getGender() << endl;
			cout << "Вес: " << Stud1.getWeight() << endl;
			cout << "Год обучения: " << Stud1.getYear() << endl;
		}
		else if (search == Stud2.getName())
		{
			cout << "Имя: " << Stud2.getName() << endl;
			cout << "Возраст: " << Stud2.getAge() << endl;
			cout << "Пол: " << Stud2.getGender() << endl;
			cout << "Вес: " << Stud2.getWeight() << endl;
			cout << "Год обучения: " << Stud2.getYear() << endl;
		}
		else
		{
			cout << "Такой студент не найден" << endl;
		}
	}

	{
		Apple a("red");
		Banana b;
		GrannySmith c;

		cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
		cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
		cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	}
	
}

