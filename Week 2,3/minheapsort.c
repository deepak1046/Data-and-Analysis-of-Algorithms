#include <stdio.h>
void heapify_min(int a[],int n,int i){
    int s=i,l=2*i+1,r=2*i+2,t;
    if(l<n&&a[l]<a[s])
        s=l;
    if(r<n&&a[r]<a[s])
        s=r;
    if(s!=i){
        t=a[i];
        a[i]=a[s];
        a[s]=t;
        heapify_min(a,n,s);
    }
}
void heapsort_min(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify_min(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int t=a[0];
        a[0]=a[i];
        a[i]=t;
        heapify_min(a,i,0);
    }
}
int main(){
    int a[]={4,1,3,2,0};
    int n=5;
    heapsort_min(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
