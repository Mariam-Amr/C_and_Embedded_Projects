#include <stdio.h>
#include <stdlib.h>
#include "Admin.h"
#include "Client.h"
#include<windows.h>


/*----- this is  a bank account system that contains Admin and client windows
*each has it's own menu and options
*/
//-------some global variables used by the other included files----------------
int i,j,k;                       //counters in loops over the code (to be global)
int main_exit;                 //variable to exite the main menu






//--------------------- main function and user interface---------------------------


int main(){
system("color 9");
    int choise;
    system("color 9");                 // 6 yellow 9 light blue 2 green
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ITI ACCOUNT BANKING SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t 1-Admin Window\n\t\t 2-Client Window\n");
    printf("\t\t Enter Your Choise...");
    scanf("%d",&choise);

            for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
    system("cls");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB3 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    if (choise==1){

    char pass[10],password[10]="iti";
    int i=0;
    printf("\n\n\tHello Admin..Enter Password To Login : ");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {
            printf("\n\nPassword Match!\n LOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);    // delay with micro sec
            printf(".");
        }
           system("cls");
           Admin_menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\n Enter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();
                    }
            else
                    {
                        printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;
                    }

        }
    }
    if(choise==2){
    printf("\n\n\tHello Client..What We Can Offer for you.. : ");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);    // delay with micro sec
            printf(".");
        }
           system("cls");
     printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB3 WELCOME TO ITI Bank Account System, Client Window \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
          Client_menu();
        }

return 0;
}
