#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	virtual void Display()
	{
		cout << "Person Display" << endl;
	}
	virtual ~Person() {}
};
class Employee : public Person
{
public:
	void Display() override
	{
		cout << "Employee Display" << endl;
	}
};
class Manager : public Person
{
public:
	void Display() override
	{
		cout << "Manager Display" << endl;
	}
};
class Cleaner : public Person
{
public:
	void Display() override
	{
		cout << "Cleaner Display" << endl;
	}
};
int main()
{
	Person* people[10];
	int count = 0;
	
	// Read 5 strings to determine object types
	for (int i = 0; i < 5; i++)
	{
		string type;
		cout << "Enter person type (Employee/Manager/Cleaner): ";
		cin >> type;
		
		//Employee* emp = new Cleaner();
		if (type == "Employee")
		{
			people[count++] = new Employee();
		}
		else if (type == "Manager")
		{
			people[count++] = new Manager();
		}
		else if (type == "Cleaner")
		{
			people[count++] = new Cleaner();
		}
		//emp->Display();
	}	
	// Display all created objects
	for (int i = 0; i < count; i++)
	{
		people[i]->Display();
	}
	// Cleanup
	for (int i = 0; i < count; i++)
	{
		delete people[i];
	}
    return 0;
}