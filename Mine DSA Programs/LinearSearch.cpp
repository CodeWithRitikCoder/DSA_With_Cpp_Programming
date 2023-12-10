//Code a program to use Linear search in Data Structure with C++ with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

/*
Notes:-
    => What is Linear search?
    -> Searches for an element by visiting all the elements sequentially until the elements is found.

    Array is :-
          0    1   2   3    4   5    6  ----> Indexing
        --------------------------------
        | 7 | 10 | 2 | 9 | 11 | 21 | 3 |  -----> {can be sorted or unsorted.}
        --------------------------------

        Search '2' ----> In this array.
                        Element found WC complexity : O(n)

    => Some points about Linear search.

        1. Works on both sorder and unsorter Array.
        2. Equality operations.
        3. O(n) WC complexity.

*/

//LinearSearch Function is here.
int linearSearchFunction(int arr[], int size, int element){
    for(int i= 0; i<= size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int main(){
    printf("Linear Search in Data Structure with C++ programming\n");
    
    //Unsorted array of linear search.
    int arr[]= {1, 3, 5, 56, 4, 3, 23, 5, 54, 36, 34};
    int element= 23;
    int size= sizeof(arr)/sizeof(int);
    int searchIndex= linearSearchFunction(arr, size, element);
    if(searchIndex == -1){
        cout<<"Element not found in the Array."<<endl;
    }else{
        cout<<"The element "<<element<<" was found at index : "<<searchIndex<<endl;
    }

    
    //getch();
    return(0);
}