/*
Encapsulation :
Bundling or tying together DATA and METHODS that operate on that data.
Aim: To prevent anyone or anything outside of our class to directly.
Else we make our own way(functions) for other classes to interact with my class.
(getter and setter methods)

Steps taken :
1. make class variables private to make them inaccessable directly like Employee.Name
2. making a getter and setter functions (basically a function of any name that sets the values of variables)
    so if a person/other class knows the functions that can be used to read or change the class,
    then only he can access the data.
3. [Exceptional Step] Adding condition for setting values using setter functions
    eg. set age only if age >= 18 is provided.
*/

#include <iostream>
using namespace std;

class Employee
{
private:
    string Name;
    string Company;
    int Age;
    // now these cannot be accessed directly like Employee.Age
    // but can be accessed by public Constructor.
public:
//  Methods

    // 1. setter Methods
    void setName_123(string name){
        Name = name;
    }
    void setComp_123(string company){
        Company = company;
    }
    void setAge__123(int age){
        if (age>=18)
            Age = age;
    }

    // 2. getter Methods
    string getName_123(){
        return Name;
    }
    string getComp_123(){
        return Company;
    }
    int getAge__123(){
        return Age;
    }

    // 3. Other Methods (not a part of Encapsulation)
    void IntroduceYourself(){
        cout << "Hello," << endl
             << "My name is " << Name << "." << endl;
        cout << "I am " << Age << " years old and I work for " << Company << "." << endl;
    }

    // 4. Constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
};

int main()
{
    Employee employee1 = Employee("Aditya Dwivedi", "RCOEM", 21);
    Employee employee2 = Employee("Saldina Nurak", "freecodecamp and CodeBeauty", 25);
    employee1.IntroduceYourself();
    employee2.IntroduceYourself();

    // testing getter
    cout<<"testing getter for name : "<<employee1.getName_123()<<endl;
    cout<<"testing getter for Comp : "<<employee1.getComp_123()<<endl;
    cout<<"testing getter for Age  : "<<employee1.getAge__123()<<endl;

    // testing setter
    employee1.setName_123("You're Hacked Successfully !!! HeHeeHe");
    cout<<endl<<"testing setter for name for employee1 : "<<endl;
    cout<<"testing getter for name : "<<employee1.getName_123()<<endl;
    cout<<"testing getter for Comp : "<<employee1.getComp_123()<<endl;
    cout<<"testing getter for Age  : "<<employee1.getAge__123()<<endl;

// testing age setter condition
    bool age16Test = false;
    // sending age to test 18+
    cout<<endl<<"try setting age = 16: "<<endl;
    employee1.setAge__123(16);
    cout<<"testing getter for name : "<<employee1.getName_123()<<endl;
    cout<<"testing getter for Comp : "<<employee1.getComp_123()<<endl;
    cout<<"testing getter for Age  : "<<employee1.getAge__123()<<endl;
    if (employee1.getAge__123()>18){
        age16Test=true;
    }

    cout<<endl<<"try setting age = 60: "<<endl;
    employee1.setAge__123(60);
    cout<<"testing getter for name : "<<employee1.getName_123()<<endl;
    cout<<"testing getter for Comp : "<<employee1.getComp_123()<<endl;
    cout<<"testing getter for Age  : "<<employee1.getAge__123()<<endl;
    if (employee1.getAge__123()==60 and age16Test==true)
        cout<<"Condition of 18+ is working perfectly in setter"<<endl;

}
