#include <stdio.h>
#include <stdlib.h>

int main()
{
   int ID_list[6]={123,456,789,147,258,369};
   int local_password=175284;
   int pass;
   int ID;
   int ID_found=0;
    printf("Enter your ID :");
    scanf("%d",&ID);
   for(int i=0; i<=6 ; i++){
    if(ID_list[i]==ID){
      ID_found=1;
       break;
    }
   }
   if(ID_found==1){
    printf("Valid ID\n");
   }else{
   printf("This is not a Valid ID\n ");

   }

   printf("Enter Your Password Please \n");
   scanf("%d",&pass);
   if (pass == local_password){
    switch(ID){
    case(123): printf("Welcome Ahmed !! \n"); break;
    case(456): printf("Welcome Mohamed!! \n"); break;
    case(789): printf("Welcome Ali !! \n"); break;
    case(147): printf("Welcome Amr !! \n"); break;
    case(258): printf("Welcome Youssef !! \n"); break;
    case(369): printf("Welcome Ibrahim !! \n"); break;
    }
   }else{
   printf("You Interred a wrong Password");
   }
    return 0;
}

