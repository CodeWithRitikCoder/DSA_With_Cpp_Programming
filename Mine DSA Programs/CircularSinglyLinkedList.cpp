//Write a program to implement Circular singly Linked List Data Structure in C++ programming with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

// It's my Structure.
struct node{
    int item;
    node *next;
};

// It's my Singly Linked List Class.
class CircularSinglyLinkedList{
    node *start;

    public:
    CircularSinglyLinkedList(); //This is the default constructor of this class.
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
    ~CircularSinglyLinkedList(); //This is the destructor of this class.
};

//Definition of all the function is here.

//Definiton of default constructor of class SLL.
CircularSinglyLinkedList::CircularSinglyLinkedList(){
    start= NULL;
}

//Definition of insertAtStart function of lisked list.
void CircularSinglyLinkedList::insertAtStart(int data){
    node *n= new node;
    n->item= data;
    n->next= start;
    if(start == NULL){
        n->next= n;
        start= n;
        return;
    }

    node *temp= start;
    while(temp->next != start){
        temp= temp->next;
    }
    temp->next= n;
    start= n;
}

//Definition of insertAtLast function of Linked list.
void CircularSinglyLinkedList::insertAtLast(int data){
    if(start == NULL){
        insertAtStart(data);
        return;
    }
    node *n= new node;
    n->item= data;
    n->next= start;

    node *temp= start;
    while(temp->next != start){
        temp= temp->next;
    }
    temp->next= n;
}

//Definition of insertAtAfter function of linked list.
void CircularSinglyLinkedList::insertAtAfter(node *temp, int data){
    node *n;
    if(temp != NULL){
        n= new node;
        n->item= data;
        n->next= temp->next;
        temp->next= n;
    }
}

//Definition of search function of linked list.
node * CircularSinglyLinkedList::search(int data){
    node *temp;
    temp= start;
    do{
        if(temp->item == data){
            return temp;
        }
        temp= temp->next;
    }while(temp != start);
    return NULL;
}

//Definition of deleteAtStart function of linked list.
void CircularSinglyLinkedList::deleteAtStart(){
    node *temp;
    if(start){
        temp= start;
        if(temp->next == start){
            start= NULL;
            return;
        }
        while(temp->next != start){
            temp= temp->next;
        }
        node *toDelete= start;
        temp->next= start->next;
        start= start->next;
        delete toDelete, temp;
    }
}

//Definition of deleteAtLast function of linked list.
void CircularSinglyLinkedList::deleteAtLast(){
    node *temp;
    if(start){
        temp= start;
        if(temp->next == start){
            deleteAtStart();
        }else{
            while(temp->next->next != start){
                temp= temp->next;
            }
            node *toDelete= temp->next;
            temp->next= temp->next->next;
            delete toDelete, temp;
        }
    }
}

//Definition of deleteSepcifiedNode function of linked list.
void CircularSinglyLinkedList::deleteSpecifiedNode(int data){
    node *temp;
    bool checkElement= true;
    if (start){
        temp = start;
        if (temp->item == data){
            deleteAtStart();
            checkElement= false;
        }
        else{
            while (temp->next != start){
                if (temp->next->item == data){
                    node *toDelete = temp->next;
                    temp->next = temp->next->next;

                    delete toDelete;
                    checkElement = false;
                    break;
                }else{
                    checkElement = true;
                }
                temp = temp->next;
            }
        }
    }else{
        cout<<"Your linked list is already empty"<<endl;
    }

    if(checkElement){
        cout<<data<<" : is not present in the linked list."<<endl;
    }else{
        cout<<data<<" : has been deleted successfully."<<endl;
    }
}

//Definiton of reverse function of linked list.
void CircularSinglyLinkedList::reverse(){
    // node *tempNode= start;
    // node *previousPtr= start;
    // node *currentPtr= tempNode;
    // node *nextPtr;

    // do{
    //     nextPtr= currentPtr->next;
    //     currentPtr->next = previousPtr;
        
    //     previousPtr= currentPtr;
    //     currentPtr= nextPtr;
    // }while(currentPtr != start);
    // start= previousPtr;
}

