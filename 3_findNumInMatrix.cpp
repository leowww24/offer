/*************************************************************************
  > File Name: findNumInMatrix.cpp
  > Title: 
  > Description: 
  > Created Time: 2014年05月01日 星期四 11时19分17秒
 ************************************************************************/

//在每行每列值均递增的数组中查找某个值

//1、二维数组参数的表示a[m][n]要求m,n为常数
//行参a[4][4]或a[][4]或(*a)[4]对应实参a或a[0](需要定义为a[4][4];如此定义m=n=4,a[m][n]不可以)
//int (*p)[4]=a; (m=n=4,a[m][n]，如此定义会编译错误)
//不定长二维数组只能转化为一维数组表示,即只能用int *a,int rows,int columns表示,根据二维数组在内存中连续存储表示为a[i*rows+j]

//2、查找方法应使每一次查找后尽可能缩小查找的范围
//从左上角查找一次只能排除一个元素，从右上角查找一次可以排除一行元素
//复杂度从O(mn)降低到O(m+n)

//1 3 5 7
//2 4 6 8
//3 5 7 9
//4 6 8 10

#include<iostream>
#include<fstream>
using namespace std;

//定义从右上角搜索的函数，将二维数组转化为一维数组表示
bool find(int *a,int rows,int columns,int x)
{
	int i=0;
	int j=columns-1;
	while(j>=0&&i<rows)
	{
		if(a[i*rows+j]>x)
			--j;
		else if(a[i*rows+j]<x)
			++i;
		else
			return true;
	}
	return false;
}

int main()
{
	int m=4,n=4;
	int a[m][n];
	ifstream cin("3_findNumInMatrix.txt");
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
		{
			cin>>a[i][j];
		}
	cout<<find(&a[0][0],m,n,7)<<endl;
}
