/*************************************************************************
    > File Name: 6_rebuildTree.cpp
    > Title: 
    > Description: 
    > Created Time: 2014年05月04日 星期日 09时34分05秒
 ************************************************************************/

//二叉搜索树的构建
//二叉树的递归与非递归遍历

#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	int val;
	Node* lef;
	Node* rig;
	Node(int i):val(i),lef(NULL),rig(NULL){}
};

//构造二叉搜索树
void insert(Node **root,int val)
{
	Node* cur=new Node(val);
	if(*root==NULL)	//处理树为空的情况
	{
		*root=cur;
		return;
	}
	Node* parent=NULL;	//设置父子节点指针，寻找子节点为空的父节点
	Node* cld=*root;
	while(cld!=NULL)
	{
		parent=cld;
		if(cld->val>=val)
			cld=cld->lef;
		else
			cld=cld->rig;
	}
	if(parent->val>=val)
		parent->lef=cur;
	else
		parent->rig=cur;
}

//前序遍历的递归实现
void preOrder(Node* root)
{
	if(root==NULL)
		return;
	cout<<root->val<<endl;
	preOrder(root->lef);
	preOrder(root->rig);
}

//前序遍历的非递归实现，用栈模拟递归
void preOrderI(Node* root)
{
	cout<<"PreOrder Iterate:"<<endl;
	if(root==NULL)
		return;
	stack<Node*> stk;
	stk.push(root);
	while(!stk.empty())
	{
		Node* cur=stk.top();
		stk.pop();
		if(cur->rig!=NULL)
			stk.push(cur->rig);
		cout<<cur->val<<endl;
		if(cur->lef!=NULL)
			stk.push(cur->lef);
	}
}

int main()
{
	Node* root;
	insert(&root,8);
	insert(&root,3);
	insert(&root,9);
	insert(&root,1);
	insert(&root,5);
	insert(&root,4);
	insert(&root,6);

	preOrder(root);
	preOrderI(root);
}
