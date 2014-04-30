/*************************************************************************
    > File Name: copyConstructor.cpp
    > Created Time: 2014年04月29日 星期二 20时16分01秒
 ************************************************************************/

//拷贝构造函数禁止使用值类型参数

#include<iostream>
using namespace std;

class A
{
private:
	int val;
public:
	A(int n):val(n){}
	//拷贝构造函数禁止使用值类型参数
	//（实参向形参传递时调用自身），无限递归，编译错误
	A(A other):val(other.val){}
};

int main()
{
	A a(3);
	A b=a;
}
