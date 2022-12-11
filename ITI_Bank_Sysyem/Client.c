#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <string.h>
#include "Admin.h"
#include "Client.h"
extern main_exit;
extern  i,j;
//----------function to Exit the whole system---------------
void close(void){

    printf("\n\n\n\t\tThis project was created by ITI student, Mariam Amr Zayed \n\n\n");
}

//----------function to delay till the next menu will appear----------------
void fordelay(long long int j){

int i,k;
    for(i=0;i<j;i++)
         k=i;
}

//-------------Client main menu-----------------

void Client_menu(void){
    int choice;
    system("cls");
    system("color 9");        //  9 light blue color
    printf("\n\n\t\t\t\t\tITI ACCOUNT BANKING SYSTEM");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB3 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Make Transaction\n\t\t2.Get Cash\n\t\t\n\t\t3.Cash Deposite\n\t\t\n\t\t4.Change Passward\n\n\n\n\n\t\t5.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:Client_Make_Transaction();
        break;
        case 2:Client_Get_Cash();
        break;
        case 3:Client_Deposit_in_Account();
        break;
        case 4:Client_Change_Account_Password();
        break;
        case 5:close();
        break;
        default: printf("Please Enter A valid chois!!");
        break;
    }
}

//-------client make transaction--------------------------
void Client_Make_Transaction(){
int choice,test=0;
    FILE *old,*newrec;
    old=fopen("Bank_Data_Base.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter Your Account ID:");
    scanf("%d",&transaction.account_id);
    while (fscanf(old,"%d %s %d %s %s %f %d/%d/%d",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.account_id==transaction.account_id)
            {   test=1;
                if(strcmp(add.account_staus,"closed")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN CLOSED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    Client_menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:EGP ");
                    scanf("%f",&transaction.amount_to_deposite);
                    add.amount_to_deposite+=transaction.amount_to_deposite;
                    fprintf(newrec,"%d %s %d %s %d %s %d %f %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:EGP ");
                    scanf("%f",&transaction.amount_to_deposite);
                    add.amount_to_deposite -=transaction.amount_to_deposite;
                    fprintf(newrec,"%d %s %d %s %d %s %d %f %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_id,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("Bank_Data_Base.dat");
   rename("new.dat","Bank_Data_Base.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        Client_Make_Transaction();
    else if (main_exit==1)
       Admin_menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
           Admin_menu();
        else
            close();
   }


}





