//Code a program to implement Singly Linked List Data Structure in C++ programming with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

// It's my Structure.
struct node{
    int item;
    node *next;
};

// It's my Singly Linked List Class.
class SLL{
    node *start;

    public:
    SLL(); //This is the default constructor of this class.
    void insertAtStart(int); //This function is used to insert element at the start of the linked list.
    void insertAtLast(int); //This function is used to insert element at the last of the linked list.
    void insertAtAfter(node *, int); //This function is used to insert element at the specified path into the linked list.
    node * search(int); //This function is used to search the element from the linked list.
    void deleteAtStart(); //This function is used to delete element from first of the linked list.
    void deleteAtLast(); //This function is used to delete element from last of the linked list.
    void deleteSpecifiedNode(int); //This function is used to delete specified node form the linked list.
    void reverse(); //This funciton is used to reverse element of Linked list.
    int countNode(); //This function is used to count Nodes of linked list.
    void display(); //This function is used to display the whole data of the linked list.
    ~SLL(); //This is the destructor of this class.
};

//Definition of all the functions is here.

//Definiton of default constructor of class SLL.
SLL::SLL(){
    start= NULL;
}

//Definition of insertAtStart function of Singly lisked list.
void SLL::insertAtStart(int data){
    node *n= new node;
    n->item= data;
    n->next= start;
    start= n;
}

//Definition of insertAtLast function of Singly Linked list.
void SLL::insertAtLast(int data){
    node *n= new node;
    n->item= data;
    n->next= NULL;

    if(start == NULL){
        start= n;
    }else{
        node *temp;
        temp= start;
        while(temp->next != NULL){
            temp= temp->next;
        }
        temp->next= n;
    }
}

//Definition of insertAtAfter function of Singly linked list.
void SLL::insertAtAfter(node *temp, int data){
    node *n;
    if(temp != NULL){
        n= new node;
        n->item= data;
        n->next= temp->next;
        temp->next= n;
    }/*else{
        cout<<"Your node is empty."<<endl;
    }*/
}

//Definition of search function of Singly linked list.
node * SLL::search(int data){
    node *temp;
    temp= start;
    while(temp != NULL){
        if(temp->item == data){
            return temp;
        }
        temp= temp->next;
    }
    return NULL;
}

//Definition of deleteAtStart function of Singly linked list.
void SLL::deleteAtStart(){
    node *temp;
    if(start){
        temp= start;
        start= start->next;
        delete temp;
    }
}

//Definition of deleteAtLast function of Singly linked list.
void SLL::deleteAtLast(){
    node *temp;
    if(start){
        temp= start;
        if(temp->next == NULL){
            delete temp;
            start= NULL;
        }else{
            while(temp->next->next != NULL){
                temp= temp->next;
            }
            delete temp->next;
            temp->next= NULL;
        }
    }
}

