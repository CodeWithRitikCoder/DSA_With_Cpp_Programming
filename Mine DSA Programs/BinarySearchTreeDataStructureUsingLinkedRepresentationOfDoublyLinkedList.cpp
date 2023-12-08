//Write a program to Implement BinarySearch Search Tree Data Structure Using Linked Representation Of Doubly Linked List in C++ programming with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//My Node Structure is here.
struct node{
    int data;
    node *left;
    node *right;

    //It's a constructor of this node Structure.
    node(int key){
        data= key;
        left= NULL;
        right= NULL;
    }
};

//Global variable.
int deletedKey;

//My Binary Search Search Tree Using Linked Representation Of Doubly linked List class is here.
class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList{
    private:
    node* root;

    protected:
    bool isBinarySearchTree(node *);
    void pre_OrderTraversal(node *);
    void post_OrderTraversal(node *);
    void in_OrderTraversal(node *);
    node* searchingRecursively(node*, int);
    node* searchingIteratively(node*, int);
    node* inOrderPredecessor(node*);
    node* deleteElement(node *, int, bool);


    public:
    //All functions declarations are here.
    BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList(); // This is the default donstructor of this class.
    bool isBinarySearchTree();
    bool isEmptyBinarySearchTree();
    void insertElement(int);
    void pre_OrderTraversal();
    void post_OrderTraversal();
    void in_OrderTraversal();
    node* searchingRecursively(int);
    node* searchingIteratively(int);
    void deleteElement(int);
    void display(int);
    ~BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList(); //This is the destructor of this class.
};

//Definition of all the function is here.

//Definition of all the Protected functions is here.

//Definiton of isBinarySearchTree protected function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
bool BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::isBinarySearchTree(node *root){
    static node *previous= NULL;
    if(root){
        if(!isBinarySearchTree(root->left)){
            return false;
        }
        if((previous != NULL) && (root->data <= previous->data)){
            return false;
        }
        previous= root;
        return (isBinarySearchTree(root->right));
    }else{
        return true;
    }
}

//Definiton of pre_OrderTraversal protected function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::pre_OrderTraversal(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    pre_OrderTraversal(root->left);
    pre_OrderTraversal(root->right);
}

//Definiton of post_OrderTraversal protected function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::post_OrderTraversal(node *root){
    if(root == NULL){
        return;
    }
    post_OrderTraversal(root->left);
    post_OrderTraversal(root->right);
    cout<<root->data<<" ";
}

//Definiton of in_OrderTraversal protected function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::in_OrderTraversal(node *root){
    if(root == NULL){
        return;
    }
    in_OrderTraversal(root->left);
    cout<<root->data<<" ";
    in_OrderTraversal(root->right);
}

//Definiton of searchingRecursively protected function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
node* BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::searchingRecursively(node *root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }else if(root->data > key){
        return searchingRecursively(root->left, key);
    }else{
        return searchingRecursively(root->right, key);
    }
}

//Definiton of searchingIteratively protected function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
node* BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::searchingIteratively(node *root, int key){
    while(root){
        if(root->data == key){
            return root;
        }else if(root->data > key){
            root= root->left;
        }else{
            root= root->right;
        }
    }
    return NULL;
}

//Definiton of inOrderPredecessor protected function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
node* BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::inOrderPredecessor(node *root){
    root= root->left;
    while(root->right){
        root= root->right;
    }
    return root;
}

//Definiton of deleteElement protected function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
node* BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::deleteElement(node *root, int key, bool toDeleteKey){
    node *iPre;
    if(toDeleteKey){
        deletedKey= key;
    }
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->data == key){
            delete root;
            cout<<deletedKey<<" : is deleted successfully from the Binary Search Tree."<<endl;
            return NULL;
        }else{
            cout<<key<<" : is not present in the Binary Search Tree."<<endl;
            return root;
        }
    }
    //Search for the node to be deleted.
    if(key < root->data){
        root->left= deleteElement(root->left, key, false);
    }else if(key > root->data){
        root->right= deleteElement(root->right, key, false);
    }else{
        iPre= inOrderPredecessor(root);
        root->data= iPre->data;
        root->left= deleteElement(root->left, iPre->data, false);
    }
    return root;
}


//Definition of all the Public functions is here.

//Definiton of default constructor of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList(){
    root= NULL;
}

// Definition of isBinaryTree function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList
bool BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::isBinarySearchTree(){
    return isBinarySearchTree(root);
}

//Definition of isEmptyBinaryTree function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
bool BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::isEmptyBinarySearchTree(){
    return (root == NULL);
}

