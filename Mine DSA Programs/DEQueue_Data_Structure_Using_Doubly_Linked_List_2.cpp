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
    void insertData(char, int); //This function is used to insert element at the Front of the DE_QueueUsingDoublylinkedlist.
    void deleteData(char); //This function is used to delete element from first of the DE_QueueUsingDoublylinkedlist.
    int getData(char); //This function is used to get Front element of the DE_QueueUsingDoublylinkedlist.
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
void DE_QueueUsingDoublyLinkedList::insertData(char position, int value){
    if(position == 'f' || position == 'F'){
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
    }else if(position == 'r' || position == 'R'){
        if(front == NULL){
            insertData('f', value);
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
}

//Definition of deleteAtStart function of class DE_QueueUsingDoublylinkedlist.
void DE_QueueUsingDoublyLinkedList::deleteData(char position){
    node *tempToDelete;
    if(front){
        if(front == rear){
            cout<<endl<<front->data<<" : is Deleted successfully at the Front of DE_Queue."<<endl;
            front= rear= NULL;
        }else{
            if(position == 'f' || position == 'F'){
                node *temp= front;
                front->next->previous= NULL;
                cout<<endl<<front->data<<" : is Deleted successfully at the Front of DE_Queue."<<endl;
                front= front->next;
                delete temp;
            }else if(position == 'r' || position == 'R'){
                node *temp= rear;
                cout<<endl<<rear->data<<" : is Deleted successfully at the Rear of DE_Queue."<<endl<<endl;
                rear= rear->previous;
                rear->next= NULL;
                delete temp;
            }
        }
    }else{
        cout<<endl<<"There is no element to Delete from Front or Back in DE_Queue."<<endl;
    }
}

//Definition of getFront() function of class DE_QueueUsingDoublylinkedlist.
int DE_QueueUsingDoublyLinkedList::getData(char position){
    if(isEmpty()){
        return -1;
    }else{
        if(position == 'f' || position == 'F'){
            return front->data;
        }else if(position == 'r' || position == 'R'){
            return rear->data;
        }
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
        deleteData('f');
    }
}

int main(){
    cout<<"DE_Queue Using Doubly Linked list Data Structure in C++ programming\n"<<endl;

    int choice= 0, element;
    char position;
    DE_QueueUsingDoublyLinkedList dE_QUDLL;

    while(1){
        
        cout<<"__________________________________________________________________________"<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"|          **** Please Select Your Operation. ****                       |"<<endl;
        cout<<"|------------------------------------------------------------------------|"<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"|       1-> Insert elements at the Front(F/f) & Rear(R/r) of DE_Queue.   |"<<endl;
        cout<<"|       2-> Delete element at the Front(F/f) & Rear(R/r) of DE_Queue.    |"<<endl;
        cout<<"|       3-> Get Front(f) & Rear(r) element of the DE_Queue.              |"<<endl;
        cout<<"|       4-> Check DE_Queue is Empty or Not.                              |"<<endl;
        cout<<"|       5-> Reversing the List elements of DE_Queue.                     |"<<endl;
        cout<<"|       6-> Total count of nodes in the DE_Queue.                        |"<<endl;
        cout<<"|       7-> Display DE_Queue elements.                                   |"<<endl;
        cout<<"|       8-> Exit.                                                        |"<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"**************************************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                cout<<"Enter position to insert Data Front(F/f) & Rear(R/r) : ";
                cin>>position;
                system("cls");
                dE_QUDLL.insertData(position, element);
                cout<<endl;
                break;
            }
            case 2: {
                if(dE_QUDLL.isEmpty()){
                    system("cls");
                    cout<<endl<<"There is no element to Delete from Front or Rear in DE_Queue."<<endl<<endl;
                }else{
                    cout<<"Enter position to insert Data Front(F/f) & Rear(R/r) : ";
                    cin>>position;
                    system("cls");
                    dE_QUDLL.deleteData(position);
                }
                break;
            }
            case 3: {
                if(dE_QUDLL.isEmpty()){
                    system("cls");
                    cout<<endl<<"There is no element in DE_Queue to get Front or Rear."<<endl;
                }else{
                    cout<<"Enter position to insert Data Front(F/f) & Rear(R/r) : ";
                    cin>>position;
                    system("cls");
                    int temp= dE_QUDLL.getData(position);
                    if(temp != -1){
                        if(position == 'F' || position == 'f'){
                            cout<<endl<<temp<<" : is Present at the Front of DE_Queue."<<endl;
                        }else if(position == 'R' || position == 'r'){
                            cout<<endl<<temp<<" : is Present at the Rear of DE_Queue."<<endl;
                        }
                    }else{
                        cout<<endl<<"There is no element at the Front or Rear of DE_Queue."<<endl;
                    }
                }
                cout<<endl;
                break;
            }
            case 4: {
                system("cls");
                if(dE_QUDLL.isEmpty()){
                    cout<<endl<<"Queue is Empty."<<endl;
                }else{
                    cout<<endl<<"Queue is not Empty."<<endl;
                }
                cout<<endl;
                break;
            }
            case 5: {
                dE_QUDLL.reverse();
                system("cls");
                //cout<<"DE_Queue has been reversed successfully."<<endl;
                cout<<endl<<"It's not working still now."<<endl;
                dE_QUDLL.displayDE_Queue();
                cout<<endl;
                break;
            }
            case 6: {
                int totalNode= 0;
                totalNode= dE_QUDLL.length();
                system("cls");
                cout<<endl<<"The total node is : "<<totalNode<<endl<<endl;
                break;
            }
            case 7: {
                system("cls");
                dE_QUDLL.displayDE_Queue();
                cout<<endl;
                break;
            }
            case 8: {
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