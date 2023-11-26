//Write a program to Move all x to the end of the string using Recursive function. with Ritik.
#include"iostream"
#include"conio.h"
using namespace std;
int count= 1;

//Recusive Funtion to Move all x to the end of the string.
string recursiveFunctionToMoveXatTheEndOfTheString(string str){
    if(str.length() == 0){
        return "";
    }
    char ch= str[0];
    string ans= recursiveFunctionToMoveXatTheEndOfTheString(str.substr(1));

    if(ch == 'x'){
        return ans+ ch;
    }
    return (ch+ ans);
}

int main(){
    cout<<"Move all x to the end of the string using Recursive function in C++ programming\n";
    
    string str; //like this :- "axxbcdxfdxhixgxhx"
    cout<<"Enter your string here : ";
    getline(cin, str);

    string stringAfterMoveX_AtTheEndOfTheString= recursiveFunctionToMoveXatTheEndOfTheString(str);
    cout<<"Now your string is : "<<stringAfterMoveX_AtTheEndOfTheString;
    
    //getch();
    return(0);
}