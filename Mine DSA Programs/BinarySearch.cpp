//Code a program to use Binary search in Data Structure with C++ with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

/*
Notes:-
    => What is Binary search?
    -> Searches for an element by breaking the search space in to half in a sorted array.

    Array is :-
          0   1    2    3    4    5    6  ----> Indexing
        ----------------------------------
        | 8 | 9 | 11 | 18 | 22 | 31 | 88 |  -----> {must be sorted.}
        ----------------------------------
          ^             ^             ^
          |             |             |
        (Low)         (Mid)         (High)

        Search '8' ----> In this array.
                        Element found WC complexity : O(log n)

    => The search continoues towords either side of (mid) based on whether the element to be searched is (lesser) or (greater) then (mid).

    => Some points about Binary search.

        1. Works only on sorder Array.
        2. Inequality operations.
        3. O(log n) WC complexity.

*/

//BinarySearch Function is here.
int BinarySearchFunction(int arr[], int size, int element){
    int low, mid, high;
    low= 0;
    high= size- 1;
    while(low<= high){
        mid= (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]< element){
            low= mid+ 1;
        }else{
            high= mid- 1;
        }
    }
    return -1;
}

int main(){
    cout<<"Binary Search in Data Structure with C++ programming\n"<<endl;
    
    //Sorted array of binary search.
    int arr[]= {1, 3, 5, 56, 64, 73, 123, 225, 444, 456, 554};
    int element= 64;
    int size= sizeof(arr)/sizeof(int);
    int searchIndex= BinarySearchFunction(arr, size, element);
    if(searchIndex == -1){
        cout<<"Element not found in the Array."<<endl;
    }else{
        cout<<"The element "<<element<<" was found at index : "<<searchIndex<<endl;
    }

    
    //getch();
    return(0);
}