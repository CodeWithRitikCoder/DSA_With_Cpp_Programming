//Write a program to Tower of Hanoi Moves of given blacks using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;
int count= 1;

//Recusive Funtion to Tower of Hanoi Moves of given blacks.
void recursiveFunctionForTowerOfHanoi(int blocks, char source, char destinaction, char helper){
    if(blocks == 0){
        return;
    }
    recursiveFunctionForTowerOfHanoi(blocks- 1, source, helper, destinaction);
    cout<<count<<" => Move from "<<source<<" to "<<destinaction<<endl;
    count++;
    recursiveFunctionForTowerOfHanoi(blocks- 1, helper, destinaction, source);
}

int main(){
    cout<<"Tower of Hanoi Moves of given blacks using Recursive function in C++ programming\n";
    
    int blocks;
    cout<<"Enter blocks quantity : ";
    cin>>blocks;

    recursiveFunctionForTowerOfHanoi(blocks, 'A', 'C', 'B');
    
    //getch();
    return(0);
}