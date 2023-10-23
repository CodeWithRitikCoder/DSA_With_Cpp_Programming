//Write a program to Implement Data Structure with Doubly Linked list in C++ programming with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//My Node Structure is here.
struct node{
    node* previousNode;
    int data;
    node* nextNode;
};

//My Doubly linked List class is here.
class DoublyLinkedList{
    private:
    node* start;

    public:
    //All functions declarations are here.
    DoublyLinkedList(); // This is the default donstructor of this class.
    void insertAtStart(int); //This function is used to insert element at the start of the Doubly linked list.
    void insertAtLast(int); //This function is used to insert element at the last of the Doubly linked list.
    void insertAtAfter(node *, int); //This function is used to insert elemtn at the specified path into the Doubly linked list.
    node * search(int); //This function is used to search the element from the Doubly linked list.
    void deleteAtStart(); //This function is used to delete element from first of the Doubly linked list.
    void deleteAtLast(); //This function is used to delete element from last of the Doubly linked list.
    void deleteSpecifiedNode(int); //This function is used to delete specified node form the Doubly linked list.
    void reverse(); //This funciton is used to reverse element of Doubly Linked list.
    int length(); //This function is used to get the length of the Doubly Linked list.
    void display(); //This function is used to display the whole data of the Doubly linked list.
    ~DoublyLinkedList(); //This is the destructor of this class.
};

//Definition of all the function is here.

//Definiton of default constructor of class DoublyLinkedList.
DoublyLinkedList::DoublyLinkedList(){
    start= NULL;
}

//Definition of insertAtStart function of class DoublyLinkedList.
void DoublyLinkedList::insertAtStart(int value){
    node *n;
    n= new node;
    n->previousNode= NULL;
    n->data= value;
    n->nextNode= start;
    if(start){
        start->previousNode= n;
    }
    start= n;
}

//Definition of insertAtLast function of class DoublyLinkedList.
void DoublyLinkedList::insertAtLast(int value){
    if(start == NULL){
       insertAtStart(value);
       return;
    }else{
        node *n= new node;
        n->previousNode= start;
        n->data= value;
        n->nextNode= NULL;

        node *temp= start;
        while(temp->nextNode != NULL){
            temp= temp->nextNode;
        }
        temp->nextNode= n;
    }
}

//Definition of insertAtAfter function of class DoublyLinkedList.
void DoublyLinkedList::insertAtAfter(node* temp, int value){
    node *n;
    if(temp){
        n= new node;
        n->data= value;
        n->nextNode= temp->nextNode;
        n->previousNode= temp->previousNode;
        temp->nextNode= n;
    }else{
        cout<<endl<<"Doubly Linked list is Empty."<<endl;
    }

}

//Definition of search function of class DoublyLinkedList.
node* DoublyLinkedList::search(int value){
    node *temp= start;
    while(temp != NULL){
        if(temp->data == value){
            return temp;
            break;
        }
        temp= temp->nextNode;
    }
    return NULL;
}

//Definition of deleteAtStart function of class DoublyLinkedList.
void DoublyLinkedList::deleteAtStart(){
    node *tempToDelete;
    if(start){
        if(start->nextNode == NULL){
            delete start;
            start= NULL;
        }else{
            tempToDelete= start;
            start= start->nextNode;
            start->previousNode= NULL;
            delete tempToDelete;
        }
    }
}

//Definition of deleteAtLast function of class DoublyLinkedList.
void DoublyLinkedList::deleteAtLast(){
    node *tempToDelete;
    if(start){
        tempToDelete= start;
        if(tempToDelete->nextNode == NULL){
            delete tempToDelete;
            start= NULL;
        }else{
            while(tempToDelete->nextNode->nextNode != NULL){
                tempToDelete= tempToDelete->nextNode;
            }
            delete tempToDelete->nextNode;
            tempToDelete->nextNode= NULL;
        }
    }
}

//Definition of deleteSpecifiedNode function of class DoublyLinkedList.
void DoublyLinkedList::deleteSpecifiedNode(int value){
    // not working still now
    node *temp= start;

    // if(temp->data == value){
    //     deleteAtStart();
    //     return;
    // }
    // while(temp != NULL && temp->data != value){
    //     temp= temp->nextNode;
    // }
    // temp->previousNode->nextNode= temp->nextNode;
    // if(temp->nextNode != NULL){
    //     temp->nextNode->previousNode= temp->previousNode;
    // }
    // delete temp;

    // while(t)
    // {
    //     if(t->data == value)
    //     {
    //         if(t->nextNode != NULL){
    //             t->nextNode->previousNode= t->previousNode;
    //             }
    //         else if(t->previousNode != NULL){
    //             t->previousNode->nextNode= t->nextNode;
    //             }
    //         else if(t->previousNode == NULL){
    //             start= t->nextNode;
    //             }
    //         else if(t->nextNode == NULL){
    //             t->previousNode->nextNode= NULL;
    //             }
    //         delete t;
    //         break;
    //     }
    //     t=t->nextNode;
    // }

    while(temp){
        if(temp->data == value){
            if(temp->previousNode == NULL){
                deleteAtStart();
                break;
            }
            else if(temp->nextNode == NULL){
                deleteAtLast();
                break;
            }
            else if(temp->nextNode != NULL && temp->previousNode != NULL){
                temp->previousNode->nextNode= temp->nextNode;
                temp->nextNode->previousNode= temp->previousNode;
                break;
            }
        }
        temp= temp->nextNode;
    }
    delete temp;

}

