/*************************************************************************
    > File Name: copyOperator.cpp
    > Created Time: 2014年04月29日 星期二 20时54分12秒
 ************************************************************************/

//完成一个类的赋值操作符的重载
//赋值操作的返回类型（要支持连续赋值，效率要高）
//赋值操作参数的类型
//边界问题（自身赋值）
//delete掉内存后野指针要设为NULL
//return *this 返回的是类对象的引用

//代码的异常安全（出现异常时不破坏程序原来状态）
//将delete放在new之后（new失败时还没有delete掉原值）
//使用局部类变量 A temp(oth);交换temp与this的指针成员，将异常放置与拷贝构造函数（安全的地方）同时利用了局部变量作用域结束时自动调用析构函数

#include<iostream>
using namespace std;

class A
{
private:
	int *pi;
public:
	A(int i):pi(new int(i)){}
	A& operator=(const A& oth)
	{
		if(this==&oth)
			return *this;
		delete pi;
		pi=NULL;
		pi=new int(*oth.pi);
		return *this;
	}
	void print(){cout<<*pi<<endl;}
};

int main()
{
	A a(1),b(2),c(3);
	b=a;	//注意之前要完成对bc的初始化，否则调用合成拷贝构造函数
	b.print();
	c=b=a;
	c.print();
}
