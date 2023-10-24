//Write a program to implement Circular Doubly Linked List Data Structure in C++ programming with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

// It's my Structure.
struct node{
    node *previousNode;
    int data;
    node *nextNode;
};

// It's my Singly Linked List Class.
class CircularDoublyLinkedList{
    node *start;

    public:
    CircularDoublyLinkedList(); //This is the default constructor of this class.
    void insertAtStart(int); //This function is used to insert element at the start of the linked list.
    void insertAtLast(int); //This function is used to insert element at the last of the linked list.
    void insertAtAfter(node *, int); //This function is used to insert elemtn at the specified path into the linked list.
    node * search(int); //This function is used to search the element from the linked list.
    void deleteAtStart(); //This function is used to delete element from first of the linked list.
    void deleteAtLast(); //This function is used to delete element from last of the linked list.
    void deleteSpecifiedNode(int); //This function is used to delete specified node form the linked list.
    void reverse(); //This funciton is used to reverse element of Linked list.
    int length();
    void display(); //This function is used to display the whole data of the linked list.
    ~CircularDoublyLinkedList(); //This is the destructor of this class.
};

//Definition of all the function is here.

//Definiton of default constructor of class SLL.
CircularDoublyLinkedList::CircularDoublyLinkedList(){
    start= NULL;
}

//Definition of insertAtStart function of lisked list.
void CircularDoublyLinkedList::insertAtStart(int value){
    node *n= new node;
    n->data= value;
    if(start == NULL){
        n->previousNode= n;
        n->nextNode= n;
        start= n;
    }else{
        n->previousNode= start->previousNode;
        n->nextNode= start;
        start->previousNode->nextNode= n;
        start->previousNode= n;
        start= n;
    }
}

//Definition of insertAtLast function of Linked list.
void CircularDoublyLinkedList::insertAtLast(int value){
    if(start == NULL){
        insertAtStart(value);
    }else{
        node *n= new node;
        n->data= value;

        //**First way to add node at the end of the Circular Doubly linked list.
        // n->previousNode= start;
        // n->nextNode= start;

        // node *temp= start;
        // while(temp->nextNode != start){
        //     temp= temp->nextNode;
        // }
        // n->previousNode= temp;
        // temp->nextNode= n;

        //**Second way to add node at the end of the Circular Doubly linked list.
        n->previousNode= start->previousNode;
        n->nextNode= start;
        start->previousNode->nextNode= n;
        start->previousNode= n;

    }
}

//Definition of insertAtAfter function of linked list.
void CircularDoublyLinkedList::insertAtAfter(node *temp, int data){
    if(temp){
        node *n= new node;
        n->data= data;
        n->previousNode= temp;
        n->nextNode= temp->nextNode;
        temp->nextNode->previousNode= n;
        temp->nextNode= n;
    }
}

//Definition of search function of linked list.
node * CircularDoublyLinkedList::search(int value){
    node *temp;
    if(start){
        temp= start;
        do{
            if(temp->data == value){
                return temp;
            }
            temp= temp->nextNode;
        }while(temp != start);
    }
    return NULL;
}

//Definition of deleteAtStart function of linked list.
void CircularDoublyLinkedList::deleteAtStart(){
    if(start){
        if(start->nextNode == start){
            delete start;
            start= NULL;
        }else{
            node *temp= start;
            start->previousNode->nextNode= start->nextNode;
            start->nextNode->previousNode= start->previousNode;
            start= start->nextNode;
            delete temp;
        }
    }
}

//Definition of deleteAtLast function of linked list.
void CircularDoublyLinkedList::deleteAtLast(){
    if(start){
        if(start->nextNode == start){
            delete start;
            start= NULL;
        }else{
            node *temp= start;
            temp= start->previousNode;
            temp->previousNode->nextNode= start;
            start->previousNode= temp->previousNode;
            delete temp;
        }
    }
}

//Definition of deleteSepcifiedNode function of linked list.
void CircularDoublyLinkedList::deleteSpecifiedNode(int value){
    int checkDelectionCondition= 0;

    if(start){
        if(start->data == value){
            deleteAtStart();
            checkDelectionCondition= 1;
        }else{
            node *temp= start;
            temp= start->nextNode;

            while(temp != start){
                if(temp->data == value){
                    temp->nextNode->previousNode= temp->previousNode;
                    temp->previousNode->nextNode= temp->nextNode;
                    checkDelectionCondition= 1;
                    delete temp;
                    break;
                }
                temp= temp->nextNode;
            }
        }
    }else{
        checkDelectionCondition= 2;
    }

    switch (checkDelectionCondition){
        case 1:{
            cout<<endl<<value<<" : has been deleted successfully."<<endl;
            break;
        }
        case 2:{
            cout<<endl<<"Your linked list is already empty"<<endl;
            break;
        }
        default:{
            cout<<endl<<value<<" : is not present in the linked list."<<endl;
            break;
        }
    }
}

