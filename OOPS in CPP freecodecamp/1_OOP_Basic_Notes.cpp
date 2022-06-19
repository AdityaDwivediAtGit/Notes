/*
Already completed C++ basics by "Code with Harry"

OOP in C++ course by Saldina Nurak (freecodecamp.org)
completed learning till 30:36
But restarting course for making notes

Points :
1. Class is a user defined datatype
2. Object = Variable of Class
3. Method = Function inside Class
4. Constructor = Method with same name as class but no returntype. Constructors are usually public.
*/

#include <iostream>

using namespace std;

// using std::string;
/* if we dont write above line (namespace standard for string), we have to write std:: everywhere
eg:
class Employee{
    std::string Name;
    std::string Company;
    int Age;
};    */

class Employee
{
public:
    // everything in class is private by default (not accessable outside Class)
    // so I have declared public access modifier to access it using main() function.
    string Name;
    string Company;
    int Age;

// declaring a Method
    void IntroduceYourself()
    {
        cout << "Hello," << endl
             << "My name is " << Name << "." << endl;
        cout << "I am " << Age << " years old and I work for " << Company << "." << endl;
    }

// Creating a constructor (default constructor is automatically used if not made one)
    Employee (string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    //  datatype Variable
    //  int      number;
    //  Employee employee1;

//  accessing members of class Employee when no constructor is made by user (default constructor present)
    // employee1.Name = "Aditya Dwivedi";
    // employee1.Company = "RCOEM";
    // employee1.Age = 21;
//  calling Method
    // employee1.IntroduceYourself();

    //Employee employee2;
    // employee2.Name = "Saldina Nurak";
    // employee2.Company = "freecodecamp";
    // employee2.Age = 25;
    // employee2.IntroduceYourself();

// using constructor to avoid writing above long statements as "employee2.Company = ..."
    Employee employee1 = Employee("Aditya Dwivedi","RCOEM",21);
    Employee employee2 = Employee("Saldina Nurak","freecodecamp",25);
    employee1.IntroduceYourself();
    employee2.IntroduceYourself();
}

/* 
Completed till 29:29
four most important concepts of OOP
1. Encapsulation
2. Abstraction
3. Inheritance
4. Polymorphism

continuing with Encapsulation in next notes
*/