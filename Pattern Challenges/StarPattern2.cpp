//Code a program to print Second Star pattern in C++ with Ritik.
/*
like this : * * * * *
              * * * *
                * * *
                  * *
                    *
*/
#include"iostream"
#include"conio.h"
using namespace std;
int main(){
    cout<<"Second Star Pattern in C++ programming\n";
    
    for(int i= 1; i<= 5; i++){
        for(int j= 1; j<= 5; j++){
            if(i-1 >= j){
                cout<<"  ";
            }else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
    
    //getch();
    return(0);
}