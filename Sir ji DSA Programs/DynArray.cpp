#include<iostream>
#include<conio.h>
#include<stdio.h>
 using namespace std;
 
 class DynArray
 {
 	private :
 		int Capacity;
 		int lastIndex;
 		int *ptr;
	protected :
		void doubleArray();
		void halfArray();
 		public :
 			DynArray(int);
 			DynArray(DynArray&);
 			DynArray& operator=(DynArray&);
 			int getCapacity();
 			bool isEmpty();
 			bool isFull();
 			void append(int data);
 			void insert(int index,int data);
 			void edit(int,int);
			void showData();
 			void delItem(int);
 			int countItem();
 			void getLastIndex();
 			void find(int);
 			DynArray();
			 ~DynArray();
 			
 };
 DynArray::DynArray()
 {
 	
 }
 DynArray::DynArray(int size)
 { 
 	if(size>0)
 	{
 	Capacity=size;
 	lastIndex=-1;
 	ptr=new int[Capacity];
 	}
 	else
 	ptr=NULL;
 	}
 	DynArray::DynArray(DynArray &a)
 	{
 		Capacity=a.Capacity;
 		lastIndex=a.lastIndex;
 		ptr=new int[Capacity];
 		for(int i=0;i<=lastIndex;i++)
 			ptr[i]=a.ptr[i];
 		}
 	DynArray& DynArray::operator=(DynArray &a)
	 {
	 	if(this!=&a)
		{
		if(ptr!=NULL)
		delete []ptr;
		Capacity=a.Capacity;
 		lastIndex=a.lastIndex;
 		ptr=new int[Capacity];
 		for(int i=0;i<=lastIndex;i++)
 		ptr[i]=a.ptr[i];
	}
	return *this;
		}	
 		
 	void DynArray::doubleArray()
 	{
 		int *temp;
 		temp= new int[Capacity*2];
 		for(int i=0;i<=lastIndex;i++)
 		 temp[i]=ptr[i];	
		 delete []ptr;
		 ptr=temp;
		 Capacity*=2; //Capacity=Capacity*2;
		 }
void DynArray::halfArray()
{
	int *temp;
	temp= new int[Capacity/2];
	for(int i=0;i<=lastIndex;i++)
	  temp[i]=ptr[i];
		delete []ptr;
		ptr=temp;
		Capacity/=2;
}
int DynArray::getCapacity()
{
	return Capacity;
}
bool DynArray::isEmpty()
{
	return lastIndex==-1;
}
bool DynArray::isFull()
{
	return lastIndex==Capacity-1;
}
void DynArray::append(int data)
{
	if(isFull())
		doubleArray();
		lastIndex++;
		ptr[lastIndex]=data;
	
}
void DynArray::insert(int index,int data)
{
	if(index<0 || lastIndex+1)
		cout<<"Invalid Index\n";
		else if(isFull())
				doubleArray();
				for(int i=lastIndex;i>=index;i--)
				ptr[i+1]=ptr[i];
				ptr[index]=data;
				lastIndex++;
}
void DynArray::edit(int index,int data)
{
	if(index<0 || index>lastIndex)
		cout<<"Invalid Index";
		ptr[index]=data;

}
void DynArray::showData()
{
	int i;
	for(i=0;i<=lastIndex;i++)
	cout<<ptr[i]<<" ";
}
void DynArray::delItem(int index)
{
	if(index<0 || index>lastIndex+1)
		cout<<"Invalid Index";
    	else if(isEmpty())
		{
			cout<<"Array is Empty";
		}
		for(int i=index;i<lastIndex;i++)
			ptr[i]=ptr[i+1];
			lastIndex--;
			if(Capacity>1 && lastIndex+1<=Capacity)
			halfArray();
			
}
void DynArray::getLastIndex()
{
	cout<<"\nLast Index : = "<<lastIndex;
}

int DynArray::countItem()
{
	return lastIndex+1;
}
DynArray::~DynArray()
{
	delete []ptr;
}
void DynArray::find(int index)
{
	if(index<0 || index>lastIndex)
	{
		cout<<"Invalid Index";
	}
	cout<<"\n"<<ptr[index];
}

int main()
{
	DynArray a1(5);
	a1.append(100);
	a1.append(200);
	a1.append(300);
	DynArray a2(5);
	a2=a1;
	a2.showData();
	getch();
}
