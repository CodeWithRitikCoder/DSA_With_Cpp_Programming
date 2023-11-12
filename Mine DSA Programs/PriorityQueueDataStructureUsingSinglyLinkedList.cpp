//Write a program to Use Queue Data Structure using Linked List in C++ programming with Ritik.
/*
Notes:-
        => What is PriorityQueue Data Structure ?
        -> A priority queue is a type of queue that arranges elements based on their priority values. Elements with higher priority values are typically retrieved before elements with lower priority values.

        -> In a priority queue, each element has a priority value associated with it. When you add an element to the queue, it is inserted in a position based on its priority value. For example, if you add an element with a high priority value to a priority queue, it may be inserted near the front of the queue, while an element with a low priority value may be inserted near the back.

        -> There are several ways to implement a priority queue, including using an array, linked list, heap, or binary search tree. Each method has its own advantages and disadvantages, and the best choice will depend on the specific needs of your application.

        -> Priority queues are often used in real-time systems, where the order in which elements are processed can have significant consequences. They are also used in algorithms to improve their efficiencies, such as Dijkstra’s algorithm for finding the shortest path in a graph and the A* search algorithm for pathfinding.
*/
#include"iostream"
#include"conio.h"
using namespace std;

struct node {
    int priority;
    int data;
    node *next;
};

//Class is here.
class PriorityQueueUsingLinkedList{
    private:
    node *start; // This is Start pointer of PriorityQueue.

    public:
    PriorityQueueUsingLinkedList(); // This is the constructor of PriorityQueueUsingLinkedList's Class to initialize the member variables.
    bool isEmpty(); // This function is used to check an PriorityQueue is empty or not.
    void enQueue(int, int); // This function is used to push/insert/enQueue a new element in the PriorityQueue.
    void deQueue(); // This function is used to pop/remove/deQueue Front element of the PriorityQueue.
    int getHighestPriorityData(); // This function is used to peek/view front element of the PriorityQueue.
    int getHighestPriorityNumber(); // This function is used to peek/view Back element of the PriorityQueue.
    int getSize();
    void clearPriorityQueue(); //This function is used to clear whole PriorityQueue.
    PriorityQueueUsingLinkedList& operator=(PriorityQueueUsingLinkedList &); //This is Assignment operloading.
    void displayPriorityQueue(); // This function is used to print inserted element of the PriorityQueue.
    ~PriorityQueueUsingLinkedList(); // This is a distructor of this PriorityQueueUsingLinkedList's class to dealocated initialized memory..

};

// Parameterized Constructor of PriorityQueueUsingLinkedList Class.
PriorityQueueUsingLinkedList::PriorityQueueUsingLinkedList(){
    start= NULL;
}

// Function for checking the PriorityQueue is empty or not.
bool PriorityQueueUsingLinkedList::isEmpty(){
    return (start == NULL);
}

// Function for push()/enQueue() a new element in the PriorityQueue.
void PriorityQueueUsingLinkedList::enQueue(int priorityNumber, int value){
    node *n= new node;
    node *temp1, *temp2;
    n->priority= priorityNumber;
    n->data= value;

    if(isEmpty()){
        n->next= NULL;
        start= n;
    }else{
        temp1= start;
        temp2= NULL;
        while(temp1){
            if(temp1->priority< priorityNumber){
                break;
            }else{
                temp2= temp1;
            }
            temp1= temp1->next;
        }
        if(temp2){
            n->next= temp1;
            temp2->next= n;
        }else{
            n->next= temp1;
            start= n;
        }
    }
    //delete temp1, temp2;
    cout<<value<<" : is enQueue successfully in the PriorityQueue."<<endl;
}

// Function for pop()/deQueue() highestPriority element from PriorityQueue.
void PriorityQueueUsingLinkedList::deQueue(){
    if(start == NULL){
        cout<<"There is no element to deQueue in PriorityQueue."<<endl;
    }else{
        node *toDelete= start;
        start= start->next;
        cout<<"Highest Priority Data is deQueue Successfully from the PriorityQueue."<<endl;
        delete toDelete;
    }
}

// Function for getHighestPriorityData() of the PriorityQueue.
int PriorityQueueUsingLinkedList::getHighestPriorityData(){
    if(isEmpty()){
        cout<<"Can't Find Highest Priority Data because of Empty PriorityQueue."<<endl;
        return -1;
    }else{
        return start->data;
    }
}

// Function for getHighestPriorityData() of the PriorityQueue.
int PriorityQueueUsingLinkedList::getHighestPriorityNumber(){
    if(isEmpty()){
        cout<<"Can't Find Highest Priority Number because of Empty PriorityQueue."<<endl;
        return -1;
    }else{
        return start->priority;
    }
}

