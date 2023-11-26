//Write a program to Print Reverse String a given string using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;

//Recusive Funtion to Print Reverse String a given string.
void recursiveFunctionToReverseAString(string str){
    if(str.length()== 0){ // Base case.
        return;
    }
    string ros= str.substr(1);
    recursiveFunctionToReverseAString(ros);
    cout<<str[0];
}

int main(){
    cout<<"Print Reverse String a given string using Recursive function in C++ programming\n";
    
    string str;
    cout<<"Enter a string here : ";
    getline(cin, str); //This line is used to read string with white space.

    recursiveFunctionToReverseAString(str);
    
    //getch();
    return(0);
}