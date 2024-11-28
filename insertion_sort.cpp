#include<iostream>
using namespace std;

void insertion_sort(int a[], int n){
    int count=0;
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
            count++;
        }
        a[j+1]=temp;
    }
    cout<<"count:"<<count<<endl;
}

// even index decreasing and odd index increasing
void my_sort(int a[],int n)
{
     for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-2;
        if(i%2){  //odd index
             while(j>=0 && a[j]>temp){
            a[j+2]=a[j];
            j-=2;
           }
         a[j+2]=temp;
        }
        else{
             while(j>=0 && a[j]<temp){
               a[j+2]=a[j];
               j-=2;
             }
         a[j+2]=temp;
        }
       
    }
}

int main()
{
   int n;
   cout<<"enter the number of element: ";
   cin>>n;

   int a[n];
   cout<<"enter the element: ";
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int arr_size=sizeof(a)/sizeof(a[0]);

    insertion_sort(a,arr_size);
    cout<<"sorted array: "<<endl;

    for(int i=0;i<arr_size;i++){
    cout<<a[i]<<" ";
   }

   my_sort(a,arr_size);
   cout<<endl;
   cout<<"even index decreasing and odd index increasing: "<<endl;
   for(int i=0;i<arr_size;i++){
    cout<<a[i]<<" ";
   }
}