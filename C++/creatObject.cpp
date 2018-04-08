#include<iostream>
using namespace std;

class testClass{

public:
    testClass(){
        cout<<"default constructor!"<<endl;
    }
    testClass(char A){
        cout<<A<<endl;
    }
    ~testClass(){
        cout<<"destructor!"<<endl;
    }
};

int main(){
    testClass *p;
    p = new testClass('b');   //b
    delete p;                 //destructor !

    testClass a; //default constructor!
                 //destructor !
    return 0;
}