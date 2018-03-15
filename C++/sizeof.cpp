#include <iostream>
using namespace std;

class S{
};

class S2{
public:
    S2(){};
    ~S2(){};
};

int main(){


    char *ss1="0123456789"; 
    cout<<sizeof(ss1)<<endl;//8

    int *p=nullptr;
    cout<<sizeof(p)<<endl;  //8,指针指向的是一个地址，32位系统就是4字节，64位系统就是8字节

    char ss2[]="0123456789";
    cout<<sizeof(ss2)<<endl;//11,一个字符占据空间为1，10个字节为10，再加上隐含的“\0”

    char ss3[100]="0123456789";
    cout<<sizeof(ss3)<<endl;//100

    int ss4[100];
    cout<<sizeof(ss4)<<endl;//100*4=400

    char q1[]="abc";
    cout<<sizeof(q1)<<endl;//3+1=4 
    //-------------------------------------
   
    cout<<sizeof(double)<<endl; //8
    cout<<sizeof(long)<<endl;   //8
    cout<<sizeof(long long)<<endl; //8
    cout<<sizeof(float)<<endl; //4
    cout<<sizeof(int)<<endl;  //4
    cout<<sizeof(short)<<endl; //2
    
    
    //-------------------------------------
    //struct
    struct{
        short a1;
        short a2;
        short a3;
    }A;

     struct{
        long a1;
        short a2;     
    }B;

    struct{
        int a1;
        double a2;
        float a3;    
    }C;

    cout<<sizeof(A)<<endl;  //6
    cout<<sizeof(B)<<endl; //16
    cout<<sizeof(C)<<endl; //16

    //-------------------------------------
    S test;
    S2 test2;
    cout<<"size of S:"<<sizeof(test)<<endl; //1
    cout<<"size of S2:"<<sizeof(test2)<<endl;//1
    //注意: C++编译器不允许对象为零长度。试想一个长度为0的对象在内存中怎么存放？怎么获取它的地址？
    //为了避免这种情况，C++强制给这种类插入一个缺省成员，长度为1。如果有自定义的变量，变量将取代这个缺省成员 
    //-------------------------------------

}