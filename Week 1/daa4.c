//factorial using recursion
#include <stdio.h>
int fact(int n){
  if(n==0){
    return 1;
  }else{
    return n*fact(n-1);
  }
}
int main(){
  int n,sum=0,i;
  printf("Enter the number to be stopped:");
  scanf("%d",&n);
  printf("The factorial of %d is: %d\n",n,fact(n));
  return 0;
}
/*
SP of int=n*O(1)
Space Complexity = O(n) because all function fact(n) is going on recursively 'n' times
*/
    
