//fibonacci series
#include <stdio.h>
int main(){
  int a=0,b=1,c,n,i;
  printf("Enter the number in series:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("%d ",a);
    c=b;
    b=a;
    a+=c;
  }
  printf("\n");
  return 0;
}
/*
SP of int=4+4+4+4+4
Space Complexity = O(1) because all INT variables a,b,c,n,i are fixed and not dynamic
*/
