//Write a program to Use Queue Data Structure using Linked List in C++ programming with Ritik.
/*
Notes:-
        => What is Queue Data Structure ?
        -> Queue is used to stores a list of items in which an item can be inserted at one end and remove from the other end only.
        -> And it is based on the FIFO machinism it means (First In First Out).
*/
#include"iostream"
#include"conio.h"
using namespace std;

struct node {
    int data;
    node *next;
};

//Class is here.
class QueueUsingLinkedList{
    private:
    node *front, *back; // This of our Front and back tracker for the Queue.

    public:
    QueueUsingLinkedList(); // This is the constructor of QueueUsingLinkedList's Class to initialize the member variables.
    bool isEmpty(); // This function is used to check an Queue is empty or not.
    void enQueue(int); // This function is used to push/insert/enQueue a new element in the Queue.
    void deQueue(); // This function is used to pop/remove/deQueue Front element of the Queue.
    int peekFront(); // This function is used to peek/view front element of the Queue.
    int peekBack(); // This function is used to peek/view Back element of the Queue.
    int reverse(); // This function is used to reverse Queue elements.
    int getSize(); //This function is used to get filled size of the Queue.
    void clearQueue(); //This function is used to clear whole Queue.
    QueueUsingLinkedList& operator=(QueueUsingLinkedList &); //This is Assignment operloading.
    void displayQueue(); // This function is used to print inserted element of the Queue.
    ~QueueUsingLinkedList(); // This is a distructor of this QueueUsingLinkedList's class to dealocated initialized memory..

};

// Parameterized Constructor of QueueUsingLinkedList Class.
QueueUsingLinkedList::QueueUsingLinkedList(){
    front= NULL;
    back= NULL;
}

// Function for checking the Queue is empty or not.
bool QueueUsingLinkedList::isEmpty(){
    return (front == NULL && back == NULL);
}

// Function for push()/enQueue() a new element in the Queue.
void QueueUsingLinkedList::enQueue(int value){
    node *n= new node;
    n->data= value;
    n->next= NULL;

    if(front == NULL){
        back= n;
        front= n;
    }else{
        back->next= n;
        back= n;
    }
    cout<<value<<" : is enQueue successfully in the Queue."<<endl;

}

// Function for pop()/deQueue() Front element of the Queue.
void QueueUsingLinkedList::deQueue(){
    if(front == NULL){
        cout<<"There is no element to deQueue in Queue."<<endl;
    }else{
        node *toDelete= front;
        if(front == back){
            back= NULL;
        }
        front= front->next;
        cout<<"Front is deQueue Successfully from the Queue."<<endl;
        delete toDelete;
    }
}

// Function for peekFront() Front element of the Queue.
int QueueUsingLinkedList::peekFront(){
    if(front == NULL){
        cout<<"There is no element to Peek Front in Queue."<<endl;
        return -1;
    }else{
        return front->data;
    }
}

// Function for peekBack() Back element of the Queue.
int QueueUsingLinkedList::peekBack(){
    if(front == NULL){
        cout<<"There is no element to Peek Back in Queue."<<endl;
        return -1;
    }else{
        return back->data;
    }
}

// Function for reverse() elements of the Queue.
int QueueUsingLinkedList::reverse(){
    if(front == NULL){
        return -1;
    }else if(front->next == NULL){
        return 0;
    }else{
        node *tempNode;
        tempNode= front;
        node *previousPtr= NULL;
        node *currentPtr= tempNode;
        node *nextPtr;

        while(currentPtr != NULL){
            nextPtr= currentPtr->next;
            currentPtr->next = previousPtr;

            previousPtr= currentPtr;
            currentPtr= nextPtr;
        }
        back= front;
        front= previousPtr;

        return 1;
    }
}

// Function for getSize() of Queue.
int QueueUsingLinkedList::getSize(){
    int countNode= 0;
    node *temp= front;
    while(temp != NULL){
        temp= temp->next;
        countNode++;
    }
    delete temp;
    return countNode;
}

