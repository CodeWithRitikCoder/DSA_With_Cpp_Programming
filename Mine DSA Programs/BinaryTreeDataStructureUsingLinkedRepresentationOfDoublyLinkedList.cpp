//Write a program to Implement Data Structure with Doubly Linked list in C++ programming with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//My Node Structure is here.
struct node{
    int data;
    node *left;
    node *right;

    //It's a constructor of this node Structure.
    node(int value){
        data= value;
        left= NULL;
        right= NULL;
    }
};

//My Doubly linked List class is here.
class BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList{
    private:
    node* root;

    public:
    //All functions declarations are here.
    BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList(); // This is the default donstructor of this class.
    void insertElement(int);
    void display(); //This function is used to display the whole data of BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList.
    ~BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList(); //This is the destructor of this class.
};

//Definition of all the function is here.

//Definiton of default constructor of class DoublyLinkedList.
BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList::BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList(){
    root= NULL;
}

//Definition of insertAtStart function of class DoublyLinkedList.
void BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList::insertElement(int value){
    node *n= new node(10);
    
}

//Definition of display function of class DoublyLinkedList.
void BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList::display(){
    node *temp= root;
    cout<<"              ("<<temp->data<<") "<<endl;
    cout<<"              /    \\"<<endl;
    cout<<"           ("<<temp->left->data<<")      ("<<temp->right->data<<")"<<endl;
}

//Definiton of Distructor of class DoublyLinkedList.
BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList::~BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList(){
    
}

int main(){
    cout<<"Binary Tree Data Structure Using Linked Representation Of Doubly Linked List in C++ programming\n"<<endl;

    int choice= 0, element;
    BinaryTreeUsingLinkedRepresentationOfDoublyLinkedList bTULRODLL;

    /*while(1){
        
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
    }*/

    node *root= new node(10);
    root->left= new node(20);
    root->right= new node(30);
    //bTULRODLL.display();
    node *temp= root;
    cout<<"              ("<<temp->data<<") "<<endl;
    cout<<"             /    \\"<<endl;
    cout<<"         ("<<temp->left->data<<")      ("<<temp->right->data<<")"<<endl<<endl;


    
    //getch();
    return(0);
}