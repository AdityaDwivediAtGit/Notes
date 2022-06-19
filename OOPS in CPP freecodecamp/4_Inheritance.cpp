/*Inheritance

Base Class = Super Class = Parent Class
Derived Class = Sub Class = Child Class

If a class (child) inherits another class (base),
Child class obtains all the members (same attributes and behaviours) of the base class. 
child class = attributes and behaviours of base class + attributes and behaviours of it's own.

Steps taken :
1. made a derived class "Developer" from base class "Employee"
2. made a constructor for Developer class
(Employee class has made a constructor. So, default constructor is not working in case of Employee class
since developer class is derived from employee class, so default constructor will also not be working in case of developer class.
Also, since all the variables of class Employee are copied to class Developer,
The constructor of Developer will also contain variables inside the employee class)
note : we dont have to specify type in the constructor of developer class when referencing to employee
*/


#include <iostream>
using namespace std;

// creating abstract class (contract/user end)
class AbstractEmployee{
    virtual void AskForPromotion()=0;   // Rule : making mandatory
};

// class "Employee" (developer) signing the contract "AbstractEmployee" (user end)
//class company: contract
class Employee:AbstractEmployee{
private:
    string Name;
    string Company;
    int Age;

public:
    // Constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    // 5. Mandatory method for Abstraction
    void AskForPromotion(){
        if(Age>30)
            cout<<Name<<" Got Promoted !"<<endl;
        else
            cout<<Name<<", Sorry ! no promotion for you."<<endl;
    }
};

// Creating a derived class for Inheritance
// class [Derived class] : [Base class]
class Developer:Employee{
    // All the Attributes (Methods, veriables, etc.) from "Employee" are imported here.
public:
    string s;

                               
    Developer(string name, string company, int age, string s1):Employee(name, company, age){
        // Note :                   we have not specified datatype here ^^^^^^^^^^^^^^^^^^
        s=s1;
    }
};

int main()
{
    Developer d1 = Developer("Aditya Dwivedi", "RCOEM", 21);
    Developer d2 = Developer("Saldina Nurak", "freecodecamp and CodeBeauty", 25);
}