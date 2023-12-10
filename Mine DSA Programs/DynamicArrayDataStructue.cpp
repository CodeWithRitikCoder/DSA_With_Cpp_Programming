//Write a program to Create Dynamic Array Data Structure in C++ programming with Ritik.
//Program- 2.
#include"iostream"
#include"conio.h"
using namespace std;

//Classes code is here.
class DynamicArray{
    int capacity;
    int lastIndex;
    int *ptr;

    public:
        DynamicArray(); //This is my default constructor.
        DynamicArray(int); //This is my Parameterized constructor.
        DynamicArray(DynamicArray &); //This is my Copy constructor.
        DynamicArray & operator=(DynamicArray &); //This function is used to Overload Assignment operator.
        bool isEmpty(); //This function is used to check the array is empty or not.
        bool isFull(); //This function is used to check the array is Full or not.
        void append(int); //This function is used to append elements in to the Array.
        void insert(int, int); //This function is used to Insert elements at particular index in the Array.
        void edit(int, int); //This function is used to edit element at particular index in the filled array.
        void del(int); //This function is used to delete element at the particular index from the array.
        void getItem(int); //This function is used to getItem from the particular index from the array.
        int countItem(); //This function is used to count How many elements are stored in the array.
        void find(int); //This function is used to check the element is present or not in the whole array.
        int getCapacity(); //This function is used to count the size of the whole array.
        void getLastIndex(); //This function is used to get LastIndex of the array.
        void showData(); //This function is used to print filled array.
        ~DynamicArray();

    protected:
        void doubleArray();
        void halfArray();
        
};

//Defining all the functions of DynamicArray Class is here.

//Definition of Default constructor.
DynamicArray::DynamicArray(){

}

//Definition of parameterized constructor.
DynamicArray::DynamicArray(int size){
    if(size> 0){
        capacity= size;
        lastIndex= -1;
        ptr= new int[size];
        //cout<<"Dynamic array is created successfully block is : "<<size<<endl;
    }else{
        ptr= NULL;
        cout<<"Invalid index for Array Creation."<<endl;
    }
}

//Definition of copy constructor.
DynamicArray::DynamicArray(DynamicArray &obj){
    capacity= obj.capacity;
    lastIndex= obj.lastIndex;
    ptr= new int[capacity];
    for(int i= 0; i<= lastIndex; i++){
        ptr[i]= obj.ptr[i];
    }
}

//Definition of Assignment Operator overload function.
DynamicArray & DynamicArray::operator=(DynamicArray &obj){
    if(this!= &obj){
        if(ptr!= NULL){
            delete []ptr;
        }
        capacity= obj.capacity;
        lastIndex= obj.lastIndex;
        ptr= new int[capacity];
        for(int i= 0; i<= lastIndex; i++){
            ptr[i]= obj.ptr[i];
        }
    }
    return (*this);
}

//Definition of isEmpty function.
bool DynamicArray::isEmpty(){
    return (lastIndex== -1);
}

//Definiton of isFull function.
bool DynamicArray::isFull(){
    return (capacity== lastIndex+ 1);
}

//Definiton of append function.
void DynamicArray::append(int data){
    if(isFull()){
        doubleArray();
    }
    lastIndex++;
    ptr[lastIndex]= data;
}

//Definiton of Insert function.
void DynamicArray::insert(int index, int data){
    if(index< 0 || index> lastIndex+ 1){
        cout<<"invalid index indide insert function."<<endl;
    }
    else if(isFull()){
        doubleArray();
    }
    for(int i= lastIndex; i>= index; i--){
        ptr[i+ 1]= ptr[i];
    }
    ptr[index]= data;
    lastIndex++;

}

//Definition of edit function.
void DynamicArray::edit(int index, int data){
    if(index< 0 || index> lastIndex+ 1){
        cout<<"Invalid index inside edit function."<<endl;
    }
    else if(isEmpty()){
        cout<<"Array is Empty inside edit function."<<endl;
    }else{
        ptr[index]= data;
    }
}

//Definition of del function.
void DynamicArray::del(int index){
    if(index< 0 || index> lastIndex+ 1){
        cout<<"Invalid index inside del function."<<endl;
    }
    else if(isEmpty()){
        cout<<"Array is Empty inside del function."<<endl;
    }else{
        for(int i= index; i<= lastIndex; i++){
            ptr[i]= ptr[i+ 1];
        }
        lastIndex--;
        if(capacity> 1 && lastIndex+ 1<= capacity){
            halfArray();
        }
    }
}

//Definition of getItem function.
void DynamicArray::getItem(int index){
    if(index< 0 || index> lastIndex){
        cout<<"Invalid index inside getItem function."<<endl;
    }
    else if(isEmpty()){
        cout<<"Array is Empty inside getItem function."<<endl;
    }else{
        cout<<"Element at index "<<index<<" is : "<<ptr[index]<<endl;
    }
}

//Definition of count function.
int DynamicArray::countItem(){
    return (lastIndex+ 1);
}

