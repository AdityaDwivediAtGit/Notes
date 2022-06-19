/*
Abstraction means hiding complex things behind the procedure that makes those things look simple.
eg. taking a picture and making a call looks simple on user's side, but is very complex on company's side.
Abstraction is like a contract signed by a class
In our case,
    Company (developer) = Employee class (contains the functioning of method "ask for promotion") 
    Contract (user) = AbstractEmployee class (not concerned with how the method "ask for promotion" is working)
    
Abstraction means summary. [byme]

Aim : If an employee asks for a promotion, make this decision look simple by examining various things about him.

Rule :
1. Whichever class decides to sign this contract, that class will need to provide implimentation for a method
    called "ask for promotion"

Steps Taken :
1. Create an Abstract class (create contract)
2. Make it mandatory for the class signing the contract to impliment "Ask for Promotion" method.
    This can be done by making "Ask for Promotion" a pure virtual Function.
3. Sign the contract
    syntax : 
        class [class signing the contract]:[contract]{
            ...
        };
4. Adding the "Ask for Promotion" Function in the class that signed the contract.
5. Add necessary conditions to examine the employee for taking the decisions in the function inside class that signed the contract.
    eg. if he is older than 30 years of age, he is elegible for promotion.
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
    /*
    Error if not added :
        error: invalid cast to abstract class type 'Employee'
        note:   because the following virtual functions are pure within 'Employee'
        error: cannot declare variable 'employee1' to be of abstract type 'Employee'
    */
    void AskForPromotion(){
        if(Age>30)
            cout<<Name<<" Got Promoted !"<<endl;
        else
            cout<<Name<<", Sorry ! no promotion for you."<<endl;
    }
};

int main()
{
    Employee employee1 = Employee("Aditya Dwivedi", "RCOEM", 21);
    Employee employee2 = Employee("Saldina Nurak", "freecodecamp and CodeBeauty", 25);
    employee1.AskForPromotion();
    employee2.AskForPromotion();
}

// completed Abstraction @ 39:50