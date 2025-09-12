#include <iostream>
using namespace std;
int main(){
	int arr[5]={1,2,3,4,5};
	int n=5;
	int i;
	for(i=0;i<n/2;i++){
		swap(arr[i],arr[n-i-1]);
	}
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
