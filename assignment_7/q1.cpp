#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        int t=a[i]; a[i]=a[min]; a[min]=t;
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
}

void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[50], R[50];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partitionF(int a[], int low, int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            int t=a[i]; a[i]=a[j]; a[j]=t;
        }
    }
    int t=a[i+1]; a[i+1]=a[high]; a[high]=t;
    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int p=partitionF(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

void print(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++) cin>>arr[i];

    int a1[100],a2[100],a3[100],a4[100],a5[100];
    for(int i=0;i<n;i++){
        a1[i]=arr[i];
        a2[i]=arr[i];
        a3[i]=arr[i];
        a4[i]=arr[i];
        a5[i]=arr[i];
    }

    selectionSort(a1,n);
    insertionSort(a2,n);
    bubbleSort(a3,n);
    mergeSort(a4,0,n-1);
    quickSort(a5,0,n-1);

    print(a1,n);
    print(a2,n);
    print(a3,n);
    print(a4,n);
    print(a5,n);

    return 0;
}
