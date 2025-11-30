//transpose of 3x3 matrix
#include <stdio.h>
int main(){
  int mat[3][3],tmat[3][3],i,j;
  printf("Enter the values of matrix:\n");
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      scanf("%d",&mat[i][j]);
    }
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      tmat[i][j]=mat[j][i];
    }
  }
  printf("---------Normal Matrix----------\n");
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("%d ",mat[i][j]);
    }
    printf("\n");
  }
  printf("---------Transposed Matrix----------\n");
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("%d ",tmat[i][j]);
    }
    printf("\n");
  }
  return 0;
}
/*
SP of int=36+36+4+4
Space Complexity = O(1) because all INT variables mat,tmat,i,j are fixed and not dynamic
*/
