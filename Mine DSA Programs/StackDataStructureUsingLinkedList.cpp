//Write a program to Use Stack Data Structure using Linked List in C++ programming with Ritik.
/*
Notes:-
        => What is Stack Data Structure ?
        -> Stack is used to stores a list of items in which an item can be added to or removed from the list only at one end.
        -> And it is based on the LIFO machinism it means (Last IN First Out).
*/
#include"iostream"
#include"conio.h"
using namespace std;

struct node {
    int data;
    node *next;
};

//Class is here.
class StackUsingLinkedList{
    private:
    node *top; // This will denote the top of the Stack.

    public:
    StackUsingLinkedList();
    bool isFull(); // This function is used to check an Stack is full or not.
    bool isEmpty(); // This function is used to check an stack is empty or not.
    void push(int); // This function is used to push/insert a new element on the Stack.
    int pop(); // This function is used to pop/remove top element of the stack.
    int peek(); // This function is used to peek/view top element of the stack.
    bool reverse(); // This function is used to reverse of the stack.
    int getSize(); //This function is used to get size of the stack.
    StackUsingLinkedList& operator=(StackUsingLinkedList &); //This is Assignment operloading.
    void displayStack(); // This function is used to print inserted element of the Stack.
    ~StackUsingLinkedList(); // This is a distructor of this StackUsingLinkedList class.

};

// Parameterized Constructor of Array Class.
StackUsingLinkedList::StackUsingLinkedList(){
    top= NULL;
}

// Function for checking the Array is Full or not.
// bool StackUsingLinkedList::isFull(){
//     return (capacity== top+ 1);
// }

// Function for checking the Array is empty or not.
bool StackUsingLinkedList::isEmpty(){
    return (top== NULL);
}

// Function for push() a new element on the Stack.
void StackUsingLinkedList::push(int value){
    node *n= new node;
    n->data= value;
    
    if(isEmpty()){
        n->next= NULL;
        top= n;
        cout<<value<<" : is Pushed successfully in the Stack."<<endl;
    }else{
        n->next= top;
        top= n;
        cout<<value<<" : is Pushed successfully in the Stack."<<endl;
    }
}

// Function for pop() top element from the Stack.
int StackUsingLinkedList::pop(){
    if(isEmpty()){
        cout<<"No element to pop in the stack."<<endl;
        return 0;
    }else{
        int x= top->data;
        node *temp= top;
        top= temp->next;
        delete temp;
        return x;
    }
}

// Function for peek() top element of the stack.
int StackUsingLinkedList::peek(){
    if(isEmpty()){
        cout<<"Can't Peek because of Empty stack."<<endl;
        return 0;
    }else{
        return top->data;
    }
}

// Function for reverse() of the stack.
bool StackUsingLinkedList::reverse(){
    if(isEmpty()){
        return false;
    }else{
        node *tempNode;
        tempNode= top;
        node *previousPtr= NULL;
        node *currentPtr= tempNode;
        node *nextPtr;

        while(currentPtr != NULL){
            nextPtr= currentPtr->next;
            currentPtr->next = previousPtr;

            previousPtr= currentPtr;
            currentPtr= nextPtr;
        }
        top= previousPtr;

        return true;
    }
}

// Function for getSize() of the Stack.
int StackUsingLinkedList::getSize(){
    int countNode= 0;
    node *temp= top;
    while(temp != NULL){
        temp= temp->next;
        countNode++;
    }
    return countNode;
}
/*
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
*/
// Function for displayingStack() data.
void StackUsingLinkedList::displayStack(){
    if(isEmpty()){
        cout<<"There is no element in the stack."<<endl;
    }else{
        node *temp= top;
        cout<<"|      |"<<endl;
        while(temp != NULL){
            cout<<"|  "<<temp->data<<"  |"<<endl;
            temp= temp->next;
        }
        cout<<"|______|"<<endl<<endl;
        delete temp;
    }
}

// This is the distructor of this class StackUsingLinkedList.
StackUsingLinkedList::~StackUsingLinkedList(){
    delete top;
}

int main(){

    system("Color 02");
    cout<<"Stack Data structure using Linked List in C++ programming\n"<<endl;

    int choice, element;

    StackUsingLinkedList sUL;

    while(1){

        cout<<"_________________________________________________"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"|    **** Please Select Your Operation. ****    |"<<endl;
        cout<<"|-----------------------------------------------|"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"|       1-> PUSH elements in the Stack.         |"<<endl;
        cout<<"|       2-> POP elements from the Stack.        |"<<endl;
        cout<<"|       3-> PEEK top element of Stack.          |"<<endl;
        cout<<"|       4-> Reversing the Stack.                |"<<endl;
        cout<<"|       5-> Total element count of Stack.       |"<<endl;
        cout<<"|       6-> Display elements of Stack.          |"<<endl;
        cout<<"|       7-> Stack is Empty of Not.              |"<<endl;
        cout<<"|       8-> Exit.                               |"<<endl;
        cout<<"|                                               |"<<endl;
        cout<<"*************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                sUL.push(element);
                break;
            }
            case 2: {
                system("cls");
                cout<<sUL.pop()<<" : is Popped Successfully from the Stack."<<endl;
                break;
            }
            case 3: {
                system("cls");
                cout<<sUL.peek()<<" : is on the Top of Stack."<<endl;
                break;
            }
            case 4: {
                if(sUL.reverse()){
                    system("cls");
                    cout<<"Stack has been reversed successfully."<<endl<<endl;
                    sUL.displayStack();
                }else{
                    system("cls");
                    cout<<"Can't Reverse because of Empty Stack."<<endl;
                }
                break;
            }
            case 5: {
                system("cls");
                cout<<sUL.getSize()<<" : elements is present in the stack."<<endl;
                break;
            }
            case 6: {
                system("cls");
                sUL.displayStack();
                break;
            }
            case 7: {
                system("cls");
                if(sUL.isEmpty()){
                    cout<<"Stack is Empty."<<endl;
                }else{
                    cout<<"Stack is not Empty."<<endl;
                }
                break;
            }
            case 8: {
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

    //getch();
    return(0);
}