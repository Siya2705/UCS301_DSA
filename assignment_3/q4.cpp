#include <iostream>
#include <string>
using namespace std;
#define MAXLEN 100
char stackArr[MAXLEN];
int top=-1;
void push(char c){
    if(top<MAXLEN-1){
        stackArr[++top]=c;
    }
}
char pop(){
    if(top>=0){
        return stackArr[top--];
    }
    return '\0';
}
char peek(){
    if(top>=0){
        return stackArr[top];
    }
    return '\0';
}
bool isEmpty(){
    return top==-1;
}
int precedence(char op){
    if(op=='+'||op=='-')return 1;
    if(op=='*'||op=='/')return 2;
    return 0;
}
bool isOperator(char c){
    return c=='+'||c=='-'||c=='*'||c=='/';
}
string infixToPostfix(string infix){
    string postfix="";
    top=-1;
    for(int i=0;i<(int)infix.length();i++){
        char c=infix[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            postfix+=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(!isEmpty()&&peek()!='('){
                postfix+=pop();
            }
            if(!isEmpty())pop();
        }
        else if(isOperator(c)){
            while(!isEmpty()&&precedence(peek())>=precedence(c)){
                postfix+=pop();
            }
            push(c);
        }
    }
    while(!isEmpty()){
        postfix+=pop();
    }
    return postfix;
}
int main(){
    string infixExp;
    cout<<"Enter Infix expression:";
    getline(cin,infixExp);
    string postfixExp=infixToPostfix(infixExp);
    cout<<"Postfix expression:"<<postfixExp<<endl;
    return 0;
}
