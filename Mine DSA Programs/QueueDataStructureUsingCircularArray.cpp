//Write a program to Use Queue Data Structure using Circular Array in C++ programming with Ritik.
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
class QueueUsingCircularArray{
    private:
    int *queueArray; // This will denote Array of the Queue.
    int front; // This will track Front value of Queue.
    int back; // This will track last value of Queue.
    int capacity; // This will remember the total size of the QueueArray.

    public:
    QueueUsingCircularArray(int); // This is the constructor of QueueUsingCircularArray's Class to initialize the member variables.
    bool isFull(); // This function is used to check an Queue is full or not.
    bool isEmpty(); // This function is used to check an Queue is empty or not.
    void enQueue(int); // This function is used to push/insert/enQueue a new element in the Queue.
    void deQueue(); // This function is used to pop/remove/deQueue Front element of the Queue.
    int peekFront(); // This function is used to peek/view front element of the Queue.
    int peekBack(); // This function is used to peek/view Back element of the Queue.
    bool reverse(); // This function is used to reverse Queue elements.
    int getSize(); //This function is used to get filled size of the Queue.
    void clearQueue(); //This function is used to clear whole Queue.
    QueueUsingCircularArray& operator=(QueueUsingCircularArray &); //This is Assignment operloading.
    void displayQueue(); // This function is used to print inserted element of the Queue.
    ~QueueUsingCircularArray(); // This is a distructor of this QueueUsingCircularArray's class to dealocated initialized memory..

};

