/*************************************************************************
    > File Name: 4_replaceBlankInString.cpp
    > Title: 
    > Description: 
    > Created Time: 2014年05月01日 星期四 16时36分36秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdlib.h>	//malloc,realloc,calloc
using namespace std;

//注意要改变具体指针时需要**p
void replace(char **p)
{
	int cnt=0;
	for(char *cur=*p;*cur!='\0';++cur)
		if(*cur==' ')
			++cnt;
	char *res=new char[strlen(*p)+2*cnt+1];

	//realloc仅用于扩展malloc开辟的堆中的空间(当原地址后面有足够空间时直接扩充，否则另外开辟足够空间，复制然后自动free掉原空间)，对指向字符串常量的空间不能扩展
	//*p=(char*)realloc(*p,strlen(temp)+2*cnt+1);

	for(char *pt=*p,*pp=res;*pt!='\0';++pt)
	{
		if(*pt==' ')
		{
			*pp++='%';
			*pp++='2';
			*pp++='0';
		}
		else
			*pp++=*pt;
	}

	*p=res;
}

int main()
{
	char *a="abc def ";
	cout<<a<<endl;
	replace(&a);
	cout<<a<<endl;
}
