#include <stdio.h>
#include <stdlib.h>

void func(int *ptr){
  int i, j, swap;
  int n=5;
  for(i=0;i<n-1;i++){
	for(j=0;j<n-i-1;j++){
		if (ptr[j]>ptr[j+1]){
		  swap    =ptr[j];
		  ptr[j]  =ptr[j+1];
		  ptr[j+1]=swap;
		}	}}
for(int i=0; i<5; i++){
  printf("%d\n",ptr[i]);
}
}

int main()
{
    int arr[5];
    printf("Enter Your 5 Elements to be Sorted...\n");
    for (int i =0; i<5; i++){
        scanf("%d",&arr[i]);
    }
 printf("Your sorted Elements are...\n");
 func(arr);
    return 0;
}
