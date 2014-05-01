/*************************************************************************
    > File Name: sizeof.cpp
    > Created Time: 2014年04月29日 星期二 16时24分22秒
 ************************************************************************/

//sizeof类名（返回sizeof类实例大小）
//static不属于实例大小
//空类的大小，表示实例在内存中空间占用，返回1
//函数地址与类实例无关，不占空间
//需函数会引入指向虚表的指针
//虚继承（节省公共基类的空间占用）会引入指向虚基类的指针

#include<iostream>
using namespace std;

class A
{
	static int val;	//static成员不属于任何实例
};

//函数不属于类实例的内容，只要知道函数地址即可调用，因此不属于sizeof
class B
{
public:
	B(){}
	~B(){}
	int val;
};

//虚表是编译器生成的，无论几个虚函数，只要一个指针指向虚表（64位系统）
class C
{
	C(){}
	virtual void func(){}
	virtual void func2(){}
};

class D:public B
{
	D():B(){}
	int Dval;
};
//虚继承会引入一个指向父类的指针
class VD:virtual public B	
{
	VD():B(){}
	int Dval;
};

int main()
{
	cout<<"爷这是64位系统（int 4  int* 8）："<<endl;
	cout<<"空类A:"<<sizeof(A)<<endl;
	A a;
	cout<<"类实例a:"<<sizeof(a)<<endl
		<<"含有构造函数和int成员的类B:"<<sizeof(B)<<endl
		<<"含有两个虚函数的类C:"<<sizeof(C)<<endl
		<<"继承B的含有一个int的D:"<<sizeof(D)<<endl
		<<"继承B的含有一个int的VD（虚继承）"<<sizeof(VD)<<endl;
}
