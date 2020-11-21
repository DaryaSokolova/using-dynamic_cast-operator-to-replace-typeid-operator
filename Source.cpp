//использование опреатора dinamic_cast для замены опреатора typeid
#include <iostream>
#include <typeinfo>

using namespace std;

class Base 
{
public:
	virtual void f() {}
};

class Derived : public Base
{
public:
	void derivedOnly()
	{
		cout << "Объект класса Derived \n";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Base* bp, b_ob;
	Derived* dp, d_ob;

	//typeid
	bp = &b_ob;
	if (typeid(*bp) == typeid(Derived))
	{
		dp = (Derived*)bp;
		dp->derivedOnly();
	}
	else
	{
		cout << "Приведение типа Base к типу Derived невозможно \n";
	}

	bp = &d_ob;
	if (typeid(*bp) == typeid(Derived))
	{
		dp = (Derived*)bp;
		dp->derivedOnly();
	}
	else
	{
		cout << "Ошибкаб приведение невозможно \n";
	}

	//dynamic_cast
	bp = &b_ob;
	dp = dynamic_cast<Derived*>(bp);
	if (dp)
	{
		dp->derivedOnly();
	}
	else
	{
		cout << "Приведение типа Base к типу Derived невозможно \n";
	}

	bp = &d_ob;
	dp = dynamic_cast<Derived*>(bp);
	if (dp)
	{
		dp->derivedOnly();
	}
	else
	{
		cout << "Ошибкаб приведение невозможно \n";
	}

	return 0;
}