//Write a program to Implement Data Structure with DE_Queue Using Doubly Linked list (Second Method) in C++ programming with Ritik.
/*
Notes:
    => DE_que Data Structure
        -> Deque or Double Ended Queue is a type of queue in which insertion and removal of elements can either be performed from the front or the rear. Thus, it does not follow FIFO rule (First In First Out).
*/
#include"iostream"
#include"conio.h"
using namespace std;

//My Node Structure is here.
struct node{
    node* previous;
    int data;
    node* next;
};

//My DE_QueUsingDoublyLinkedList2 class is here.
class DE_QueUsingDoublyLinkedList2{
    private:
    node *front, *rear;

    public:
    //All functions declarations are here.
    DE_QueUsingDoublyLinkedList2(); // This is the default donstructor of this class.
    void insertData(char, int); //This function is used to insert element at the Front or Rear of the DE_QueueUsingDoublylinkedlist.
    void deleteData(char); //This function is used to delete element from Front ofr Rear of the DE_QueUsingDoublyLinkedList2.
    int getData(char); //This function is used to get Front or Rear element of the DE_QueUsingDoublyLinkedList2.
    bool isEmpty(); //This function is used to check DE_Que is Empty or not.
    void reverse(); //This funciton is used to reverse element of DE_QueUsingDoublyLinkedList2.
    int length(); //This function is used to get the length of the DE_QueUsingDoublyLinkedList2.
    void displayDE_Que(); //This function is used to display the whole data of the DE_QueUsingDoublyLinkedList2.
    ~DE_QueUsingDoublyLinkedList2(); //This is the destructor of this class.
};

//Definition of all the function is here.

//Definiton of default constructor of class DE_QueUsingDoublyLinkedList2.
DE_QueUsingDoublyLinkedList2::DE_QueUsingDoublyLinkedList2(){
    front= NULL;
    rear= NULL;
}

//Definition of insertData() function of class DE_QueUsingDoublyLinkedList2.
void DE_QueUsingDoublyLinkedList2::insertData(char position, int value){
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
        cout<<endl<<value<<" : is Inserted successfully at the Front of DE_Que."<<endl;
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
            cout<<endl<<value<<" : is Inserted successfully at the Rear of DE_Que."<<endl;
        }
    }
}

//Definition of deleteData() function of class DE_QueUsingDoublyLinkedList2.
void DE_QueUsingDoublyLinkedList2::deleteData(char position){
    node *tempToDelete;
    if(front){
        if(front == rear){
            cout<<endl<<front->data<<" : is Deleted successfully at the Front of DE_Que."<<endl;
            front= rear= NULL;
        }else{
            if(position == 'f' || position == 'F'){
                node *temp= front;
                front->next->previous= NULL;
                cout<<endl<<front->data<<" : is Deleted successfully at the Front of DE_Que."<<endl;
                front= front->next;
                delete temp;
            }else if(position == 'r' || position == 'R'){
                node *temp= rear;
                cout<<endl<<rear->data<<" : is Deleted successfully at the Rear of DE_Que."<<endl<<endl;
                rear= rear->previous;
                rear->next= NULL;
                delete temp;
            }
        }
    }else{
        cout<<endl<<"There is no element to Delete from Front or Back in DE_Que."<<endl;
    }
}

//Definition of getData() function of class DE_QueUsingDoublyLinkedList2.
int DE_QueUsingDoublyLinkedList2::getData(char position){
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

//Definition of isEmpty() function of class DE_QueUsingDoublyLinkedList2.
bool DE_QueUsingDoublyLinkedList2::isEmpty(){
    if(front == NULL && rear == NULL){
        return true;
    }else{
        return false;
    }
}

//Definition of reverse function of class DE_QueUsingDoublyLinkedList2.
void DE_QueUsingDoublyLinkedList2::reverse(){
    

}

//Definition of countNode function of class DE_QueUsingDoublyLinkedList2.
int DE_QueUsingDoublyLinkedList2::length(){
    int count= 0;
    node *temp= front;
    while(temp != NULL){
        temp= temp->next;
        count++;
    }
    return count;
}

//Definition of display function of class DE_QueUsingDoublyLinkedList2.
void DE_QueUsingDoublyLinkedList2::displayDE_Que(){
    node *temp= new node;
    temp= front;
    if(temp == NULL){
        cout<<endl<<"There is no node in the DE_Que."<<endl;
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

//Definiton of Distructor of class DE_QueUsingDoublyLinkedList2.
DE_QueUsingDoublyLinkedList2::~DE_QueUsingDoublyLinkedList2(){
    while(front){
        deleteData('f');
    }
}

int main(){
    cout<<"DE_Que Using Doubly Linked list Data Structure in C++ programming\n"<<endl;

    int choice= 0, element;
    char position;
    DE_QueUsingDoublyLinkedList2 dE_QUDLL;

    while(1){
        
        cout<<"__________________________________________________________________________"<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"|          **** Please Select Your Operation. ****                       |"<<endl;
        cout<<"|------------------------------------------------------------------------|"<<endl;
        cout<<"|                                                                        |"<<endl;
        cout<<"|       1-> Insert elements at the Front(F/f) & Rear(R/r) of DE_Que.     |"<<endl;
        cout<<"|       2-> Delete element at the Front(F/f) & Rear(R/r) of DE_Que.      |"<<endl;
        cout<<"|       3-> Get Front(f) & Rear(r) element of the DE_Que.                |"<<endl;
        cout<<"|       4-> Check DE_Que is Empty or Not.                                |"<<endl;
        cout<<"|       5-> Reversing the List elements of DE_Que.                       |"<<endl;
        cout<<"|       6-> Total count of nodes in the DE_Que.                          |"<<endl;
        cout<<"|       7-> Display DE_Que elements.                                     |"<<endl;
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
                    cout<<endl<<"There is no element to Delete from Front or Rear in DE_Que."<<endl<<endl;
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
                    cout<<endl<<"There is no element in DE_Que to get Front or Rear."<<endl;
                }else{
                    cout<<"Enter position to insert Data Front(F/f) & Rear(R/r) : ";
                    cin>>position;
                    system("cls");
                    int temp= dE_QUDLL.getData(position);
                    if(temp != -1){
                        if(position == 'F' || position == 'f'){
                            cout<<endl<<temp<<" : is Present at the Front of DE_Que."<<endl;
                        }else if(position == 'R' || position == 'r'){
                            cout<<endl<<temp<<" : is Present at the Rear of DE_Que."<<endl;
                        }
                    }else{
                        cout<<endl<<"There is no element at the Front or Rear of DE_Que."<<endl;
                    }
                }
                cout<<endl;
                break;
            }
            case 4: {
                system("cls");
                if(dE_QUDLL.isEmpty()){
                    cout<<endl<<"DE_Que is Empty."<<endl;
                }else{
                    cout<<endl<<"DE_Que is not Empty."<<endl;
                }
                cout<<endl;
                break;
            }
            case 5: {
                dE_QUDLL.reverse();
                system("cls");
                //cout<<"DE_Queue has been reversed successfully."<<endl;
                cout<<endl<<"It's not working still now."<<endl;
                dE_QUDLL.displayDE_Que();
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
                dE_QUDLL.displayDE_Que();
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