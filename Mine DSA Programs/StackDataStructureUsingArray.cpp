//Write a program to Use Stack Data Structure using Array in C++ programming with Ritik.
/*
Notes:-
        => What is Stack Data Structure ?
        -> Stack is used to stores a list of items in which an item can be added to or removed from the list only at one end.
        -> And it is based on the LIFO machinism it means (Last IN First Out).
*/
#include"iostream"
#include"conio.h"
using namespace std;

//Class is here.
class StackUsingArray{
    private:
    int top; // This will denote the top element of the Stack.
    int capacity; // Total size of Stack.
    int *ptr;

    public:
    StackUsingArray(int);
    bool isFull(); // This function is used to check an Stack is full or not.
    bool isEmpty(); // This function is used to check an stack is empty or not.
    void push(int); // This function is used to push/insert a new element on the Stack.
    int pop(); // This function is used to pop/remove top element of the stack.
    int peek(); // This function is used to peek/view top element of the stack.
    void reverse(); // This function is used to reverse of the stack.
    int getSize(); //This function is used to get size of the stack.
    StackUsingArray& operator=(StackUsingArray &); //This is Assignment operloading.
    void displayStack(); // This function is used to print inserted element of the Stack.
    ~StackUsingArray(); // This is a distructor of this StackUsingArray class.

};

// Parameterized Constructor of Array Class.
StackUsingArray::StackUsingArray(int size){
    if(size>0){
        capacity= size;
        top= -1;
        ptr= new int(size);
        //cout<<"Array has been created successfully"<<endl;
    }else{
        ptr= NULL;
        cout<<"Invalid index for Array creation."<<endl;
    }
}

// Function for checking the Array is Full or not.
bool StackUsingArray::isFull(){
    return (capacity== top+ 1);
}

// Function for checking the Array is empty or not.
bool StackUsingArray::isEmpty(){
    return (top== -1);
}

// Function for push() a new element on the Stack.
void StackUsingArray::push(int data){
    if(isFull()){
       cout<<"Stack is overFlow."<<endl;
    }else{
        top++;
        ptr[top]= data;
        cout<<data<<" : is Pushed successfully in the Stack."<<endl;
    }
}

// Function for pop() top element of the Stack.
int StackUsingArray::pop(){
    try{
        if(top == -1){
            throw 1;
        }else{
            int temp= ptr[top];
            top--;
            return temp;
        }
    }catch(int ex){
        cout<<"No element to pop in the stack."<<endl;
        return 0;
    }
}

// Function for peek() top element of the stack.
int StackUsingArray::peek(){
    try{
        if(top == -1){
            throw 1;
        }else{
            return ptr[top];
        }
    }catch(int ex){
        cout<<"Can't Peek because of Empty stack."<<endl;
        return 0;
    }
}

// Function for reverse() of the stack.
void StackUsingArray::reverse(){
    int temp; 
    for(int i=0;i<(top+1)/2;i++){ 
        temp= ptr[i]; 
        ptr[i]= ptr[top-i]; 
        ptr[top-i]= temp; 
    }
}

void reverseUsingRecursive(){
    
}

// Function for getSize() of the Stack.
int StackUsingArray::getSize(){
    return (top+ 1);
}

// Function for = Assignment operator overloading.
StackUsingArray& StackUsingArray::operator=(StackUsingArray &tempStack){
    if(this != &tempStack){
        capacity= tempStack.capacity;
        top= tempStack.top;
        if(ptr != NULL){
            delete []ptr;
        }
        ptr= new int[capacity];
        for(int i= 0; i<= top; i++){
            ptr[i]= tempStack.ptr[i];
        }
    }
    return *this;
}

// Function for displayingStack() data.
void StackUsingArray::displayStack(){
    if(isEmpty()){
        cout<<"There is no element in the stack."<<endl;
    }else{
        cout<<"|     |"<<endl;
        for(int i= top; i>= 0; i--){
            cout<<"|  "<<ptr[i]<<"  |"<<endl;
        }
        cout<<"|_____|"<<endl<<endl;
    }
}

