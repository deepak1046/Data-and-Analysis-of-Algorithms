//sum of squares of n natural numbers
#include <stdio.h>
int main(){
  int n,sum=0,i;
  printf("Enter the number to be stopped:");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    sum+=(i*i);
  }
  printf("The sum: %d\n",sum);
  return 0;
}
/*
SP of int=4+4+4
Space Complexity = O(1) because all INT variables n,sum,i are fixed and not dynamic
*/
