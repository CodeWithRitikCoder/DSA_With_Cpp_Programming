//Write a program to Implement Data Structure with DE_Queue Using Doubly Linked list in C++ programming with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//My Node Structure is here.
struct node{
    node* previous;
    int data;
    node* next;
};

//My DE_QueueUsingDoublyLinkedList class is here.
class DE_QueueUsingDoublyLinkedList{
    private:
    node *front, *rear;

    public:
    //All functions declarations are here.
    DE_QueueUsingDoublyLinkedList(); // This is the default donstructor of this class.
    void insertAtFront(int); //This function is used to insert element at the Front of the DE_QueueUsingDoublylinkedlist.
    void insertAtRear(int); //This function is used to insert element at the Rear of the DE_QueueUsingDoublylinkedlist.
    void deleteAtFront(); //This function is used to delete element from first of the DE_QueueUsingDoublylinkedlist.
    void deleteAtRear(); //This function is used to delete element from last of the DE_QueueUsingDoublylinkedlist.
    int getFront(); //This function is used to get Front element of the DE_QueueUsingDoublylinkedlist.
    int getRear(); //This function is used to get Rear element of the DE_QueueUsingDoublylinkedlist.
    bool isEmpty(); //This function is used to check DE_Queue is Empty or not.
    void reverse(); //This funciton is used to reverse element of DE_QueueUsingDoublyLinkedlist.
    int length(); //This function is used to get the length of the DE_QueueUsingDoublyLinkedlist.
    void displayDE_Queue(); //This function is used to display the whole data of the DE_QueueUsingDoublylinkedlist.
    ~DE_QueueUsingDoublyLinkedList(); //This is the destructor of this class.
};

//Definition of all the function is here.

//Definiton of default constructor of class DE_QueueUsingDoublylinkedlist.
DE_QueueUsingDoublyLinkedList::DE_QueueUsingDoublyLinkedList(){
    front= NULL;
    rear= NULL;
}

//Definition of insertAtStart function of class DE_QueueUsingDoublylinkedlist.
void DE_QueueUsingDoublyLinkedList::insertAtFront(int value){
    node *n;
    n= new node;
    n->previous= NULL;
    n->data= value;
    n->next= front;
    if(front){
        front->previous= n;
    }else{
        rear= n;
    }
    front= n;
    cout<<endl<<value<<" : is Inserted successfully at the Front of DE_Queue."<<endl;
}

//Definition of insertAtLast function of class DE_QueueUsingDoublylinkedlist.
void DE_QueueUsingDoublyLinkedList::insertAtRear(int value){
    if(front == NULL){
       insertAtFront(value);
       return;
    }else{
        node *n= new node;
        n->previous= rear;
        n->data= value;
        n->next= NULL;
        rear->next= n;
        rear= n;
        cout<<endl<<value<<" : is Inserted successfully at the Rear of DE_Queue."<<endl;
    }
}

//Definition of deleteAtStart function of class DE_QueueUsingDoublylinkedlist.
void DE_QueueUsingDoublyLinkedList::deleteAtFront(){
    node *tempToDelete;
    if(front){
        if(front == rear){
            cout<<endl<<front->data<<" : is Deleted successfully at the Front of DE_Queue."<<endl;
            front= rear= NULL;
        }else{
            node *temp= front;
            front->next->previous= NULL;
            cout<<endl<<front->data<<" : is Deleted successfully at the Front of DE_Queue."<<endl;
            front= front->next;
            delete temp;

        }
    }else{
        cout<<endl<<"There is no element to DeleteAtFront in DE_Queue."<<endl;
    }
}

//Definition of deleteAtLast function of class DE_QueueUsingDoublylinkedlist.
void DE_QueueUsingDoublyLinkedList::deleteAtRear(){
    node *tempToDelete;
    if(front){
        if(front == rear){
            cout<<endl<<rear->data<<" : is Deleted successfully at the Rear of DE_Queue."<<endl<<endl;
            front= rear= NULL;
        }else{
            node *temp= rear;
            cout<<endl<<rear->data<<" : is Deleted successfully at the Rear of DE_Queue."<<endl<<endl;
            rear= rear->previous;
            rear->next= NULL;
            delete temp;
        }
    }
    else{
        cout<<endl<<"There is no element to DeleteAtRear in DE_Queue."<<endl<<endl;
    }
}

//Definition of getFront() function of class DE_QueueUsingDoublylinkedlist.
int DE_QueueUsingDoublyLinkedList::getFront(){
    if(isEmpty()){
        return -1;
    }else{
        return front->data;
    }
}

//Definition of getRear() function of class DE_QueueUsingDoublylinkedlist.
int DE_QueueUsingDoublyLinkedList::getRear(){
    if(isEmpty()){
        return -1;
    }else{
        return rear->data;
    }
}

//Definition of isEmpty() function of class DE_QueueUsingDoublylinkedlist.
bool DE_QueueUsingDoublyLinkedList::isEmpty(){
    if(front == NULL && rear == NULL){
        return true;
    }else{
        return false;
    }
}