//Definition of reverse function of class DoublyLinkedList.
void DoublyLinkedList::reverse(){
    node *tempNode;
    tempNode= start;
    node *previousPtr= NULL;
    node *currentPtr= tempNode;
    node *nextPtr;

    while(currentPtr != NULL){
        nextPtr= currentPtr->nextNode;
        currentPtr->nextNode = previousPtr;
        
        previousPtr= currentPtr;
        currentPtr= nextPtr;
    }
    start= previousPtr;

}

//Definition of countNode function of class DoublyLinkedList.
int DoublyLinkedList::length(){
    int count= 0;
    node *temp= start;
    while(temp){
        temp= temp->nextNode;
        count++;
    }
    return count;
}

//Definition of display function of class DoublyLinkedList.
void DoublyLinkedList::display(){
    node *temp= new node;
    temp= start;
    if(temp == NULL){
        cout<<endl<<"There is no node in the Doubly Linked list now."<<endl;
    }else{
        cout<<endl<<"NULL<-";
        while(temp != NULL){
            cout<<"P["<<temp->data<<"]N";
            if(temp->nextNode != NULL){
                cout<<"<=>";
            }
            temp= temp->nextNode;
        }
        cout<<"->NULL"<<endl;
    }
}

//Definiton of Distructor of class DoublyLinkedList.
DoublyLinkedList::~DoublyLinkedList(){
    while(start){
        deleteAtStart();
    }
}

int main(){
    cout<<"Doubly Linked list Data Structure in C++ programming\n"<<endl;

    int choice= 0, element;
    DoublyLinkedList dLL;
    node *t= NULL;

    while(1){
        
        cout<<"________________________________________________________________________________________"<<endl;
        cout<<"|\t                                                                               |"<<endl;
        cout<<"|\t                 **** Please Select Your Operation. ****                       |"<<endl;
        cout<<"|--------------------------------------------------------------------------------------|"<<endl;
        cout<<"|\t                                                                               |"<<endl;
        cout<<"|\t1-> Insert elements at the Start Doubly Linked List.                           |"<<endl;
        cout<<"|\t2-> Insert elements at the Last Doubly Linked List.                            |"<<endl;
        cout<<"|\t3-> Insert elements at the Specified Position of the Doubly Linked List.       |"<<endl;
        cout<<"|\t4-> Searching elements in the Doubly Linked List.                              |"<<endl;
        cout<<"|\t5-> Delete element at the start of the Doubly Linked List.                     |"<<endl;
        cout<<"|\t6-> Delete element at the last of the Doubly Linked List.                      |"<<endl;
        cout<<"|\t7-> Delete element at the specified position of the Doubly Linked List.        |"<<endl;
        cout<<"|\t8-> Reversing the List elements of the Doubly Linked list.                     |"<<endl;
        cout<<"|\t9-> Total count of nodes in the Doubly linked list.                            |"<<endl;
        cout<<"|\t10-> Display Doubly Linked List elements.                                      |"<<endl;
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
                dLL.insertAtStart(element);
                system("cls");
                cout<<endl<<element<<" : is inserted successfully at the start of Doubly linked list."<<endl;
                cout<<endl;
                break;
            }
            case 2: {
                cout<<"Enter element here : ";
                cin>>element;
                dLL.insertAtLast(element);
                system("cls");
                cout<<endl<<element<<" : is inserted successfully at the Last of Doubly linked list."<<endl;
                cout<<endl;
                break;
            }
            case 3: {
                if(t == NULL){
                    system("cls");
                    cout<<endl<<"Firstly you will have to Run search function."<<endl<<endl;
                    break;
                }
                cout<<"Enter element here : ";
                cin>>element;
                dLL.insertAtAfter(t, element);
                system("cls");
                cout<<endl<<element<<" : is inserted successfully at after : "<<t->data<<endl;
                cout<<endl;
                break;
            }
            case 4: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                if(t= dLL.search(element)){
                    cout<<endl<<element<<" : is present in the Doubly linked list."<<endl;
                }else{
                    cout<<endl<<element<<" : is not present in the Doubly linked list."<<endl;
                }
                cout<<endl;
                break;
            }
            case 5: {
                dLL.deleteAtStart();
                system("cls");
                cout<<endl<<"Element is deleted at the start of this Doubly Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 6: {
                dLL.deleteAtLast();
                system("cls");
                cout<<endl<<"Element is deleted at the Last of this Doubly Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 7: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                dLL.deleteSpecifiedNode(element);
                cout<<endl<<element<<" : is deleted at spcified position of this Doubly Linked list."<<endl;
                cout<<endl;
                break;
            }
            case 8: {
                dLL.reverse();
                system("cls");
                cout<<"Linked list has been reversed successfully."<<endl;
                dLL.display();
                cout<<endl;
                break;
            }
            case 9: {
                int totalNode= 0;
                totalNode= dLL.length();
                system("cls");
                cout<<endl<<"The total node is : "<<totalNode<<endl<<endl;
                break;
            }
            case 10: {
                system("cls");
                dLL.display();
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

        //This condition is used to Clear screen at the specific conditions.
        // if(choice == 9 || choice == 10 || choice == 8 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7){
        //     //Do nothing.
        // }else{
        //     system("cls");
        // }

    }    
    
    //getch();
    return(0);
}