//Definition of deleteSepcifiedNode function of Singly linked list.
void SLL::deleteSpecifiedNode(int data){
    node *temp;
    bool checkElement= true;
    if (start){
        temp = start;
        if (temp->item == data){
            start = start->next;
            delete temp;
        }else{
            while (temp->next != NULL){
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
        cout<<"Your Singly linked list is already empty"<<endl;
    }

    if(checkElement){
        cout<<data<<" : is not present in the linked list."<<endl;
    }else{
        cout<<data<<" : has been deleted successfully."<<endl;
    }
}

//Definiton of reverse function of Singly linked list.
void SLL::reverse(){
    node *tempNode;
    tempNode= start;
    node *previousPtr= NULL;
    node *currentPtr= tempNode;
    node *nextPtr;

    while(currentPtr != NULL){
        nextPtr= currentPtr->next;
        currentPtr->next = previousPtr;
        
        previousPtr= currentPtr;
        currentPtr= nextPtr;
    }
    start= previousPtr;
}

//Definition of countNode function of Singly linked list.
int SLL::countNode(){
    int count= 0;
    node *temp;
    temp= start;
    if(temp == NULL){
        return 0;
    }else{
        while(temp->next != NULL){
            temp= temp->next;
            count++;
        }
        return count+ 1;
    }
    cout<<endl;
}

//Definition of display linked list elemnts function.
void SLL::display(){
    node* d= new node;
    d= start;
    cout<<endl;
    while(d != NULL){
        cout<<"["<<d->item<<"]->";
        d= d->next;
    }
    cout<<"[NULL]"<<endl;
}

//Definition of destructor of the Singly linked list.
SLL::~SLL(){
    while(start){
        deleteAtStart();
    }
}

//Main function code is here.
int main(){
    cout<<"Singly Linked List in C++ programming\n"<<endl;

    int choice, element;
    SLL sll;
    node *t;
    t= NULL;

    while(1){

        cout<<"________________________________________________________________________________________"<<endl;
        cout<<"|\t                                                                               |"<<endl;
        cout<<"|\t                 **** Please Select Your Operation. ****                       |"<<endl;
        cout<<"|--------------------------------------------------------------------------------------|"<<endl;
        cout<<"|\t                                                                               |"<<endl;
        cout<<"|\t1-> Insert elements at the Start Singly Linked List.                           |"<<endl;
        cout<<"|\t2-> Insert elements at the Last Singly Linked List.                            |"<<endl;
        cout<<"|\t3-> Insert elements at the Specified Position of the Singly Linked List.       |"<<endl;
        cout<<"|\t4-> Searching elements in the Singly Linked List.                              |"<<endl;
        cout<<"|\t5-> Delete element at the start of the Singly Linked List.                     |"<<endl;
        cout<<"|\t6-> Delete element at the last of the Singly Linked List.                      |"<<endl;
        cout<<"|\t7-> Delete element at the specified position of the Singly Linked List.        |"<<endl;
        cout<<"|\t8-> Reversing the List elements of the Singly Linked list.                     |"<<endl;
        cout<<"|\t9-> Total count of nodes in the Singly linked list.                            |"<<endl;
        cout<<"|\t10-> Display Singly Linked List elements.                                      |"<<endl;
        cout<<"|\t11-> Exit.                                                                     |"<<endl;
        cout<<"|\t                                                                               |"<<endl;
        cout<<"****************************************************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                sll.insertAtStart(element);
                system("cls");
                cout<<element<<" : is inserted successfully at the start of linked list."<<endl;
                cout<<endl;
                break;
            }
            case 2: {
                cout<<"Enter element here : ";
                cin>>element;
                sll.insertAtLast(element);
                system("cls");
                cout<<element<<" : is inserted successfully at the Last of linked list."<<endl;
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
                    sll.insertAtAfter(t, element);
                    system("cls");
                    cout<<element<<" : is inserted successfully at after : "<<t->item<<endl;
                }
                cout<<endl;
                break;
            }
            case 4: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                if(t= sll.search(element)){
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
                sll.deleteAtStart();
                system("cls");
                cout<<"Element is deleted at start of this Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 6: {
                sll.deleteAtLast();
                system("cls");
                cout<<"Element is deleted at Last of this Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 7: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                sll.deleteSpecifiedNode(element);
                //cout<<"Element is deleted at spcified position of this Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 8: {
                sll.reverse();
                system("cls");
                cout<<"Linked list has been reversed successfully."<<endl;
                sll.display();
                cout<<endl;
                break;
            }
            case 9: {
                int totalNode= 0;
                totalNode= sll.countNode();
                system("cls");
                cout<<"The total node is : "<<totalNode<<endl<<endl;
                break;
            }
            case 10: {
                system("cls");
                sll.display();
                cout<<endl;
                break;
            }
            case 11: {
                exit(1);
                break;
            }
            default :{
                cout<<"Invalid choice! Please choice a valid option."<<endl;
                break;
            }
        }

        //This condition is used to Clear screen at the specific conditions.
        if(choice == 9 || choice == 10 || choice == 8 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7){
            //Do nothing.
        }else{
            system("cls");
        }

    }
    
    //getch();
    return(0);
}