/*************************************************************************
    > File Name: 6_queueToStack.cpp
    > Title: 
    > Description: 
    > Created Time: 2014年05月02日 星期五 20时44分12秒
 ************************************************************************/

//用两个队列模拟栈
//插入直接在队尾插入，实现后进先出只能将前面所有元素移至另一个队列
//需要使用容器指针区分空和非空队列

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
class Stack
{
public:
	void Push(const T& node);
	T Pop();
private:
	queue<T> que1;
	queue<T> que2;
};

//在队列尾部插入元素
template<typename T>
void Stack<T>::Push(const T& node)
{
	queue<T> *q;
	if(que1.size()>=que2.size())
		q=&que1;
	else
		q=&que2;
	q->push(node);
}

//取队列尾部元素
template<typename T>
T Stack<T>::Pop()
{
	queue<T> *q1,*q2;
	if(que1.size()>=que2.size())
	{
		q1=&que1;
		q2=&que2;
	}
	else
	{
		q1=&que2;
		q2=&que1;
	}
	while(q1->size()!=1)
	{
		T& cur=q1->front();
		q1->pop();
		q2->push(cur);
	}
	T res=q1->front();
	q1->pop();
	return res;
}

int main()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	int t=s.Pop();
	cout<<t<<endl;
	t=s.Pop();
	cout<<t<<endl;
}
