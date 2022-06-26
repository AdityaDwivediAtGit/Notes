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
3. Provided the favourateprogrammingLanguage string to provide objects d1 and d2 to Developer Class in main()
4. Created a method called PrintProgLangMethod() to check if the details are properly stored.
5. Using a Getter Method, since private variable Name of Employee Class is not directly Accessible to Developer class.
6. Marking variable "Name" as Protected Access Modifier, so that it will be accessable to the child class Developer.
7. We cannot access methods of Developer class which are inerited by employee. eg. Ask for promotion()
    Because those derived methods of base class "employee" are by default private here.
    So, we have to declare base class as "public Employee"
    class Developer:Employee{
        is changed to
    class Developer:public Employee{
    Now, AskforPromotion method is accessable inside main class using object of Developer class
8. Creating a derived class "Teacher" form base class "Employee"
9. creating a constructor for Teacher class since default constructor is deleted in Employee class
    Now, it can be noted that, in main,
    when inheriting from Employee class        : Only methods inside the derived class are accessible
    when inheriting from public Employee class : All methods inside the derived class and Base Class are accessible
10. Created objects of Teacher and called Methods 
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
protected:
    string Name;

private:
    string Company;
    int Age;

public:
// Setters and Getters
    void setName_123(string name){ Name = name; }
    void setComp_123(string company){ Company = company; }
    void setAge__123(int age){
        if (age>=18)
            Age = age;
    }

    string getName_123(){ return Name; }
    string getComp_123(){ return Company; }
    int getAge__123(){ return Age; }

    // Constructor
    Employee(string name, string company, int age){
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



class Teacher:public Employee{
public:
    string Subject;
    void PrepareLesson(){
        cout<<Name<<" is preparing "<<Subject<<" Lesson."<<endl;
    }
    Teacher(string name, string company, int age, string subject):Employee(name, company, age){
        Subject = subject;
    }
};




// Creating a derived class for Inheritance
// class [Derived class] : [Base class]
class Developer:public Employee{
    // All the Attributes (Methods, veriables, etc.) from "Employee" are imported here.
    // But those derived methods of base class "employee" are by default private here.
    // So, we have to declate base class as "public Employee".
public:
    string FavouriteProgrammingLanguage;

    Developer(string name, string company, int age, string s1):Employee(name, company, age){
        // Note :                   we have not specified datatype here ^^^^^^^^^^^^^^^^^^
        FavouriteProgrammingLanguage=s1;
    }

    // Creating a Method to print the details of developers d1 and d2
    void PrintFavProgLangMethod(){
        // Printing using getter method, since private variable Name of Employee Class is not directly Accessible to Developer class.
        cout<<"(Getter method test) The favourate Programming language of "<<getName_123()<<" is "<<FavouriteProgrammingLanguage<<endl;
        // changed "Name" variable to protected access modifier and now it is accessable here
        cout<<"(protected test)     The favourate Programming language of "<<getName_123()<<" is "<<FavouriteProgrammingLanguage<<endl;
    }
};

int main()
{
    Developer d1 = Developer("Aditya Dwivedi", "RCOEM", 21, "Python");
    Developer d2 = Developer("Saldina Nurak", "freecodecamp and CodeBeauty", 25, "C++");
    d1.PrintFavProgLangMethod();
    d2.PrintFavProgLangMethod();
    d1.AskForPromotion();

    Teacher t = Teacher ("Akash", "Great School", 31, "Aerodynamics");
    t.PrepareLesson();
    t. AskForPromotion();
}

// Finished Inheritance (1:15:43)