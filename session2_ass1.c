#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5];
    int x;
    int number;
    int i;
    for( x=1 ; x<=5 ; x++){
        printf("Please inter Number %d: ",x);
        scanf("%d",&arr[x]);
    }
    int found=0;
    printf("Enter a number to search for: ");
    scanf("%d",&number);

    for( i =0; i<=5 ;i++){
          if(arr[i]==number){
              found=1;
              break;
          }}
  if(found==1){
    printf("Number is exist at position %d ",i);
  }else{
    printf("Number is not exist");
  }
    return 0;
}
