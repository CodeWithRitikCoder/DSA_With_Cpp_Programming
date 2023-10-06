//Write a program to Implement Data Structure with Doubly Linked list in C++ programming with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//My Node Structure is here.
struct node{
    node* previousNode;
    int item;
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
    int countNode();
    void display(); //This function is used to display the whole data of the Doubly linked list.
    ~DoublyLinkedList(); //This is the destructor of this class.
};

//Definition of all the function is here.

//Definiton of default constructor of class DoublyLinkedList.
DoublyLinkedList::DoublyLinkedList(){
    start= NULL;
}

//Definition of insertAtStart function of class DoublyLinkedList.
void DoublyLinkedList::insertAtStart(int data){

}

//Definition of insertAtLast function of class DoublyLinkedList.
void DoublyLinkedList::insertAtLast(int data){

}

//Definition of insertAtAfter function of class DoublyLinkedList.
void DoublyLinkedList::insertAtAfter(node* temp, int data){

}

//Definition of search function of class DoublyLinkedList.
node* DoublyLinkedList::search(int data){

}

//Definition of deleteAtStart function of class DoublyLinkedList.
void DoublyLinkedList::deleteAtStart(){

}

//Definition of deleteAtLast function of class DoublyLinkedList.
void DoublyLinkedList::deleteAtLast(){

}

//Definition of deleteSpecifiedNode function of class DoublyLinkedList.
void DoublyLinkedList::deleteSpecifiedNode(int data){

}

//Definition of reverse function of class DoublyLinkedList.
void DoublyLinkedList::reverse(){

}

//Definition of countNode function of class DoublyLinkedList.
int DoublyLinkedList::countNode(){

}

//Definition of display function of class DoublyLinkedList.
void DoublyLinkedList::display(){
    
}

//Definiton of Distructor of class DoublyLinkedList.
DoublyLinkedList::~DoublyLinkedList(){
    while(start){
        deleteAtStart();
    }
}

int main(){
    cout<<"Doubly Linked list Data Structure in C++ programming\n"<<endl;
    
    
    //getch();
    return(0);
}