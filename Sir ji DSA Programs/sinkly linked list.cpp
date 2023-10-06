#include<stdio.h>
#include<conio.h>
using namespace std;
struct node
{
	int item;
	node *next;
};
class SLL
{
	private:
	node *start;
	public:
	SLL();
	void insertAtStart(int);
	void insertAtLast(int);
	node* search(int);	
	void insertAtAfter(node*,int);
	void deleteFirst();
	void deleteLast();
	void deleteNode(int);
	~SLL();
};
SLL::SLL()
{
	start=NULL;
}
void SLL::insertAtStart(int data)
{
	node *n;
	n=new node;
	n->item=data;
	n->next=start;
	start=n;
}
void SLL::insertAtLast(int data)
{
	node *n,*t;
	n=new node;
	n->item=data;
	n->next=NULL;
	if(start==NULL)
		start=n;
		else
		{
		t=start;
		while(t->next!=NULL)
		    t=t->next;
			t->next=n;		
		}
}
node* SLL::search(int item)
{
	node *t;
	t=start;
	while(t->next!=NULL)
	{
		if(t->item==item)
			return t;
				t=t->next;
	}
			return NULL;
	}
	
void SLL::insertAtAfter(node *temp,int data)
{
	node *n;
	if(temp!=NULL)
	{
	n=new node;
	n->item=data;
	n->next=temp->next;
	temp->next=n;
	}
}
void SLL::deleteFirst()
{
	node *t;
	if(start)
	{
		t=start;
		start=start->next;
		delete t;
	}
}
void SLL::deleteLast()
{
	node *t;
	if(start)
	{
		t=start;
		if(t->next==NULL)
		delete t;
		start=NULL;
	}
	else
	{
		while(t->next->next!=NULL)
			t=t->next;
			delete t->next;
			t->next=NULL;
		}
	}

void SLL::deleteNode(int data)
{
	node *t,*temp;
	if(start)
	{
		t=start;
		if(t->item==data)
		{
			start=start->next;
			delete t;
		}
	else
	{
		while(t->next!=NULL)
		{	
			if(t->next->item==data)
			{
			temp=t->next;
			t->next=temp->next;
			delete temp;
			break;
		}
		t=t->next;
			}
		}
	}
}
SLL::~SLL()
{
	deleteFirst();
	}		