// Function for getSize() of PriorityQueue.
int PriorityQueueUsingLinkedList::getSize(){
    int countNode= 0;
    node *temp= start;
    while(temp != NULL){
        temp= temp->next;
        countNode++;
    }
    return countNode;
}

// Function for clearQueue() whole PriorityQueue.
void PriorityQueueUsingLinkedList::clearPriorityQueue(){
    if(isEmpty()){
        cout<<"PriorityQueue is Already Empty."<<endl;
    }else{
        start=  NULL;
        cout<<"The Whole PriorityQueue is Clear Successfully."<<endl;
    }
}

// Function for displayPriorityQueue() data.
void PriorityQueueUsingLinkedList::displayPriorityQueue(){
    if(start == NULL){
        cout<<"There is no element to Display in the PriorityQueue."<<endl;
    }else{
        node *temp= start;
        while(temp){
            cout<<temp->data<<" <- ";
            temp= temp->next;
        }
        cout<<"[NULL]"<<endl;
        delete temp;
    }
}

// This is the distructor of this class PriorityQueueUsingLinkedList.
PriorityQueueUsingLinkedList::~PriorityQueueUsingLinkedList(){
    delete start;
}

int main(){

    system("Color 02");
    cout<<"PriorityQueue Data structure using Linked List in C++ programming\n"<<endl;

    int choice, element, priorityNumber;

    PriorityQueueUsingLinkedList pQUL;

    while(1){

        cout<<"__________________________________________________________________"<<endl;
        cout<<"|                                                                |"<<endl;
        cout<<"|           **** Please Select Your Operation. ****              |"<<endl;
        cout<<"|----------------------------------------------------------------|"<<endl;
        cout<<"|                                                                |"<<endl;
        cout<<"|       1-> EnQueue elements in the PriorityQueue.               |"<<endl;
        cout<<"|       2-> DeQueue elements from the PriorityQueue.             |"<<endl;
        cout<<"|       3-> Get Highest Priority element of PriorityQueue.       |"<<endl;
        cout<<"|       4-> Get Highest Priority Number of PriorityQueue.        |"<<endl;
        cout<<"|       5-> PriorityQueue is Empty of Not.                       |"<<endl;
        cout<<"|       6-> Total element count of PriorityQueue.                |"<<endl;
        cout<<"|       7-> Clear Whole PriorityQueue.                           |"<<endl;
        cout<<"|       8-> Display elements of PriorityQueue.                   |"<<endl;
        cout<<"|       9-> Exit.                                                |"<<endl;
        cout<<"|                                                                |"<<endl;
        cout<<"******************************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                cout<<"Enter priority number here : ";
                cin>>priorityNumber;
                system("cls");
                pQUL.enQueue(priorityNumber, element);
                break;
            }
            case 2: {
                system("cls");
                pQUL.deQueue();
                break;
            }
            case 3: {
                system("cls");
                int temp= pQUL.getHighestPriorityData();
                if(temp != -1){
                    cout<<temp<<" : is present on the highest priority in PriorityQueue."<<endl;
                }
                break;
            }
            case 4: {
                system("cls");
                int temp= pQUL.getHighestPriorityNumber();
                if(temp != -1){
                    cout<<temp<<" : is the highest priority Number of PriorityQueue."<<endl;
                }
                break;
            }
            
            case 5: {
                system("cls");
                if(pQUL.isEmpty()){
                    cout<<"PriorityQueue is Empty."<<endl;
                }else{
                    cout<<"PriorityQueue is not Empty."<<endl;
                }
                break;
            }
            case 6: {
                system("cls");
                cout<<pQUL.getSize()<<" : elements is present in the PriorityQueue."<<endl;
                break;
            }
            case 7: {
                system("cls");
                pQUL.clearPriorityQueue();
                break;
            }
            case 8: {
                system("cls");
                pQUL.displayPriorityQueue();
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

    // pQUL.enQueue(10, 10);
    // pQUL.displayPriorityQueue();
    // pQUL.enQueue(8, 20);
    // pQUL.displayPriorityQueue();
    // pQUL.enQueue(7, 30);
    // pQUL.displayPriorityQueue();
    // pQUL.enQueue(5, 40);
    // pQUL.displayPriorityQueue();
    // pQUL.enQueue(4, 50);
    // pQUL.displayPriorityQueue();
    // pQUL.enQueue(3, 60);
    // pQUL.displayPriorityQueue();
    // pQUL.enQueue(-1, 70);
    // pQUL.displayPriorityQueue();
    // pQUL.enQueue(11, 80);
    // pQUL.displayPriorityQueue();
    // pQUL.enQueue(9, 200);
    // pQUL.displayPriorityQueue();

    //getch();
    return(0);
}