//Definition of countNode function of linked list.
int CircularSinglyLinkedList::length(){
    int count= 0;
    node *temp= start;
    do{
        temp= temp->next;
        count++;
    }while(temp != start);
    return count;
}

//Definition of display linked list elemnts function.
void CircularSinglyLinkedList::display(){
    node* d= start;
    cout<<endl;
    if(start){
        do{
            cout<<"["<<d->item<<"]->";
            d= d->next;
        }while(d != start);
        cout<<"[First Node]"<<endl;
    }else{
        cout<<"There is no element in the Circular Linked List."<<endl;
    }
    
}

//Definition of destructor of the linked list.
CircularSinglyLinkedList::~CircularSinglyLinkedList(){
    deleteAtStart();
}

//Main function code is here.
int main(){
    cout<<"Circular Singly Linked List in C++ programming\n"<<endl;

    int choice, element;
    CircularSinglyLinkedList cSLL;
    node *t;
    t= NULL;

    while(1){

        cout<<"___________________________________________________________________________________________"<<endl;
        cout<<"|\t                                                                                  |"<<endl;
        cout<<"|\t            **** Please Select Your Operation. ****                               |"<<endl;
        cout<<"|-----------------------------------------------------------------------------------------|"<<endl;
        cout<<"|\t                                                                                  |"<<endl;
        cout<<"|\t1-> Insert elements at the Start Circular Singly Linked List.                     |"<<endl;
        cout<<"|\t2-> Insert elements at the Last Circular Singly Linked List.                      |"<<endl;
        cout<<"|\t3-> Insert elements at the Specified Position of the Circular Linked List.        |"<<endl;
        cout<<"|\t4-> Searching elements in the Circular Singly Linked List.                        |"<<endl;
        cout<<"|\t5-> Delete element at the start of the Circular Singly Linked List.               |"<<endl;
        cout<<"|\t6-> Delete element at the last of the Circular Singly Linked List.                |"<<endl;
        cout<<"|\t7-> Delete element at the specified position of the Circular Singly Linked List.  |"<<endl;
        cout<<"|\t8-> Reversing the List elements of the Circular Singly Linked list.               |"<<endl;
        cout<<"|\t9-> Total count of nodes in the Circular Singly linked list.                      |"<<endl;
        cout<<"|\t10-> Display Circular Singly Linked List elements.                                |"<<endl;
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
                cout<<endl<<element<<" : is inserted successfully at the start of linked list."<<endl;
                cout<<endl;
                break;
            }
            case 2: {
                cout<<"Enter element here : ";
                cin>>element;
                cSLL.insertAtLast(element);
                system("cls");
                cout<<endl<<element<<" : is inserted successfully at the Last of linked list."<<endl;
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
                    cout<<endl<<element<<" : is inserted successfully at after : "<<t->item<<endl;
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
                    cout<<"Its present in the linked list."<<endl;
                }else{
                    cout<<endl;
                    cout<<"Its not present in the linked list."<<endl;
                }
                cout<<endl;
                break;
            }
            case 5: {
                cSLL.deleteAtStart();
                system("cls");
                cout<<"Element is deleted at start of this Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 6: {
                cSLL.deleteAtLast();
                system("cls");
                cout<<"Element is deleted at Last of this Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 7: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                cSLL.deleteSpecifiedNode(element);
                //cout<<"Element is deleted at spcified position of this Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 8: {
                cSLL.reverse();
                system("cls");
                cout<<"Reverse Fnction is about to come."<<endl;
                //cout<<"Linked list has not been reversed successfully."<<endl;
                //cSLL.display();
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
                cout<<endl<<"Invalid choice! Please choice a valid option."<<endl;
                break;
            }
        }
    }
    
    //getch();
    return(0);
}