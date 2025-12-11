#include <stdio.h>
#include <stdlib.h>
void bucket_sort(int a[],int n){
    int i,j,k,max=a[0];
    for(i=1;i<n;i++) 
        if(a[i]>max) 
            max=a[i];
    int bcount=max+1;
    int *b=calloc(bcount,sizeof(int));
    for(i=0;i<n;i++) 
        b[a[i]]++;
        k=0;
    for(i=0;i<bcount;i++){
        for(j=0;j<b[i];j++){
            a[k++]=i;
        }
    }
    free(b);
}
int main(){
    int a[]={4,1,3,4,2,0,1};
    int n=sizeof(a)/sizeof(a[0]);
    bucket_sort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}