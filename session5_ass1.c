#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n=10;
    int arr[n];
    printf("Please Enter 10 values :\n");
    for (int i =0 ; i<n; i++){
        scanf("%d",&arr[i]);
    }

//sorting the array
int i, j, swap;
  for(i=0;i<n-1;i++){       // iteration for number of elements-1
	for(j=0;j<n-i-1;j++){    // the inner iteration
		if (arr[j]>arr[j+1]){
		  swap    =arr[j];
		  arr[j]  =arr[j+1];
		  arr[j+1]=swap;
		}
	}
}

int max=arr[0];
int min=arr[0];
for (int i =0; i<n; i++){
    if (arr[i]>max){
        max=arr[i];
    }
    if(arr[i]<min){
        min=arr[i];
    }

}
printf("Maximum Number is %d\n",max);
printf("Minimum Number is %d\n ",min);

    return 0;
}
