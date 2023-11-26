//Write a program to Find the first and last occurence of a given number in an given Array using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Find the first and last occurence of a given number in an given Array.
int recursiveFunctionForFirstOccurence(int arr[], int arraySize, int position, int key){
    if(position == arraySize){
        return -1;
    }
    if(arr[position] == key){
        return position;
    }
    return recursiveFunctionForFirstOccurence(arr, arraySize, position+ 1, key);
}

int recursiveFunctionForLastOccurence(int arr[], int arraySize, int position, int key){
    if(position == arraySize){
        return -1;
    }
    int restArray= recursiveFunctionForLastOccurence(arr, arraySize, position+ 1, key);
    if(restArray!= -1){
        return restArray;
    }
    if(arr[position] == key){
        return position;
    }
    return -1;
}

int main(){
    cout<<"Find the first and last occurence of a given number in an given Array using Recursive function in C++ programming\n";
    
    int arraySize;
    cout<<"Enter the size of Array : ";
    cin>>arraySize;

    int arr[arraySize];

    for(int i= 0; i< arraySize; i++){
        cout<<"Enter array element at "<<i<<"th index : ";
        cin>>arr[i];
    }

    int key;
    cout<<"Enter your key which you want to find occurences : ";
    cin>>key;

    int firstOccurence= recursiveFunctionForFirstOccurence(arr, arraySize, 0, key);
    int lastOccurence= recursiveFunctionForLastOccurence(arr, arraySize, 0, key);

    cout<<"The first Occurence of "<<key<<" is at index : "<<firstOccurence<<endl; 
    cout<<"The last Occurence of "<<key<<" is at index : "<<lastOccurence<<endl; 
    
    //getch();
    return(0);
}