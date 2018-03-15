#include<iostream>
using namespace std;

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

    p->doSomething();

}