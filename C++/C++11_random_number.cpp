
//随机数生成算法：
//C++ 11提供三种生成算法：

//linear_congruential_engine线性同余法
//mersenne_twister_engine梅森旋转法
//substract_with_carry_engine滞后Fibonacci

#include<iostream>
#include<random>
using namespace std;

int main() {
	
	default_random_engine random;

	//产生均匀分布的随机数
	uniform_int_distribution<int> dis1(0, 10);   //范围[]，int表示整数，因为它是一个模板，可以用int、long、short实例化
	uniform_real_distribution<double> dis2(0.0, 1.0); //范围[)，可以使用double、float实例化
	
	for (int i = 0; i < 10; i++)
	{
		cout << random() << " ";
	}
	cout<<endl;

	for(int i=0; i < 10; i++ )
	{
		cout<<dis1(random)<<" ";
	}
	cout<<endl;

	for(int i=0; i < 10; i++ )
	{
		cout<<dis2(random)<<" ";
	}
	cout<<endl;
	
}

