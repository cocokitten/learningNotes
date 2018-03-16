#include<iostream>
using namespace std;

class A{
    public:
     A(){cout<<"i'm the constructor of class A!"<<endl;}
    ~A(){ cout<<"i'm the destructor of class A!"<<endl;}
};

class B:public A{
    public:
     B(){cout<<"i'm the constructor of class B!"<<endl;}
    ~B(){ cout<<"i'm the destructor of class B!"<<endl;}
};

class C:public B{
    public:
     C(){cout<<"i'm the constructor of class C!"<<endl;}
    ~C(){ cout<<"i'm the destructor of class C!"<<endl;}
};

int main(){

    C test;
    //输出
    //i'm the constructor of class A!  //构造函数的调用是从父类到子类
    //i'm the constructor of class B!   
    //i'm the constructor of class C!
    //i'm the destructor of class C!   //析构函数的调用顺序是从子类到父类
    //i'm the destructor of class B!
    //i'm the destructor of class A!

}