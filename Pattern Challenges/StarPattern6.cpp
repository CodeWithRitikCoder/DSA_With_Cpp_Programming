//Code a program to print Sixth Star pattern in C++ with Ritik.
/*
like this : * * * * * * * * *
              * * * * * * *
                * * * * *
                  * * *
                    *
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"Sixth Star Pattern in C++ programming\n";
    
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= 10-i; j++){
            if(j>= i){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}