// Parameterized Constructor of QueueUsingCircularArray Class.
QueueUsingCircularArray::QueueUsingCircularArray(int size){
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
bool QueueUsingCircularArray::isFull(){
    return (front == 0 & capacity == back+ 1 || front == back+ 1);
}

// Function for checking the Queue is empty or not.
bool QueueUsingCircularArray::isEmpty(){
    return (front == -1 && back == -1);
}

// Function for push()/enQueue() a new element in the Queue.
void QueueUsingCircularArray::enQueue(int data){
    if(isFull()){
       cout<<"Queue is overFlow - for enQueue : "<<data<<endl;
    }else if(back != capacity- 1){
        back++;
        queueArray[back]= data;
        cout<<data<<" : is enQueue successfully in the Queue."<<endl;

        if(front == -1){ //This case will execute when we enter first eleemnt in the queue.
            front++;
        }
    }else if(back == capacity- 1){
        back= 0;
        queueArray[back]= data;
        cout<<data<<" : is enQueue successfully in the Queue."<<endl;
    }
}

// Function for pop()/deQueue() Front element of the Queue.
void QueueUsingCircularArray::deQueue(){
    if(isEmpty()){
        cout<<"There is no element to deQueue in Queue."<<endl;
        return;
    }else{
        if(front< capacity- 1 && front != back){
            front++;
            cout<<"Front is deQueue Successfully from the Queue."<<endl;
        }else if(front == capacity-1 && back == capacity-1 || front == back){
            front= back= -1;
            cout<<"Front is deQueue Successfully from the Queue."<<endl;
        }else{
            front= 0;
            cout<<"Front is deQueue Successfully from the Queue."<<endl;
        }
    }
}

// Function for peekFront() Front element of the Queue.
int QueueUsingCircularArray::peekFront(){
    if(isEmpty()){
        cout<<"There is no element to Peek Front in Queue."<<endl;
        return -1;
    }
    return queueArray[front];
}

// Function for peekBack() Back element of the Queue.
int QueueUsingCircularArray::peekBack(){
    if(isEmpty()){
        cout<<"There is no element to Peek Back in Queue."<<endl;
        return -1;
    }
    return queueArray[back];
}

// Function for reverse() elements of the Queue.
/*bool QueueUsingCircularArray::reverse(){
    if(isEmpty()){
        return false;
    }else if(back< capacity && back> front || front == back){
        int temp; 
        for(int i= front; i<(back+ 1)/2; i++){ 
            temp= queueArray[i]; 
            queueArray[i]= queueArray[back-i]; 
            queueArray[back-i]= temp; 
        }
        return true;
    }
}*/

// Function for getSize() of the filled Queue.
int QueueUsingCircularArray::getSize(){
    if(isEmpty()){
        return 0;
    }else if(isFull()){
        return (capacity);
    }else if(back< capacity && back> front || front == back){
        return ((back+ 1)- front);
    }else{
        int counter= 0;
        for(int i= 0; i<= back; i++){
            counter++;
        }
        return (capacity- front)+ counter;
    }
}

// Function for clearQueue() whole Queue.
void QueueUsingCircularArray::clearQueue(){
    if(isEmpty()){
        cout<<"Queue is Already Empty."<<endl;
    }else{
        front= back= -1;
        cout<<"The Whole Queue is Clear Successfully."<<endl;
    }
}

// Function for = Assignment operator overloading.
QueueUsingCircularArray& QueueUsingCircularArray::operator=(QueueUsingCircularArray &tempStack){
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
void QueueUsingCircularArray::displayQueue(){
    if(isEmpty()){
        cout<<"There is no element to Display in the Queue."<<endl;
    }else{
        if(front< capacity || front == back){
            if(front<= back){
                for(int i= front; i<= back; i++){
                    cout<<queueArray[i]<<" <- ";
                }
            }else{
                for(int i= front; i< capacity; i++){
                    cout<<queueArray[i]<<" <- ";
                }
            }
        }
        if(front> back){
            for(int i= 0; i<= back; i++){
                cout<<queueArray[i]<<" <- ";
            }
        }
        if(isFull()){
            cout<<"FULL";
        }
        cout<<endl;
    }
}

// This is the distructor of this class StackUsingArray.
QueueUsingCircularArray::~QueueUsingCircularArray(){
    delete []queueArray;
}

int main(){

    system("Color 02");
    cout<<"Queue Data structure using Circular Array in C++ programming\n"<<endl;

    int choice, element, n= 10;

    // cout<<"Enter the Size to Create Queue = ";
    // cin>>n;
    QueueUsingCircularArray qUCA(n);

    system("cls");
    cout<<"Queue is Created successfully the size of : "<<n<<endl;

    /*
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
                qUCA.enQueue(element);
                break;
            }
            case 2: {
                system("cls");
                //qUCA.deQueue();
                break;
            }
            case 3: {
                system("cls");
                // int temp= qUCA.peekFront();
                // if(temp != -1){
                //     cout<<temp<<" : is Present on the Front of Queue."<<endl;
                // }
                break;
            }
            case 4: {
                system("cls");
                // int temp= qUCA.peekBack();
                // if(temp != -1){
                //     cout<<temp<<" : is Present on the Back of Queue."<<endl;
                // }
                break;
            }
            case 5: {
                // if(qUCA.reverse()){
                //     system("cls");
                //     cout<<"Queue has been reversed successfully."<<endl<<endl;
                //     qUCA.displayQueue();
                // }else{
                //     system("cls");
                //     cout<<"Can't Reverse because of Empty Queue."<<endl;
                // }    
                break;
            }
            case 6: {
                system("cls");
                // if(qUCA.isFull()){
                //     cout<<"Queue is FULL."<<endl;
                // }else{
                //     cout<<"Queue is not FULL."<<endl;
                // }
                break;
            }
            case 7: {
                system("cls");
                // if(qUCA.isEmpty()){
                //     cout<<"Queue is Empty."<<endl;
                // }else{
                //     cout<<"Queue is not Empty."<<endl;
                // }
                break;
            }
            case 8: {
                system("cls");
                qUCA.displayQueue();
                break;
            }
            case 9: {
                system("cls");
                //cout<<qUCA.getSize()<<" : elements is present in the Queue."<<endl;
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
    */

    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;
    cout<<endl;

    qUCA.enQueue(10);
    qUCA.enQueue(20);
    qUCA.enQueue(30);
    qUCA.enQueue(40);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(50);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(60);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(70);
    qUCA.enQueue(80);
    qUCA.enQueue(90);
    qUCA.enQueue(100);
    qUCA.enQueue(110);
    qUCA.enQueue(120);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(70);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(80);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(90);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(120);
    qUCA.enQueue(130);
    qUCA.enQueue(140);
    qUCA.enQueue(150);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(10);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(20);
    qUCA.enQueue(30);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.enQueue(50);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(50);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(10);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(20);
    qUCA.enQueue(30);
    qUCA.enQueue(40);
    qUCA.enQueue(50);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(60);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(10);
    qUCA.enQueue(20);
    qUCA.enQueue(30);
    qUCA.enQueue(40);
    qUCA.enQueue(50);
    qUCA.enQueue(60);
    qUCA.enQueue(70);
    qUCA.enQueue(80);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.clearQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(10);
    qUCA.enQueue(20);
    qUCA.enQueue(30);
    qUCA.enQueue(40);
    qUCA.enQueue(50);
    qUCA.enQueue(60);
    qUCA.enQueue(70);
    qUCA.enQueue(80);
    qUCA.enQueue(90);
    qUCA.enQueue(100);
    qUCA.enQueue(110);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue();
    qUCA.deQueue(); //extra deQueue.
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.clearQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.enQueue(90);
    qUCA.enQueue(100);
    qUCA.enQueue(110);
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;
    qUCA.clearQueue();
    qUCA.displayQueue();
    cout<<"Now the size of filled queue is : "<<qUCA.getSize()<<endl;
    cout<<"Element at the front of the queue : "<<qUCA.peekFront()<<endl;
    cout<<"Element at the back of the queue : "<<qUCA.peekBack()<<endl;
    cout<<"Queue is Full or not : "<<qUCA.isFull()<<endl;
    cout<<"Queue is Empty or not : "<<qUCA.isEmpty()<<endl;

    cout<<endl;

    //getch();
    return(0);
}