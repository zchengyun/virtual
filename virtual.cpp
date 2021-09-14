#include <iostream>

class Base
{
public:
	virtual void func()const
	{
		std::cout << "Base!" << std::endl;
	}
	~Base() {
		std::cout << "~Base!" << std::endl;
	}
};

class Base2
{
public:
	virtual void func2() = 0;
	~Base2() {
		std::cout << "~Base2!" << std::endl;
	}
};

class Derived :public Base2, public Base
{
public:
	virtual void func()
	{
		std::cout << "Derived!" << std::endl;
	}
	void func2() {
		std::cout << "Derived2!" << std::endl;
	}
	~Derived() {
		std::cout << "~Derived!" << std::endl;
	}
};

Base base;
Derived derived;

int main()
{
	/*Base!   Derived!   Derived2!  ~Derived!  ~Base!  ~Base2!  ~Base!*/
	base.func();
	derived.func();
	derived.func2();
	return 0;
}

