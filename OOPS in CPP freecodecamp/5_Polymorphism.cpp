/*

Polymorphism = Greek word = Ability of an Object or Method to have many Forms
poly + morph = many forms = most common use is when a parent class reference is used to refer to an Object of a child class 

Note : When we call method using object we use "object.method()"
  But, when we call method using object pointer we use "object->method()"

1:25:00
The Work of "virtual" is to check weather the method is implimented in my derived classes or not
If yes, the method inside derived class is executed and same method in parent class is NOT executed
If no, the method inside base class is executed
Basically, most derived version of that method is executed


Steps taken :
1. Created a method "Work" in Employee Class.(prints checking email)
2. Called that work function using objects of teacher and developer in main.
    It shows the same output for all.
    But we want that method to show different work since work of every employee is not checking email.
    eg. Work of developer is programming and work of teacher is teaching.
    Now, er will try to impliment that.
3. Defining method Work in child classes of employee (same name "Work") 
4. Called the Work method using objects of different classes
5. Creating object pointer of Employee class and giving it the address of Developer class (MOST COMMON USE)
                              PARENT CLASS                                CHILD CLASS
6. using parent pointers to access methods of child
    Problem: When calling method Work, both object pointers return the (checking email) Work function inside the Employee class
             But, they should return contents inside their Work method
    Solution: Make method (Work) of Employee class virtual 
*/




#include <iostream>
using namespace std;





// creating abstract class (contract/user end)
class AbstractEmployee{
    virtual void AskForPromotion()=0;   // Rule : making mandatory
};




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

    // Created class for polymorphism
    virtual void Work(){
        cout<<Name<<" is checking emails, task backlog, Fixing Bugs and reporting them to the team."<<endl;
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

    void Work(){
        cout<<Name<<" is teaching "<<Subject<<"."<<endl;
    }
};




// Creating a derived class for Inheritance
// class [Derived class] : [Base class]
class Developer:public Employee{
public:
    string FavouriteProgrammingLanguage;

    Developer(string name, string company, int age, string s1):Employee(name, company, age){
        // Note :                   we have not specified datatype here ^^^^^^^^^^^^^^^^^^
        FavouriteProgrammingLanguage=s1;
    }

    // Creating a Method to print the details of developers d1 and d2
    void PrintFavProgLangMethod(){
        cout<<"(Getter method test) The favourate Programming language of "<<getName_123()<<" is "<<FavouriteProgrammingLanguage<<endl;
        cout<<"(protected test)     The favourate Programming language of "<<getName_123()<<" is "<<FavouriteProgrammingLanguage<<endl;
    }

    // This Method is defined for Polymorphism 
    void Work(){
        cout<<Name<<" is developing program and fixing bug using "<<FavouriteProgrammingLanguage<<"."<<endl;
    }
};




int main()
{
    Employee e = Employee("Aditya Dwivedi", "RCOEM", 21); 
    //           Employee( name, company, age)
    Developer d = Developer("Saldina Nurak", "freecodecamp and CodeBeauty", 25, "C++"); 
    //            Developer( name, company, age, FavouriteProgrammingLanguage)
    Teacher t = Teacher("Akash", "Great School", 31, "Aerodynamics");
    //          Teacher(name, company, age, subject)
    e.Work();
    d.Work();
    t.Work();


    Employee *ed = &d;    // parent class reference is used to refer to an Object of a child class (PARENT POINTER STORES ADDRESS OF CHILD)
    // This works because, Developer is orignally an Employee,
    // So statement can be simply Employee_Pointer stores value of Employee(Developer)
    Employee *et = &t;    // employee ed is developer and employee et is a teacher
    Employee *ee = &e;

    cout<<endl<<"Testing Pointers :"<<endl;
    // Note : When we call method using object we use "object.method()"
    //   But, when we call method using object pointer we use "object->method()"
    ed->Work();
    et->Work();
    ee->Work();

}

// Completed
// Great Thanks to FreeCodeCamp and Saldina Nurak (CodeBeauty) for making such a great course available to us for free.