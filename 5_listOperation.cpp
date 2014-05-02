/*************************************************************************
    > File Name: 5_addToTail.cpp
    > Title: 
    > Description: 
    > Created Time: 2014年05月02日 星期五 15时29分41秒
 ************************************************************************/

//链表操作
//链表头指针一般包含元素(不空情况下head->val即第一个元素)
//操作链表的函数由于可能修改头指针所以需要Node **head参数
//特别注意链表头指针为空情况


#include<iostream>
using namespace std;

struct Node
{
	Node *next;
	int val;
	Node(int i):next(NULL),val(i){}
};
//向链表结尾增加元素为x的结点
void addToTail(Node **head,int x)
{
	Node *cur=new Node(x);
	//注意判断链表是否为空
	if(*head==NULL)
	{
		*head=cur;
		return;
	}

	//链表不为空时找到尾结点，插入新结点
	Node *tail=*head;
	while(tail->next!=NULL)
		tail=tail->next;
	tail->next=cur;
}

//删除链表中所有元素为x的结点
void removeNode(Node **head,int x)
{
	//判断链表是否存在
	if(head==NULL||*head==NULL)
		return;

	//处理头指针指向要删除结点的情况
	while(*head!=NULL&&(*head)->val==x)
	{
		Node* toDelete=*head;
		*head=toDelete->next;
		delete toDelete;
		toDelete=NULL;
	}

	//此时可以肯定头指针指向的元素不含元素x,即p不是要删除的结点
	//删除p后面包含元素x的结点
	Node* p=*head;
	while(p!=NULL&&p->next!=NULL)
	{
		Node* toDelete=p->next;
		while(toDelete!=NULL&&toDelete->val==x)//处理多个x结点连续的i情况
		{
			Node *nextToDelete=toDelete->next;
			delete toDelete;
			toDelete=nextToDelete;
			p->next=toDelete;
		}
		p=toDelete;
	}
}

//顺次打印链表结点元素
void printList(Node* head)
{
	if(head==NULL)
		return;
	do
	{
		cout<<head->val<<" ";
		head=head->next;
	}while(head!=NULL);
}

//反向打印链表，递归实现，用栈模拟递归可增强代码的鲁棒性(避免递归栈溢出)
void reversePrint(Node* head)
{
	if(head==NULL)
		return;
	reversePrint(head->next);
	cout<<head->val<<" ";
}
int main()
{
	Node* head=NULL;
	addToTail(&head,2);
	addToTail(&head,2);
	addToTail(&head,4);
	addToTail(&head,5);
	addToTail(&head,7);
	addToTail(&head,2);

	printList(head);
	cout<<endl;

	reversePrint(head);
	cout<<endl;

	removeNode(&head,2);
	printList(head);

}
