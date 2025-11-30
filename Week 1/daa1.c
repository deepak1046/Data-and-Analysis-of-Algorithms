//sum of n natural numbers
#include <stdio.h>
int n_sum(int n){
  int sum=0,i;
  for(i=1;i<=n;i++){
    sum+=i;
  }
  printf("The sum: %d\n",sum);
  return 0;
}
int main(){
  int n;
  printf("Enter the number to be stopped:");
  scanf("%d",&n);
  n_sum(n);
  return 0;
}
/*
SP for int = 4+4+4 bytes
Space complexity= O(1) because all INT variables n,sum,i are fixed and not dynamic
*/ 