//Definition of insertAtStart function of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::insertElement(int key){
    node *ptr;
    node *n= new node(key);
    if(root == NULL){
        root= n;
        cout<<key<<" : is inserted successfully in BST. in root"<<endl;
    }else{   
        ptr= root;
        while(key != ptr->data){
            if(key <ptr->data){
                if(ptr->left != NULL){
                    ptr= ptr->left;
                }else{
                    ptr->left= n;
                    cout<<key<<" : is inserted successfully in BST. in left"<<endl;
                    break;
                }
            }else{
                if(ptr->right != NULL){
                    ptr= ptr->right;
                }else{
                    ptr->right= n;
                    cout<<key<<" : is inserted successfully in BST. in right"<<endl;
                    break;
                }
            }
        }
        if(ptr->data == key){
            delete n;
            cout<<"Cannot insert "<<key<<" already exist in BST."<<endl;
        }
    }
}

//Definition of pre_OrderTraversal function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::pre_OrderTraversal(){
    pre_OrderTraversal(root);
}

//Definition of post_OrderTraversal function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::post_OrderTraversal(){
    post_OrderTraversal(root);
}

//Definition of in_OrderTraversal function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::in_OrderTraversal(){
    in_OrderTraversal(root);
}

//Definition of searchingRecursively function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
node* BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::searchingRecursively(int key){
    return searchingRecursively(root, key);
}

//Definition of searchingIteratively function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
node* BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::searchingIteratively(int key){
    return searchingIteratively(root, key);
}

//Definition of deleteElement function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::deleteElement(int key){
    root= deleteElement(root, key, true);
}

//Definition of display function of Class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
void BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::display(int n){
    switch (n){
        case 1:{
            cout<<"It's your Pre-Order Traversal in Binary Search Tree."<<endl;
            cout<<":==> ";
            pre_OrderTraversal(root);
            break;
        }
        case 2:{
            cout<<"It's your Post-Order Traversal in Binary Search Tree."<<endl;
            cout<<":==> ";
            post_OrderTraversal(root);
            break;
        }
        case 3:{
            cout<<"It's your In-Order Traversal in Binary Search Tree."<<endl;
            cout<<":==> ";
            in_OrderTraversal(root);
            break;
        }
        default:{
            cout<<"Invalide choice please choose a valide option."<<endl;
            break;
        }
    }
}

//Definiton of Distructor of class BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList.
BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList::~BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList(){
    while (root){
        deleteElement(root->data);
    }
    
}

