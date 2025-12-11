#include <stdio.h>
void heapify_max(int a[],int n,int i){
    int l=2*i+1,r=2*i+2,m=i,t;
    if(l<n&&a[l]>a[m])
        m=l;
    if(r<n&&a[r]>a[m])
        m=r;
    if(m!=i){
        t=a[i];
        a[i]=a[m];
        a[m]=t;
        heapify_max(a,n,m);
    }
}
void heapsort_max(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify_max(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int t=a[0];
        a[0]=a[i];
        a[i]=t;
        heapify_max(a,i,0);
    }
}
int main(){
    int a[]={4,1,3,2,0};
    int n=5;
    heapsort_max(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}