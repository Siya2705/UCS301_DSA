
#include <iostream>
using namespace std;
#define maxlen 100
typedef struct{
	int element[maxlen];
	int top;
}stack;
stack init(){

	stack S;
	S.top=-1;
	return S;
}
int isEmpty(stack S){
	return(S.top==-1);
	
}
int isFull(stack S){
	return(S.top==maxlen-1);
}
int top(stack S){
	if (isEmpty(S)){
		cout<<"Empty stack"<<endl;
		
	}
	if (isFull(S)){
		return S.element[S.top];
	}
}
stack push(stack S,int x){
	if (isFull(S)){
		cout<<"Stack overflow"<<endl;
		
	}
	else{
		++S.top;
		S.element[S.top]=x;
	}
	return S;
}
stack pop(stack S){
	if (isEmpty(S)){
		cout<<"Stack underflow"<<endl;
		
	}
	else{
		--S.top;
	}
	return S;
}
void print(stack S){
	int i;
	for (i=S.top;i>=0;i--){
		cout<<S.element[i]<<endl;
	}
}
int main(){
	stack S=init();
	int choice=0;
	int value;
	cout<<"Enter choice:1.Push 2.Pop 3.Empty 4.Full 5.Display 6.Peek 7.Exit"<<endl;

	while (choice!=7){
		cout<<"Enter your choice:"<<endl;
		cin>>choice;
		if (choice==1){
			cout<<"Enter element to be pushed:"<<endl;
			cin>>value;
			S=push(S,value);
			
		}
		if(choice==2){
			S=pop(S);
		}
		if (choice==3){
			isEmpty(S);
			
		}
		if (choice==4){
			isFull(S);
		}
		if (choice==5){
			print(S);
		}
		if (choice==6){
			value=top(S);
			if (value!=1){
				cout<<"Top element is:"<<value<<endl;
			}
		}
	}
	
}