// Function for clearQueue() whole Queue.
void QueueUsingLinkedList::clearQueue(){
    if(isEmpty()){
        cout<<"Queue is Already Empty."<<endl;
    }else{
        front= back=  NULL;
        cout<<"The Whole Queue is Clear Successfully."<<endl;
    }
}

// Function for displayQueue() data.
void QueueUsingLinkedList::displayQueue(){
    if(front == NULL){
        cout<<"There is no element in the Queue."<<endl;
    }else{
        node *temp= front;
        while(temp != NULL){
            cout<<temp->data<<" <- ";
            temp= temp->next;
        }
        cout<<"[NULL]"<<endl;
        delete temp;
    }
}

// This is the distructor of this class QueueUsingLinkedList.
QueueUsingLinkedList::~QueueUsingLinkedList(){
    delete front, back;
}

int main(){

    system("Color 02");
    cout<<"Queue Data structure using Linked List in C++ programming\n"<<endl;

    int choice, element;

    QueueUsingLinkedList qUL;

    while(1){

        cout<<"___________________________________________________"<<endl;
        cout<<"|                                                 |"<<endl;
        cout<<"|    **** Please Select Your Operation. ****      |"<<endl;
        cout<<"|-------------------------------------------------|"<<endl;
        cout<<"|                                                 |"<<endl;
        cout<<"|       1-> EnQueue elements in the Queue.        |"<<endl;
        cout<<"|       2-> DeQueue elements from the Queue.      |"<<endl;
        cout<<"|       3-> PEEK Front element of Queue.          |"<<endl;
        cout<<"|       4-> PEEK Back element of Queue.           |"<<endl;
        cout<<"|       5-> Reversing the Queue.                  |"<<endl;
        cout<<"|       6-> Display elements of Queue.            |"<<endl;
        cout<<"|       7-> Queue is Empty of Not.                |"<<endl;
        cout<<"|       8-> Total element count of Queue.         |"<<endl;
        cout<<"|       9-> Clear Whole Queue.                    |"<<endl;
        cout<<"|       10-> Exit.                                |"<<endl;
        cout<<"|                                                 |"<<endl;
        cout<<"***************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                qUL.enQueue(element);
                break;
            }
            case 2: {
                system("cls");
                qUL.deQueue();
                break;
            }
            case 3: {
                system("cls");
                int temp= qUL.peekFront();
                if(temp != -1){
                    cout<<temp<<" : is Present on the Front of Queue."<<endl;
                }
                break;
            }
            case 4: {
                system("cls");
                int temp= qUL.peekBack();
                if(temp != -1){
                    cout<<temp<<" : is Present on the Back of Queue."<<endl;
                }
                break;
            }
            case 5: {
                int temp= qUL.reverse();
                if(temp == 1){
                    system("cls");
                    cout<<"Queue has been reversed successfully."<<endl<<endl;
                    qUL.displayQueue();
                }else if(temp == 0){
                    system("cls");
                    cout<<"Only one Element is Present in the Queue so we can't Reverse this Queue."<<endl;
                }else{
                    system("cls");
                    cout<<"Can't Reverse because of Empty Queue."<<endl;
                }    
                break;
            }
            case 6: {
                system("cls");
                qUL.displayQueue();
                break;
            }
            case 7: {
                system("cls");
                if(qUL.isEmpty()){
                    cout<<"Queue is Empty."<<endl;
                }else{
                    cout<<"Queue is not Empty."<<endl;
                }
                break;
            }
            case 8: {
                system("cls");
                cout<<qUL.getSize()<<" : elements is present in the Queue."<<endl;
                break;
            }
            case 9: {
                system("cls");
                qUL.clearQueue();
                break;
            }
            case 10: {
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

    // qUL.enQueue(10);
    // qUL.enQueue(20);
    // qUL.enQueue(30);
    // qUL.enQueue(40);
    // qUL.enQueue(50);
    // qUL.displayQueue();

    //getch();
    return(0);
}