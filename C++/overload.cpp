
#include<iostream>

//const 参数重载解析 
 class A{
 public:
    int foo(int *test);
    int foo(const int *test);
};

 int A::foo(int *test){
    std::cout << *test << " A::foo(int *test)" <<std::endl;
    return 1;
}
 int A::foo(const int *test){
    std::cout << *test << " A::foo(const int *test)" <<std::endl;
    return 1;
}


//const成员函数重载
class B{
public:
    int fooB(int *test);   //可以看做 int fooB(A *this,int *test);
    int fooB(int *test) const; //可以看做 int fooB(const A *this,int *test);
};

int B::fooB(int *test){
    std::cout<<*test<<"fooB"<<std::endl;
    return 0;
}

int B::fooB(int *test) const {
    std::cout<<*test<<" fooB const"<<std::endl;
    return 0;
}


 int main()
{
    const int b =5;
    int c = 3;
    A a;
    a.foo(&b);   //输出：5 A::foo(const int *test)
    a.foo(&c);   //输出：3 A::foo(int *test)

    int d = 6;
    const B b1;
    b1.fooB(&d); //6 fooB const

    return 0;
}
