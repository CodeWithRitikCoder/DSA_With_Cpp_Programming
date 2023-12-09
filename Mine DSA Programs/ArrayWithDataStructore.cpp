//Write a program to Use Array with Data Structure with Ritik.
//Program- 1.
#include"iostream"
#include"conio.h"
using namespace std;

//Class is here.
class Array{
    private:
    int lastIndex; // Used size of Array.
    int capacity; // Total size of Array.
    int *ptr;

    public:
    Array(int);
    bool isFull(); // This function is used to check an array is full or not.
    bool isEmpty(); // This function is used to check an array is empty or not.
    void add(int); // This function is used to append element in the array.
    void add(int, int); // This function is used to insert element at any index under the array.
    void edit(int, int); // This function is used to edit element at specific index in the array.
    void remove(int); // This function is used to remove element at specific index from the array.
    void removeAll(); // This function is used to remove all the elements from the array.
    void getItem(int); // This function is used to Get Item from the particular index from the array.
    void count(); // This function is used to print total count of items of the array.
    void find(int); // This function is used to find index of particular data.
    void printArray(); // This function is used to print inserted element of the array.

};

// Parameterized Constructor of Array Class.
Array::Array(int size){
    capacity= size;
    lastIndex= -1;
    if(size>0){
        ptr= new int(capacity);
        //cout<<"Array has been created successfully"<<endl;
    }else{
        ptr= NULL;
        cout<<"Invalid index for Array creation."<<endl;
    }
}

// Function for checking the Array is empty or not.
bool Array::isEmpty(){
    return (lastIndex== -1);
}

// Function for checking the Array is Full or not.
bool Array::isFull(){
    return (capacity== lastIndex+ 1);
}

// Function for appand data into the Array.
void Array::add(int data){
    if(isFull()){
        cout<<"Array is Over flow."<<endl;
    }else{
        lastIndex+= 1;
        ptr[lastIndex]= data;
    }
}

// Function for insert data at specific index into the Array.
void Array::add(int index, int data){
    if(index< 0 || index> lastIndex+ 1){
        cout<<"Invalid index."<<endl;        
    }
    else if(isFull()){
        cout<<"Array of Over flow."<<endl;
    }else{
        for(int i= lastIndex; i>= index; i--){
            ptr[i+ 1]= ptr[i];
        }
        ptr[index]= data;
        lastIndex++;
    }
}

// Function for edit data at specific index into the Array.
void Array::edit(int index, int data){
    if(index> lastIndex){
        cout<<"This index can't editable."<<endl;
    }else{
        ptr[index]= data;
    }
}

// Function for remove/delete elements from the array.
void Array::remove(int index){
    if(index< 0 || index> lastIndex+ 1){
        cout<<"Invalid index."<<endl;
    }
    else if(isEmpty()){
        cout<<"Array is Empty."<<endl;
    }else{
        for(int i= index; i<= lastIndex; i++){
            ptr[i]= ptr[i+ 1];
        }
        lastIndex--;
    }
}

// Function for remove all the elements from the array.
void Array::removeAll(){
    delete[] ptr;
    lastIndex= -1;
}

// Function for getItem from the particular index from the array.
void Array::getItem(int index){
    if(index< 0 || index> lastIndex){
        cout<<"Invalid index."<<endl;
    }
    else if(isEmpty()){
        cout<<"Array is empty inside getItem"<<endl;
    }else{
        cout<<"Geted item is : "<<ptr[index]<<endl;
    }
}

// Function for print total inserted item in the array.
void Array::count(){
    cout<<"Total item is : "<<lastIndex+ 1<<endl;
}

// Function for finding index of particular data.
void Array::find(int data){
    if(isEmpty()){
        cout<<"Array is empty. inside find."<<endl;
    }else{
        for(int i= 0; i<= lastIndex; i++){
            if(data == ptr[i]){
                cout<<i<<endl;
                break;
            }
        }
    }
}

// Function for printing the whole filled array.
void Array::printArray(){
    for(int i= 0; i<= lastIndex; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    cout<<"Static Array Data Structure in C++ programming.\n";

    Array a1(6);
    a1.count();
    a1.add(2);
    a1.add(4);
    a1.add(5);
    a1.add(6);
    a1.add(1);
    a1.printArray();

    a1.add(5, 9);
    a1.printArray();

    a1.count();

    a1.remove(0);
    a1.printArray();

    a1.edit(0, 8);
    a1.printArray();

    a1.getItem(4);

    a1.count();

    a1.remove(0);

    a1.count();

    a1.find(9);

    a1.add(9);
    a1.printArray();

    a1.find(1);



    //getch();
    return(0);
}