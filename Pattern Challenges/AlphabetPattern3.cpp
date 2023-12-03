//Code a program to print Third Alphabet pattern in C++ with Ritik.
/*
like this : A
            A B
            A B C
            A B C D
            A B C D E
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"Third Alphabet Pattern in C++ programming\n";
    
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= i; j++){
            printf("%c ", (64+j));
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}