int main(){
    cout<<"BinarySearch Tree Data Structure Using Linked Representation Of Doubly Linked List in C++ programming\n"<<endl;

    int choice= 0, element;
    BinarySearchTreeUsingLinkedRepresentationOfDoublyLinkedList bSTULRODLL;

    while(1){
        
        cout<<"_________________________________________________________________"<<endl;
        cout<<"|\t                                                        |"<<endl;
        cout<<"|\t    **** Please Select Your Operation. ****             |"<<endl;
        cout<<"|---------------------------------------------------------------|"<<endl;
        cout<<"|\t                                                        |"<<endl;
        cout<<"|\t1-> Insert elements in the Binary Search Tree.          |"<<endl;
        cout<<"|\t2-> Search elements in Binary Search Tree.              |"<<endl;
        cout<<"|\t3-> Delete elements in Binary Search Tree.              |"<<endl;
        cout<<"|\t4-> Display Traversals of Binary Search Tree.           |"<<endl;
        cout<<"|\t5-> Binary Search Tree is Empty of Not.                 |"<<endl;
        cout<<"|\t6-> Exit.                                               |"<<endl;
        cout<<"|\t                                                        |"<<endl;
        cout<<"*****************************************************************"<<endl<<endl;
        cout<<"Enter your choice to perform that Operation : ";
        cin>>choice;

        //Switch case code is here.
        switch(choice){
            case 1: {
                cout<<"Enter element to Insert in Binary Search Tree : ";
                cin>>element;
                system("cls");
                bSTULRODLL.insertElement(element);
                cout<<endl;
                break;
            }
            case 2: {
                if(bSTULRODLL.isEmptyBinarySearchTree()){
                    system("cls");
                    cout<<"Can't Search because of Empty Binary Search Tree."<<endl;
                }else{
                    cout<<"Enter element to Search in Binary Searhc Tree : ";
                    cin>>element;
                    system("cls");
                    if(bSTULRODLL.searchingIteratively(element)){
                        cout<<element<<" is present in the Binary Search Tree."<<endl;
                    }else{
                        cout<<element<<" is not present in the Binary Search Tree."<<endl;
                    }
                }
                cout<<endl;
                break;
            }
            case 3: {
                if(bSTULRODLL.isEmptyBinarySearchTree()){
                    system("cls");
                    cout<<"Can't Delete because of Empty Binary Search Tree."<<endl;
                }else{
                    cout<<"Enter element to Delete from Binary Search Tree : ";
                    cin>>element;
                    system("cls");
                    bSTULRODLL.deleteElement(element);
                }
                cout<<endl;
                break;
            }
            case 4: {
                if(bSTULRODLL.isEmptyBinarySearchTree()){
                    system("cls");
                    cout<<"Can't Display because of Empty Binary Search Tree."<<endl;
                }else{
                    system("cls");
                    cout<<"_______________________________________________________________________"<<endl;
                    cout<<"|\t                                                              |"<<endl;
                    cout<<"|\t  **** Displaying Binary Searhc Tree Traversal. ****          |"<<endl;
                    cout<<"|---------------------------------------------------------------------|"<<endl;
                    cout<<"|\t                                                              |"<<endl;
                    cout<<"|\t1-> Display Pre-Order Traversal of Binary Search Tree.        |"<<endl;
                    cout<<"|\t2-> Display Post-Order Traversal of Binary Search Tree.       |"<<endl;
                    cout<<"|\t3-> Display In-Order Traversal of Binary Search Tree.         |"<<endl;
                    cout<<"|\t                                                              |"<<endl;
                    cout<<"***********************************************************************"<<endl<<endl;
                    cout<<"Enter your choice to Display Traversal : ";
                    cin>>choice;

                    system("cls");
                    bSTULRODLL.display(choice);
                }
                cout<<endl;
                break;
            }
            case 5: {
                system("cls");
                if(bSTULRODLL.isEmptyBinarySearchTree()){
                    cout<<"Binary Search Tree is Empty."<<endl;
                }else{
                    cout<<"Binary Search Tree is not Empty."<<endl;
                }
                cout<<endl;
                break;
            }
            case 6: {
                exit(1);
                break;
            }
            default :{
                system("cls");
                cout<<"Invalid choice! Please choice a valid option."<<endl<<endl;
                break;
            }
        }
    }


    // cout<<"Is this your Binary Search Tree or not : "<<bSTULRODLL.isBinarySearchTree()<<endl;
    // cout<<"Is Binary Search Tree is Empty or not : "<<bSTULRODLL.isEmptyBinarySearchTree()<<endl;
    // bSTULRODLL.insertElement(8);
    // bSTULRODLL.insertElement(10);
    // bSTULRODLL.insertElement(10);
    // bSTULRODLL.insertElement(3);
    // bSTULRODLL.insertElement(1);
    // bSTULRODLL.insertElement(6);
    // bSTULRODLL.insertElement(4);
    // bSTULRODLL.insertElement(7);
    // bSTULRODLL.insertElement(14);
    // bSTULRODLL.insertElement(13);
    // bSTULRODLL.pre_OrderTraversal();
    // cout<<endl;
    // bSTULRODLL.post_OrderTraversal();
    // cout<<endl;
    // bSTULRODLL.in_OrderTraversal();
    // cout<<endl;
    // cout<<"Is this your Binary Search Tree or not : "<<bSTULRODLL.isBinarySearchTree()<<endl;
    // cout<<"Is Binary Search Tree is Empty or not : "<<bSTULRODLL.isEmptyBinarySearchTree()<<endl;
    // if(bSTULRODLL.searchingRecursively(100)){
    //     cout<<"100 is Present in the Binary search Tree."<<endl;
    // }else{
    //     cout<<"100 is not Present in the Binary search Tree."<<endl;
    // }
    // if(bSTULRODLL.searchingIteratively(7)){
    //     cout<<"7 is Present in the Binary search Tree."<<endl;
    // }else{
    //     cout<<"7 is not Present in the Binary search Tree."<<endl;
    // }

    // bSTULRODLL.deleteElement(8);
    
    // cout<<endl;
    // bSTULRODLL.pre_OrderTraversal();
    // cout<<endl;
    // bSTULRODLL.post_OrderTraversal();
    // cout<<endl;
    // bSTULRODLL.in_OrderTraversal();
    // cout<<endl;
    // cout<<"Is this your Binary Search Tree or not : "<<bSTULRODLL.isBinarySearchTree()<<endl;
    // cout<<"Is Binary Search Tree is Empty or not : "<<bSTULRODLL.isEmptyBinarySearchTree()<<endl;
    // if(bSTULRODLL.searchingRecursively(100)){
    //     cout<<"100 is Present in the Binary search Tree."<<endl;
    // }else{
    //     cout<<"100 is not Present in the Binary search Tree."<<endl;
    // }
    // if(bSTULRODLL.searchingIteratively(7)){
    //     cout<<"7 is Present in the Binary search Tree."<<endl;
    // }else{
    //     cout<<"7 is not Present in the Binary search Tree."<<endl;
    // }
    
    //getch();
    return(0);
}