//Definition of reverse function of class DE_QueueUsingDoublylinkedlist.
void DE_QueueUsingDoublyLinkedList::reverse(){
    

}

//Definition of countNode function of class DE_QueueUsingDoublylinkedlist.
int DE_QueueUsingDoublyLinkedList::length(){
    int count= 0;
    node *temp= front;
    while(temp != NULL){
        temp= temp->next;
        count++;
    }
    return count;
}

//Definition of display function of class DE_QueueUsingDoublylinkedlist.
void DE_QueueUsingDoublyLinkedList::displayDE_Queue(){
    node *temp= new node;
    temp= front;
    if(temp == NULL){
        cout<<endl<<"There is no node in the DE_Queue."<<endl;
    }else{
        cout<<endl<<"NULL<-";
        do{
            cout<<"P["<<temp->data<<"]N";
            if(temp->next != NULL){
                cout<<"<=>";
            }
            temp= temp->next;
        }while(temp != NULL);
        cout<<"->NULL"<<endl;
    }
    delete temp;
}

//Definiton of Distructor of class DE_QueueUsingDoublylinkedlist.
DE_QueueUsingDoublyLinkedList::~DE_QueueUsingDoublyLinkedList(){
    while(front){
        deleteAtFront();
    }
}

int main(){
    cout<<"DE_Queue Using Doubly Linked list Data Structure in C++ programming\n"<<endl;

    int choice= 0, element;
    DE_QueueUsingDoublyLinkedList dE_QUDLL;

    while(1){
        
        cout<<"_____________________________________________________________"<<endl;
        cout<<"|                                                           |"<<endl;
        cout<<"|          **** Please Select Your Operation. ****          |"<<endl;
        cout<<"|-----------------------------------------------------------|"<<endl;
        cout<<"|                                                           |"<<endl;
        cout<<"|       1-> Insert elements at the Front of DE_Queue.       |"<<endl;
        cout<<"|       2-> Insert elements at the Rear of DE_Queue.        |"<<endl;
        cout<<"|       3-> Delete element at the Front of DE_Queue.        |"<<endl;
        cout<<"|       4-> Delete element at the Rear of DE_Queue.         |"<<endl;
        cout<<"|       5-> Get Front element of the DE_Queue.              |"<<endl;
        cout<<"|       6-> Get Rear element of the DE_Queue.               |"<<endl;
        cout<<"|       7-> Check DE_Queue is Empty or Not.                 |"<<endl;
        cout<<"|       8-> Reversing the List elements of DE_Queue.        |"<<endl;
        cout<<"|       9-> Total count of nodes in the DE_Queue.           |"<<endl;
        cout<<"|       10-> Display DE_Queue elements.                     |"<<endl;
        cout<<"|       11-> Exit.                                          |"<<endl;
        cout<<"|                                                           |"<<endl;
        cout<<"*************************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                dE_QUDLL.insertAtFront(element);
                cout<<endl;
                break;
            }
            case 2: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                dE_QUDLL.insertAtRear(element);
                cout<<endl;
                break;
            }
            case 3: {
                system("cls");
                dE_QUDLL.deleteAtFront();
                cout<<endl;
                break;
            }
            case 4: {
                system("cls");
                dE_QUDLL.deleteAtRear();
                break;
            }
            case 5: {
                int temp= dE_QUDLL.getFront();
                system("cls");
                if(temp != -1){
                    cout<<endl<<temp<<" : is Present at the Front of DE_Queue."<<endl;
                }else{
                    cout<<endl<<"There is no element at the Front of DE_Queue."<<endl;
                }
                cout<<endl;
                break;
            }
            case 6: {
                int temp= dE_QUDLL.getRear();
                system("cls");
                if(temp != -1){
                    cout<<endl<<temp<<" : is Present at the Rear of DE_Queue."<<endl;
                }else{
                    cout<<endl<<"There is no element at the Rear of DE_Queue."<<endl;
                }
                cout<<endl;
                break;
            }
            case 7: {
                system("cls");
                if(dE_QUDLL.isEmpty()){
                    cout<<endl<<"Queue is Empty."<<endl;
                }else{
                    cout<<endl<<"Queue is not Empty."<<endl;
                }
                cout<<endl;
                break;
            }
            case 8: {
                dE_QUDLL.reverse();
                system("cls");
                //cout<<"DE_Queue has been reversed successfully."<<endl;
                cout<<endl<<"It's not working still now."<<endl;
                dE_QUDLL.displayDE_Queue();
                cout<<endl;
                break;
            }
            case 9: {
                int totalNode= 0;
                totalNode= dE_QUDLL.length();
                system("cls");
                cout<<endl<<"The total node is : "<<totalNode<<endl<<endl;
                break;
            }
            case 10: {
                system("cls");
                dE_QUDLL.displayDE_Queue();
                cout<<endl;
                break;
            }
            case 11: {
                exit(1);
                break;
            }
            default :{
                system("cls");
                cout<<endl<<"Invalid choice! Please choice a valid option."<<endl<<endl;
                break;
            }
        }
    }    
    
    //getch();
    return(0);
}