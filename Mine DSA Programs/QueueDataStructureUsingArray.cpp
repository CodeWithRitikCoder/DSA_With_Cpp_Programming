//Write a program to Use Queue Data Structure using Array in C++ programming with Ritik.
/*
Notes:-
        => What is Queue Data Structure ?
        -> Queue is used to stores a list of items in which an item can be inserted at one end and remove from the other end only.
        -> And it is based on the FIFO machinism it means (First In First Out).
*/
#include"iostream"
#include"conio.h"
using namespace std;

//Class is here.
class QueueUsingArray{
    private:
    int *queueArray; // This will denote Array of the Queue.
    int front; // This will track Front value of Queue.
    int back; // This will track last value of Queue.
    int capacity; // This will remember the total size of the QueueArray.

    public:
    QueueUsingArray(int); // This is the constructor of QueueUsingArray's Class to initialize the member variables.
    bool isFull(); // This function is used to check an Queue is full or not.
    bool isEmpty(); // This function is used to check an Queue is empty or not.
    void enQueue(int); // This function is used to push/insert/enQueue a new element in the Queue.
    void deQueue(); // This function is used to pop/remove/deQueue Front element of the Queue.
    int peekFront(); // This function is used to peek/view front element of the Queue.
    int peekBack(); // This function is used to peek/view Back element of the Queue.
    bool reverse(); // This function is used to reverse Queue elements.
    int getSize(); //This function is used to get filled size of the Queue.
    QueueUsingArray& operator=(QueueUsingArray &); //This is Assignment operloading.
    void displayQueue(); // This function is used to print inserted element of the Queue.
    ~QueueUsingArray(); // This is a distructor of this QueueUsingArray's class to dealocated initialized memory..

};

// Parameterized Constructor of QueueUsingArray Class.
QueueUsingArray::QueueUsingArray(int size){
    if(size>0){
        capacity= size;
        queueArray= new int(size);
        front= -1;
        back= -1;
        //cout<<"Array has been created successfully"<<endl;
    }else{
        queueArray= NULL;
        cout<<"Invalid index for Array creation."<<endl;
    }
}

// Function for checking the Queue is Full or not.
bool QueueUsingArray::isFull(){
    return (back == capacity- 1);
}

// Function for checking the Queue is empty or not.
bool QueueUsingArray::isEmpty(){
    return (front == -1 || front> back);
}

// Function for push()/enQueue() a new element in the Queue.
void QueueUsingArray::enQueue(int data){
    if(isFull()){
       cout<<"Queue is overFlow."<<endl;
    }else{
        back++;
        queueArray[back]= data;
        cout<<data<<" : is enQueue successfully in the Queue."<<endl;

        if(front == -1){ //This case will execute when we enter first eleemnt in the queue.
            front++;
        }
    }
}

// Function for pop()/deQueue() Front element of the Queue.
void QueueUsingArray::deQueue(){
    if(isEmpty()){
        cout<<"There is no element to deQueue in Queue."<<endl;
        return;
    }else{
        front++;
        cout<<"Front is deQueue Successfully from the Queue."<<endl;
    }
}

// Function for peekFront() Front element of the Queue.
int QueueUsingArray::peekFront(){
    if(isEmpty()){
        cout<<"There is no element to Peek Front in Queue."<<endl;
        return -1;
    }
    return queueArray[front];
}

// Function for peekBack() Back element of the Queue.
int QueueUsingArray::peekBack(){
    if(isEmpty()){
        cout<<"There is no element to Peek Back in Queue."<<endl;
        return -1;
    }
    return queueArray[back];
}

// Function for reverse() elements of the Queue.
bool QueueUsingArray::reverse(){
    if(isEmpty()){
        return false;
    }else{
        int temp; 
        for(int i= front; i<(back+ 1)/2; i++){ 
            temp= queueArray[i]; 
            queueArray[i]= queueArray[back-i]; 
            queueArray[back-i]= temp; 
        }
        return true;
    }
}

// Function for getSize() of the filled Queue.
int QueueUsingArray::getSize(){
    if(front == -1 && back == -1){
        return 0;
    }else{
        return ((back+ 1)- front);
    }
}

// Function for = Assignment operator overloading.
QueueUsingArray& QueueUsingArray::operator=(QueueUsingArray &tempStack){
    if(this != &tempStack){
        capacity= tempStack.capacity;
        front= tempStack.front;
        if(queueArray != NULL){
            delete []queueArray;
        }
        queueArray= new int[capacity];
        for(int i= 0; i<= front; i++){
            queueArray[i]= tempStack.queueArray[i];
        }
    }
    return *this;
}

