#include <iostream>
using namespace std;
#define MAXSIZE 100
int q[MAXSIZE],f=-1,r=-1;
bool isEmpty(){
    return f==-1||f>r;
}
bool isFull(){
    return r==MAXSIZE-1;
}
void enqueue(int v){
    if(isFull()){
        cout<<"Queue full\n";
        return;
    }
    if(f==-1)f=0;
    q[++r]=v;
    cout<<v<<" added\n";
}
void dequeue(){
    if(isEmpty()){
        cout<<"Queue empty\n";
        return;
    }
    cout<<q[f++]<<" removed\n";
}
void display(){
    if(isEmpty()){
        cout<<"Queue empty\n";
        return;
    }
    cout<<"Queue:";
    for(int i=f;i<=r;i++)cout<<" "<<q[i];
    cout<<"\n";
}
void peek(){
    if(isEmpty()){
        cout<<"Queue empty\n";
        return;
    }
    cout<<"Front:"<<q[f]<<"\n";
}
int main(){
    int ch,v;
    do{
        cout<<"\n1.Enq 2.Deq 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\nChoice:";
        cin>>ch;
        switch(ch){
            case 1:cout<<"Val:";cin>>v;enqueue(v);break;
            case 2:dequeue();break;
            case 3:cout<<(isEmpty()?"Empty\n":"Not empty\n");break;
            case 4:cout<<(isFull()?"Full\n":"Not full\n");break;
            case 5:display();break;
            case 6:peek();break;
            case 7:cout<<"Bye\n";break;
            default:cout<<"Wrong\n";
        }
    }while(ch!=7);
    return 0;
}
