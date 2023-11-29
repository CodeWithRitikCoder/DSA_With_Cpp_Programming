//Write a program to Introduction to Binary Search Tree Data Structure. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

/*
Notes:-
    => Binary Search Tree Data Structure.
        -> It is a type of Binary Tree Data Structure.
                i.g->      (9)
                          /  \
                       (7)    (11)
                      /  \    /  \
                    (1) (8)  (10) (12)
            
            => It's a Binary Search Tree.

    => Properties of a Binary Search Tree.

        1-> All nodes of the left subtree are lesses from its root node.
        2-> All nodes of the left subtree are greater from its root node.
        3-> Left & Right subtrees are also Binary Search Tree.
        4-> There are no duplicate node in Binary Search Tree.
        5-> Inorder Traversal of a Binary Search Tree gives an accending sorted elements.

        => Let's look a tree of Binary Search Tree or not.
                i.g->      (8)                 |                i.g->      (11)
                          /  \                 |                          /   \
                       (4)    (9)              |                      (10)    (12)
                      /  \    /                |                      /  \    /  \
                    (3) (2)  (6)               |                   (8) (13)  (9) (14)
                                               |
                -> No, It's not a BST.         |       -> Yes, It's a BST because of It fllows all the BST Properties.
                                               |

    => What is In-Order Predecisor and In-Order Successor.
        -> In-Order Predecisor.
        -> In-Order Successor.

            => Let's Suppose we have this :- 1, 2, 3, 4, 5, 6, 7, 8;
                -> and now I want to find out In-Order Predecisor and In-Order Successor of (6) from this list.
                    -> Then the In-Order Predecisor of (6) is : 5
                    -> Then the In-Order Successor of (6) is : 7

        -> That's all about In-Order Predicisor and In-Order successor.

    => Operations on a Binary Search Tree.

        => Checking a Tree is Binary Search Tree or Not.

        => Searching a element in a Binary Search Tree.
            -> Recusrively
            -> Iteratively

        => Inserting a element in a Binary Search Tree.

        => Deleting a element in a Binary Search Tree.
            -> There are Four(4) cases while deleting an element from the Binary Search Tree.
                Case 1-> The node is a leaf node.
                        Step 1-> Search for the node. 
                        Step 2-> and delete that node.
                        -> That's it.

                Case 2-> The node is a non-leaf node.
                        Step 1-> Search for the node.
                        Step 2-> and replace that node with the In-Order successor of that node.
                        -> That's it.

                Case 3-> The node is the root node or node in between the Binary Search Tree.
                        Step 1-> Search the node.
                        Step 2-> Search for In-Order predecisor and In-Order Successor.
                        Step 3-> Keep doing it until the tree has no empty node.
                        -> That's it.

                Case 4-> The node is not in the Binary Search Tree.

*/

int main(){
    cout<<"Introduction to Binary Search Tree Data Structure. in C++ programming\n"<<endl;
    
    
    //getch();
    return(0);
}