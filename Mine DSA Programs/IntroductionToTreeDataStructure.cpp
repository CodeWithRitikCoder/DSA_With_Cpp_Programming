//Write a program to Introduction to Tree Data Structure. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

/*
Notes:-
    => Tree Data Structure.
                    (7)----------->[Root]
                 /   |  \--------->[Edge]
              (8)   (2)  (11)----->[These all are Nodes]
            /  \    /      \
         (1)  (6)  (2)     (3)
                            \
                            (4)

    => Terminologys of Tree Data Structure.
        1:- Root-> Topmost node is Called Root node.
        2:- Parent-> Node which connects to the child.
        3:- Siblings-> Nodes belongings to the same parent.
        4:- Child-> Node which is connected by another node is it's child.
        5:- Leaf/External Node-> Nodes with no children.
        6:- Internal Node-> Node with at least one child.
        7:- Depth-> Number of edges from root to the Node.
        8:- Height-> Number of edges from node to the deepest leaf.
        9:- Ancestors-> Upword relations -- Parent or parent of parent.
        10:- Descendents-> Downlword relations -- Child or child of child.
        11:- Level->                     (7)
                                      /   |  \
                        >----------(8)---(2)--(11)----> this is called level of tree.
        12:- Degree-> Total child of parents node is known as Degree.

    => Why use Tree Data Structure?
        -> Ideal for representing hierarchical data.

    => Binary Tree.
    => What is Binary Tree?
        -> Binary tree is a tree which has at most two children for all the nodes.
        i.g->        (7)
                    /  \
                 (8)    (11)  ----->[Yes, It's a Binary tree]
                /  \    /  \
              (1) (6)  (9) (3)

        i.g->       (7)
                 /   |   \
             (8)    (2)   (11)  ----->[No, It's a Binary tree]

    => Properties of Binary tree.
        1-> Tree is made up of nodes & edges.
        2-> n nodes = n-1 edges.
            i.g->        (7)        (i)-> It has 7 nodes in this tree.
                        /  \        (ii)-> It has node-1 = edges.
                     (8)    (11)    (iii)-> It has 6 edges.
                    /  \    /  \
                  (1) (6)  (9) (3)
    
        3-> Degree:- Number of direct child (for a node).
        4-> Degree of a tree is the highest degree of a node among all the node present in the tree.
        5-> Binary tree:- Tree of degree=2
            -> Nodes can have 0, 1 or 2 children.
            i.g->        (7)----------->[Root Node]
                        /  \----------->[Edge]
                     (8)    (11)------->[These all are Nodes]
                    /  \    /  \
                  (1) (6)  (9) (3)
                        \
                        (3)------------>[Leaf Node]                 

    => Type of Binary Tree.
        -> There are Four (4) types of binary tree.

            1. Full or Strict binary tree.
            2. Perfect binart tree.
            3. Complete binary tree.
            4. Degenerate tree.
                i. Skewed tree.
                    a. Left skewed tree.
                    b. Right skewed tree.

        1=> Full or Strict binary tree.
            -> All nodes have either (0) or (2) children.

                1-i.g->        (7)   ----> It have two children.
                              /  \       ===>[Yes, This is called Full or Strict binary tree.]
                           (8)    (11)
                                    |-----> It has (0) children.

                2-i.g->        (7)
                              /  \
                           (8)    (11)       ===>[Yes, It is also Full or Strict binary tree.]
                          /  \
                      (3)    (1)

                3-i.g->        (7)
                              /  \
                           (8)    (11)       ===>[No, It is not Full or Strict binary tree.]
                          /  \      \
                      (3)    (1)    (5) -->[because of it has has only (1) child so it's not a Full or Strict binary tree.]

        2=> Perfect binary tree.
            -> Internal nodes have 2 childrens and(+) all leaf nodes are on same level.

                1-i.g->      (7)
                            /  \
                         (8)    (11)       ===>[Yes, It is Perfect binary tree.]
                        /  \    /  \
                      (1) (6)  (9) (3)    

                2-i.g->        (7)
                              /  \
                           (8)    (11)       ===>[No, It is not Pefect binary tree because of it break rule no-1 which is
                          /  \      \            Internal nodes have (2) child but It has only one (1) child.]
                      (3)    (1)    (5)

        3=> Complete binary tree.
            -> All levels are completely fill except possible the last level and last level must have its keys are left as possible.

                1-i.g->      (7)
                            /  \
                         (8)    (11)       ===>[Yes, It is a Completely binary tree.]
                        /  \    /  \
                      (1) (6)  (9) (3) 

                2-i.g->      (7)
                            /  \
                         (8)    (11)       ===>[Yes, It is also a Completely binary tree.
                        /  \    /               because of all keys are align in left side.]
                      (1) (6)  (9)

                3-i.g->        (7)
                              /  \
                           (8)    (11)       ===>[It is not a Complete binary tree.
                          /  \      \             because of the keys are not algin in left side.]
                      (3)    (1)    (5) 

                4-i.g->        (7)
                              /  \
                           (8)    (11)       ===>[It is not a Complete binary tree.
                          /  \                    because of all levels are not completely filled.]
                      (3)    (1) 

        4=> Degenerate tree.
            -> Every parents node has exactly one child
            -> And it has also Skewed Tree.

                1-i.g->        (7)
                              /
                           (8)       ===>[It is a Degenerate tree.
                          /                    because of every parent node has only one child.]
                       (3) 
                        \
                        (1)

                2-i.g->        (7)
                              /
                           (8)       ===>[It is also a Degenerate tree.
                          /                    because of every parent node has only one child.]
                       (3)
                      /
                    (5)

                2-i.g-> (7)
                          \
                          (8)       ===>[It is also a Degenerate tree.
                            \                    because of every parent node has only one child.]
                            (3)
                              \
                              (5)

            => Skewed tree
                -> There are two types of Skewed trees.

                i-> Left Skewed tree.
                ii-> Right Skewed tree.

                => Left Skewed tree.
                    -> Every parent node has its left child node. if it has.
                    -> All the children of a left skewed trees are towords the left.

                    1-i.g->        (7)
                                  /
                               (8)       ===>[It is a Left Skewed tree.
                              /                    because of every parent node has it's left child.]
                           (3)
                          /
                        (5)

                    2-i.g->        (7)
                                  /
                               (8)       ===>[It's not a Left Skewed tree.
                              /                    because of it break the rule of left skewed tree.]
                           (3) 
                            \
                            (1)
                            /
                         (4)

                => Right Skewed tree.
                    -> Every parent node has its Right child node. if it has.
                    -> All the children of a Right skewed trees are towords the Right.

                    1-i.g-> (7)
                              \
                              (8)       ===>[It is a Right Skewed tree.
                                \            because of every parent node has it's Right child.]
                                (3)
                                  \
                                  (5)
                                    \
                                    (9)

                    2-i.g-> (7)
                              \
                              (3)
                                \
                                (8)       ===>[It is not a Right Skewed tree.
                               /            because of it break the rule of Right skewed tree.]
                            (3)
                              \
                              (5)
                             /
                          (9)
                            \
                            (2)

    => Representation of a Binary Tree.

        1-> Array Representation of binary tree. - (Not Recomanded).
        2-> Linked Representation Using Doubly Linked List. - (Recomanded).

    => Traversal in Binary Tree.
        -> There are three types of traversal in Binary Tree.

            1-> Pre-Order Traversal. ---> (Root -> Left -> Right)
            2-> Post-Order Traversal. ---> (Left -> Right -> Root)
            3-> In-Order Traversal. ---> (Left -> Root -> Right)

            -> Let's Suppose We have this tree.
                i.g->      (9)
                            /  \
                         (7)    (11)
                        /  \    /  \
                      (1) (8)  (10) (12)
                
                The find out the Traversal of this Tree.

                    -> Pre-Order Traversal of this Tree is :- 9, 7, 1, 8, 11, 10, 12
                    -> Post-Order Traversal of this Tree is :- 1, 8, 7, 10, 12, 11, 9
                    -> In-Order Traversal of this Tree is :- 1, 7, 8, 9, 10, 11, 12

            => Trick to find Pre-Order, Post-Order and In-Order Traversal of Binary Tree.
                1. In Pre-Order Traversal (<--)
                2. In Post-Order Traversal (-->)
                3. In In-Order Traversal (down-Arrow)
                => After draw the line start cutting these lines. and also printing your Traversal number as well.

*/

int main(){
    cout<<"Introduction to Tree Data Structure. in C++ programming\n"<<endl;
    
    
    //getch();
    return(0);
}