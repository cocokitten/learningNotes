#include<iostream>
using namespace std;

//虚函数用于实现动态多态（一个类函数的调用在运行时期才确定，而非编译期），
//即允许基类的指针调用子类的函数

class base{
    public:
    virtual void doSomething(){
        cout<<"i'm base class"<<endl;
    }
};

class derived:public base
{
    public:
    void doSomething(){
        cout<<"I'm derived class"<<endl;
    }
};

int main(){
    base *p = new derived;
    p->doSomething();   //I'm derived class

}