// Function for displayQueue() data.
void QueueUsingArray::displayQueue(){
    if(isEmpty()){
        cout<<"There is no element to Display in the Queue."<<endl;
    }else{
        for(int i= front; i<= back; i++){
            cout<<queueArray[i]<<" <- ";
        }
        cout<<endl;
    }
}

// This is the distructor of this class StackUsingArray.
QueueUsingArray::~QueueUsingArray(){
    delete []queueArray;
}

int main(){

    system("Color 02");
    cout<<"Queue Data structure using Array in C++ programming\n"<<endl;

    int choice, element, n;

    cout<<"Enter the Size to Create Queue = ";
    cin>>n;
    QueueUsingArray qUA(n);

    system("cls");
    cout<<"Queue is Created successfully the size of : "<<n<<endl;

    while(1){

        cout<<"___________________________________________________"<<endl;
        cout<<"|                                                 |"<<endl;
        cout<<"|    **** Please Select Your Operation. ****      |"<<endl;
        cout<<"|-------------------------------------------------|"<<endl;
        cout<<"|                                                 |"<<endl;
        cout<<"|       1-> EnQueue elements in the Queue.        |"<<endl;
        cout<<"|       2-> DeQueue elements from the Queue.      |"<<endl;
        cout<<"|       3-> PEEK Front element of Queue.          |"<<endl;
        cout<<"|       4-> PEEK Back element of Queue.           |"<<endl;
        cout<<"|       5-> Reversing the Queue.                  |"<<endl;
        cout<<"|       6-> Queue is Full or Not.                 |"<<endl;
        cout<<"|       7-> Queue is Empty of Not.                |"<<endl;
        cout<<"|       8-> Display elements of Queue.            |"<<endl;
        cout<<"|       9-> Total element count of Queue.         |"<<endl;
        cout<<"|       10-> Exit.                                |"<<endl;
        cout<<"|                                                 |"<<endl;
        cout<<"***************************************************"<<endl<<endl;
        cout<<"Enter your choice here : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element here : ";
                cin>>element;
                system("cls");
                qUA.enQueue(element);
                break;
            }
            case 2: {
                system("cls");
                qUA.deQueue();
                break;
            }
            case 3: {
                system("cls");
                int temp= qUA.peekFront();
                if(temp != -1){
                    cout<<temp<<" : is Present on the Front of Queue."<<endl;
                }
                break;
            }
            case 4: {
                system("cls");
                int temp= qUA.peekBack();
                if(temp != -1){
                    cout<<temp<<" : is Present on the Back of Queue."<<endl;
                }
                break;
            }
            case 5: {
                if(qUA.reverse()){
                    system("cls");
                    cout<<"Queue has been reversed successfully."<<endl<<endl;
                    qUA.displayQueue();
                }else{
                    system("cls");
                    cout<<"Can't Reverse because of Empty Queue."<<endl;
                }    
                break;
            }
            case 6: {
                system("cls");
                if(qUA.isFull()){
                    cout<<"Queue is FULL."<<endl;
                }else{
                    cout<<"Queue is not FULL."<<endl;
                }
                break;
            }
            case 7: {
                system("cls");
                if(qUA.isEmpty()){
                    cout<<"Queue is Empty."<<endl;
                }else{
                    cout<<"Queue is not Empty."<<endl;
                }
                break;
            }
            case 8: {
                system("cls");
                qUA.displayQueue();
                break;
            }
            case 9: {
                system("cls");
                cout<<qUA.getSize()<<" : elements is present in the Queue."<<endl;
                break;
            }
            case 10: {
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

    // qUA.displayQueue();
    // qUA.isEmpty();
    // qUA.isFull();
    // qUA.peekFront();
    // qUA.peekBack();
    // qUA.enQueue(10);
    // qUA.enQueue(20);
    // qUA.enQueue(30);
    // qUA.enQueue(40);
    // qUA.enQueue(50);
    // cout<<endl;
    // qUA.displayQueue();
    // cout<<endl;
    // cout<<"It is the result of isFull() function = "<<qUA.isFull()<<endl;
    // cout<<"It is the result of isEmpty() function = "<<qUA.isEmpty()<<endl;
    // cout<<"This element is present on the Front of the Queue = "<<qUA.peekFront()<<endl;
    // cout<<"This element is present on the Back of the Queue = "<<qUA.peekBack()<<endl;
    // cout<<endl;
    // qUA.displayQueue();
    // qUA.deQueue();
    // cout<<endl;
    // qUA.displayQueue();
    // cout<<endl;
    // qUA.deQueue();
    // qUA.displayQueue();

    //This code is not working still now.
    /*
    QueueUsingArray qUA1(5);
    qUA1.enQueue(60);
    cout<<endl;
    qUA1.displayQueue();
    cout<<endl;

    qUA= qUA1;
    qUA.displayQueue();
    */

    //getch();
    return(0);
}