// This is the distructor of this class StackUsingArray.
StackUsingArray::~StackUsingArray(){
    delete []ptr;
}

int main(){

    system("Color 02");
    cout<<"Stack Data structure using Array in C++ programming\n"<<endl;

    int choice, element, n;

    cout<<"Enter the Size to Create Stack = ";
    cin>>n;
    StackUsingArray sUA(n);

    system("cls");
    cout<<"Stack is Created successfully this size of : "<<n<<endl;

    while(1){

        cout<<"_________________________________________________"<<endl;
        cout<<"|\t                                        |"<<endl;
        cout<<"|    **** Please Select Your Operation. ****    |"<<endl;
        cout<<"|-----------------------------------------------|"<<endl;
        cout<<"|\t                                        |"<<endl;
        cout<<"|\t1-> PUSH elements in the Stack.         |"<<endl;
        cout<<"|\t2-> POP elements from the Stack.        |"<<endl;
        cout<<"|\t3-> PEEK top element of Stack.          |"<<endl;
        cout<<"|\t4-> Reversing the Stack.                |"<<endl;
        cout<<"|\t5-> Total element count of Stack.       |"<<endl;
        cout<<"|\t6-> Display elements of Stack.          |"<<endl;
        cout<<"|\t7-> Stack is Full or Not.               |"<<endl;
        cout<<"|\t8-> Stack is Empty of Not.              |"<<endl;
        cout<<"|\t9-> Exit.                               |"<<endl;
        cout<<"|\t                                        |"<<endl;
        cout<<"*************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                sUA.push(element);
                break;
            }
            case 2: {
                system("cls");
                cout<<sUA.pop()<<" : is Popped Successfully from the Stack."<<endl;
                break;
            }
            case 3: {
                system("cls");
                cout<<sUA.peek()<<" : is on the Top of Stack."<<endl;
                break;
            }
            case 4: {
                sUA.reverse();
                system("cls");
                cout<<"Stack has been reversed successfully."<<endl<<endl;
                sUA.displayStack();
                break;
            }
            case 5: {
                system("cls");
                cout<<sUA.getSize()<<" : elements is present in the stack."<<endl;
                break;
            }
            case 6: {
                system("cls");
                sUA.displayStack();
                break;
            }
            case 7: {
                system("cls");
                if(sUA.isFull()){
                    cout<<"Stack is FULL."<<endl;
                }else{
                    cout<<"Stack is not FULL."<<endl;
                }
                break;
            }
            case 8: {
                system("cls");
                if(sUA.isEmpty()){
                    cout<<"Stack is Empty."<<endl;
                }else{
                    cout<<"Stack is not Empty."<<endl;
                }
                break;
            }
            case 9: {
                exit(1);
                break;
            }
            default :{
                system("cls");
                cout<<"Invalid choice! Please choice a valid option."<<endl;
                break;
            }
        }
    }

    // cout<<sUA.pop()<<" : popped"<<endl;
    // cout<<sUA.peek()<<" : is on the peek."<<endl;
    // sUA.push(1);
    // sUA.push(2);
    // sUA.displayStack();
    // cout<<sUA.peek()<<" : is on the peek."<<endl;
    // sUA.push(3);
    // sUA.displayStack();
    // cout<<sUA.peek()<<" : is on the peek."<<endl;
    // sUA.reverse();
    // sUA.displayStack();

    // sUA.push(1);
    // sUA.push(2);
    // sUA.push(3);
    // sUA.push(4);
    // sUA.displayStack();
    // cout<<"Peeked element is : "<<sUA.peek();
    // StackUsingArray s(sUA);
    // cout<<endl;
    // s.push(6);
    // s.displayStack();

    //getch();
    return(0);
}