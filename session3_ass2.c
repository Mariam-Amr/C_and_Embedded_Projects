#include <stdio.h>
#include <stdlib.h>

int main()
{
   int ID_list[3]={1234,5678,9870};
   int pass;
   int ID;
   int ID_found=0;
    printf("Enter your ID :");
    scanf("%d",&ID);
   for(int i=0; i<=3 ; i++){
   if(ID_list[i]==ID){
      ID_found=1;
       break;
    }
   }
   if(ID_found==1){
   printf("Your Are Registered \n");
   }else{
   printf("You Are Not Registered\n ");
   }

   printf("Enter Your Password Please \n");
   scanf("%d",&pass);

    switch(pass){
    case(7788): printf("Welcome Ahmed !! \n"); break;
    case(5566): printf("Welcome Amr!!    \n"); break;
    case(1122): printf("Welcome wael !!  \n"); break;
    }
    if(pass!= pass){
    printf("Try again\n");
    scanf("%d",&pass);
    }
    return 0;
}
