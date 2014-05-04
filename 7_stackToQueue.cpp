/*************************************************************************
    > File Name: 6_stackToQueue.cpp
    > Title: 
    > Description: 
    > Created Time: 2014年05月02日 星期五 20时27分39秒
 ************************************************************************/

//用两个栈模拟队列
//注意：没必要每次都清空另一个栈来完成插入和删除操作

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<typename T>
class Queue
{
public:
	void Push(const T& node);
	T Front();
private:
	stack<T> stk1;
	stack<T> stk2;
};

//stk1存放队列后半部分
template<typename T>
void Queue<T>::Push(const T& node)
{
	stk1.push(node);
}
//stk2存放逆序后的队列的前半部分
template<typename T>
T Queue<T>::Front()
{
	if(stk2.size()==0)
	{
		while(stk1.size()>0)
		{
			T& cur=stk1.top();
			stk1.pop();
			stk2.push(cur);
		}
	}
	T res=stk2.top();
	stk2.pop();
	return res;
}

int main()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	int h=q.Front();
	cout<<h<<endl;
	h=q.Front();
	cout<<h<<endl;
}