//Definition of find function.
void DynamicArray::find(int data){
    if(isEmpty()){
        cout<<"Array is Empty inside find function."<<endl;
    }else{
        bool f= true;
        for(int i= 0; i<= lastIndex; i++){
            if(data== ptr[i]){
                cout<<"This element "<<data<<" at index : "<<i<<endl;
                f= false;
                break;
            }else{
                f= true;
            }
        }
        if(f){
            cout<<"Not find this "<<data<<" in this array."<<endl;
        }
    }
}

//Definition of getSize function.
int DynamicArray::getCapacity(){
    return (capacity);
}

//Definition of getLastIndex function.
void DynamicArray::getLastIndex(){
    cout<<"Last Index is : "<<lastIndex<<endl;
}

//Definition of printArray function.
void DynamicArray::showData(){
    cout<<"[ ";
    for(int i= 0; i<= lastIndex; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<"]"<<endl;
}

//Definition of Distructor.
DynamicArray::~DynamicArray(){
    delete []ptr;
    //cout<<"Array has been deleted"<<endl;
}

//Definition of doubleArray Function.
void DynamicArray::doubleArray(){
    capacity*= 2;
    int *ptrTemp;
    ptrTemp= new int[capacity];
    for(int i= 0; i<= lastIndex; i++){
        ptrTemp[i]= ptr[i];
    }
    delete []ptr;
    ptr= ptrTemp;
}

//Definition of halfArray function.
void DynamicArray::halfArray(){
    int *ptrTemp;
    ptrTemp= new int[capacity/2];
    for(int i= 0; i<= lastIndex; i++){
        ptrTemp[i]= ptr[i];
    }
    delete []ptr;
    ptr= ptrTemp;
    capacity/= 2;
}

//Here it is my main() function.
int main(){
    cout<<"Dynamic Array Data Structure in C++ programming.\n"<<endl;
    
    DynamicArray dA1(3);

    dA1.append(2);
    dA1.append(4);
    dA1.append(6);
    dA1.append(6);
    dA1.showData();

    cout<<"The capacity of array is : "<<dA1.getCapacity()<<endl;

    dA1.del(1);
    dA1.showData();
    cout<<"The capacity of array is : "<<dA1.getCapacity()<<endl;

    dA1.del(1);
    dA1.showData();
    cout<<"The capacity of array is : "<<dA1.getCapacity()<<endl;
    dA1.getLastIndex();

    cout<<"Is array full or not : "<<dA1.isFull()<<endl;
    cout<<"Is array empty or not : "<<dA1.isEmpty()<<endl;

    cout<<endl;
    dA1.insert(1, 10);
    dA1.showData();

    cout<<"The capacity of array is : "<<dA1.getCapacity()<<endl;
    dA1.getLastIndex();

    cout<<"Total item in the array till the now is : "<<dA1.countItem()<<endl;
    dA1.getLastIndex();

    // cout<<endl;
    // dA1.getItem(1);
    // dA1.insert(0, 20);
    // dA1.showData();
    // cout<<"The capacity of array is : "<<dA1.getCapacity()<<endl;
    // dA1.getLastIndex();
    // cout<<"Total item in the array till the now is : "<<dA1.countItem()<<endl;

    // cout<<endl;
    // dA1.append(50);
    // dA1.showData();
    // cout<<"The capacity of array is : "<<dA1.getCapacity()<<endl;
    // dA1.getLastIndex();
    // cout<<"Total item in the array till the now is : "<<dA1.countItem()<<endl;

    // cout<<endl;
    // DynamicArray dA2(2);
    // dA2.append(44);
    // dA2.showData();
    // cout<<"The capacity of array is : "<<dA2.getCapacity()<<endl;
    // dA2.getLastIndex();
    // cout<<"Total item in the array till the now is : "<<dA2.countItem()<<endl; 

    // cout<<endl;52
    // dA1.getItem(3);
    // dA1.find(10);
    // dA1.find(44);

    // cout<<endl;5
    // dA1.append(11);
    // dA1.append(22);
    // dA1.append(31);
    // dA1.showData();
    // cout<<"The capacity of array is : "<<dA1.getCapacity()<<endl;
    // dA1.getLastIndex();
    // cout<<"Total item in the array till the now is : "<<dA1.countItem()<<endl;

    // cout<<endl;
    // dA1.del(1);
    // dA1.showData();
    // cout<<"The capacity of array is : "<<dA1.getCapacity()<<endl;
    // dA1.getLastIndex();
    // cout<<"Total item in the array till the now is : "<<dA1.countItem()<<endl;
    
    // cout<<endl;
    // DynamicArray dA3= dA1;
    // dA3.showData();
    // cout<<"The capacity of array is : "<<dA3.getCapacity()<<endl;
    // dA3.getLastIndex();
    // cout<<"Total item in the array till the now is : "<<dA3.countItem()<<endl;

    // cout<<endl;
    // DynamicArray dA4(dA1);
    // dA4.showData();
    // cout<<"The capacity of array is : "<<dA4.getCapacity()<<endl;
    // dA4.getLastIndex();
    // cout<<"Total item in the array till the now is : "<<dA4.countItem()<<endl;

    // cout<<endl;
    // DynamicArray dA5;
    // dA5= dA1;
    // dA5.showData();

    //getch();
    return(0);
}