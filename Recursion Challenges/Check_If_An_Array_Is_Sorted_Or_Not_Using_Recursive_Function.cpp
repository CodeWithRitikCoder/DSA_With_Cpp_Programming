//Write a program to Check if an Array is Sorted or not using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Check if an Array is Sorted or not.
bool recursiveFunction(int arr[], int n){
    if(n == 1){
        return true;
    }
    bool restArray= recursiveFunction(arr+ 1, n-1);
    return (arr[0]< arr[1] && restArray);
}

int main(){
    cout<<"Check if an Array is Sorted or not using Recursive function in C++ programming\n";
    
    int arraySize;
    cout<<"Enter the size of Array : ";
    cin>>arraySize;

    int arr[arraySize];

    for(int i= 0; i< arraySize; i++){
        cout<<"Enter array element at "<<i<<"th index : ";
        cin>>arr[i];
    }
    bool arrayIsSorted= recursiveFunction(arr, arraySize);
    if(arrayIsSorted){
        cout<<"Your Array is Sorted."<<endl;
    }else{
        cout<<"Your Array is non-Sorted."<<endl;
    }

    
    
    //getch();
    return(0);
}