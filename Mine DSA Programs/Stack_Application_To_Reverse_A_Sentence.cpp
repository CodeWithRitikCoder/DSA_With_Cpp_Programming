//Write a program to ------------ with Ritik.
#include"iostream"
#include"conio.h"
#include"stack"
using namespace std;
void reverseSentenceFunction(string);

void reverseSentenceFunction(string s){
    stack<string> strTemp;
    for(int i= 0; i< s.length(); i++){
        string word= "";
        while(s[i] != ' ' && i<s.length()){
            word+= s[i];
            i++;
        }
        strTemp.push(word);
    }

    while(!strTemp.empty()){
        cout<<strTemp.top()<<" ";
        strTemp.pop();
    }cout<<endl;
}

int main(){
    cout<<"Stack Application to Reverse a Sentence in C++ programming\n"<<endl;

    string str= "Hey, How are you doing?";
    cout<<str<<endl;
    
    reverseSentenceFunction(str);
    
    //getch();
    return(0);
}