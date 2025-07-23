#include <iostream>

using namespace std;
class Student{
    public:
    string name;
    int age;
    double gpa;
Student(string x,int y,double z){
name=x;
age=y;
gpa=z;
}
};
int main(){  Student student1("sponge",28,4.23);
cout<<student1.name<<endl;
cout<<student1.age<<endl;
cout<<student1.gpa<<endl;
    return 0;
}
