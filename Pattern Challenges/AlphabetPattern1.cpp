//Code a program to print First Alphabet pattern in C++ with Ritik.
/*
like this : A
            B B
            C C C
            D D D D
            E E E E E
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"First Alphabet Pattern in C++ programming\n";
    
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= i; j++){
            printf("%c ", (64+i));
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}