//Definiton of reverse function of linked list.
void CircularDoublyLinkedList::reverse(){
    // Not working still now.
    
}

//Definition of countNode function of linked list.
int CircularDoublyLinkedList::length(){
    int count= 0;
    node *temp= start;
    do{
        temp= temp->nextNode;
        count++;
    }while(temp != start);
    return count;
}

//Definition of display linked list elemnts function.
void CircularDoublyLinkedList::display(){
    node* d= start;
    if(start){
        cout<<endl<<"[Last Node]<-";
        do{
            cout<<"P["<<d->data<<"]N->";
            d= d->nextNode;
        }while(d != start);
        cout<<"[First Node]"<<endl;
    }else{
        cout<<endl<<"There is no element in the Circular Linked List."<<endl;
    }
    
}

//Definition of destructor of the linked list.
CircularDoublyLinkedList::~CircularDoublyLinkedList(){
    while(start){
        deleteAtStart();
    }
}

//Main function code is here.
int main(){
    cout<<"Circular Doubly Linked List in C++ programming\n"<<endl;

    int choice, element;
    CircularDoublyLinkedList cSLL;
    node *t;
    t= NULL;

    while(1){

        cout<<"___________________________________________________________________________________________"<<endl;
        cout<<"|\t                                                                                  |"<<endl;
        cout<<"|\t            **** Please Select Your Operation. ****                               |"<<endl;
        cout<<"|-----------------------------------------------------------------------------------------|"<<endl;
        cout<<"|\t                                                                                  |"<<endl;
        cout<<"|\t1-> Insert elements at the Start Circular Doubly Linked List.                     |"<<endl;
        cout<<"|\t2-> Insert elements at the Last Circular Doubly Linked List.                      |"<<endl;
        cout<<"|\t3-> Insert elements at the Specified Position of the Circular Doubly List.        |"<<endl;
        cout<<"|\t4-> Searching elements in the Circular Singly Doubly List.                        |"<<endl;
        cout<<"|\t5-> Delete element at the start of the Circular Doubly Linked List.               |"<<endl;
        cout<<"|\t6-> Delete element at the last of the Circular Doubly Linked List.                |"<<endl;
        cout<<"|\t7-> Delete element at the specified position of the Circular Doubly Linked List.  |"<<endl;
        cout<<"|\t8-> Reversing the List elements of the Circular Doubly Linked list.               |"<<endl;
        cout<<"|\t9-> Total count of nodes in the Circular Doubly linked list.                      |"<<endl;
        cout<<"|\t10-> Display Circular Doubly Linked List elements.                                |"<<endl;
        cout<<"|\t11-> Exit.                                                                        |"<<endl;
        cout<<"|\t                                                                                  |"<<endl;
        cout<<"*******************************************************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                cSLL.insertAtStart(element);
                system("cls");
                cout<<endl<<element<<" : is inserted successfully at the start of Circular Doubly linked list."<<endl;
                cout<<endl;
                break;
            }
            case 2: {
                cout<<"Enter element here : ";
                cin>>element;
                cSLL.insertAtLast(element);
                system("cls");
                cout<<endl<<element<<" : is inserted successfully at the Last of Circular Doubly linked list."<<endl;
                cout<<endl;
                break;
            }
            case 3: {
                if(t == NULL){
                    system("cls");
                    cout<<endl<<"Unable to insert data at specified position! Use search at least once before Run this Utility."<<endl;
                }else{
                    cout<<"Enter element here : ";
                    cin>>element;
                    cSLL.insertAtAfter(t, element);
                    system("cls");
                    cout<<endl<<element<<" : is inserted successfully at after : "<<t->data<<endl;
                }
                cout<<endl;
                break;
            }
            case 4: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                if(t= cSLL.search(element)){
                    cout<<endl;
                    cout<<element<<" : is present in the Circular Doubly linked list."<<endl;
                }else{
                    cout<<endl;
                    cout<<element<<" : is not present in the Circular Doubly linked list."<<endl;
                }
                cout<<endl;
                break;
            }
            case 5: {
                cSLL.deleteAtStart();
                system("cls");
                cout<<endl<<"Element is deleted at start of this Circular Doubly Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 6: {
                cSLL.deleteAtLast();
                system("cls");
                cout<<endl<<"Element is deleted at Last of this Circular Doubly Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 7: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                cSLL.deleteSpecifiedNode(element);
                // cout<<endl<<element<<" : is deleted at spcified position of this Circular Doubly Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 8: {
                cSLL.reverse();
                system("cls");
                cout<<"Linked list has not been reversed successfully."<<endl;
                cSLL.display();
                cout<<endl;
                break;
            }
            case 9: {
                int totalNode= 0;
                totalNode= cSLL.length();
                system("cls");
                cout<<endl<<"The total node is : "<<totalNode<<endl<<endl;
                break;
            }
            case 10: {
                system("cls");
                cSLL.display();
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