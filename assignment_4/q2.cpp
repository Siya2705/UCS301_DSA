#include <iostream>
using namespace std;
#define MAXSIZE 5
int cq[MAXSIZE],front=-1,rear=-1;
bool isEmpty(){
    return front==-1;
}
bool isFull(){
    return (rear+1)%MAXSIZE==front;
}
void enqueue(int v){
    if(isFull()){
        cout<<"Full\n";
        return;
    }
    if(isEmpty())front=0;
    rear=(rear+1)%MAXSIZE;
    cq[rear]=v;
    cout<<v<<" added\n";
}
void dequeue(){
    if(isEmpty()){
        cout<<"Empty\n";
        return;
    }
    cout<<cq[front]<<" removed\n";
    if(front==rear)front=rear=-1;
    else front=(front+1)%MAXSIZE;
}
void display(){
    if(isEmpty()){
        cout<<"Empty\n";
        return;
    }
    cout<<"Queue:";
    int i=front;
    while(true){
        cout<<" "<<cq[i];
        if(i==rear)break;
        i=(i+1)%MAXSIZE;
    }
    cout<<"\n";
}
void peek(){
    if(isEmpty()){
        cout<<"Empty\n";
        return;
    }
    cout<<"Front:"<<cq[front]<<"\n";
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
