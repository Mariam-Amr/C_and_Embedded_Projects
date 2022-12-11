#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <string.h>
#include "Admin.h"
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

//--------------------Admin Menu-------------------------------
void Admin_menu(void){
    int choice;
    system("cls");
    system("color 9");        //  9 light blue color
    printf("\n\n\t\t\t\t\tITI ACCOUNT BANKING SYSTEM");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB3 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new Account\n\t\t2.Open An Existing Account\n\t\t\n\t\t3.View Clients Data \n\t\t\n\t\t4.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:Create_New_Account();
        break;
        case 2:Open_An_Existing_Account();
        break;
        case 3:view_list();
        break;
        case 4:close();
        break;
        default: printf("Please Enter A valid chois!!");
        break;
    }
}

 //----------function to create New Account--------------------
void Create_New_Account(){
    int choice;
    FILE *ptr;

    ptr=fopen("Bank_Data_Base.dat","a+"); //add and creat a file to save all data in
    account_no:
    system("cls");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2 ADD RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    //save the date to deposits
    scanf("%d%d%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter Account ID:");
    scanf("%d",&check.account_id);
    while(fscanf(ptr,"%d %s %d %s %d %s %f %d%d%d\n",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.account_id==add.account_id)
            {printf("Account No. Already Exist!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.account_id = check.account_id;
    printf("\nEnter the name:");
    scanf("%s",&add.name);
 //-------make sure user enter his full name----------------
   /* int counter=0;
    for (int i = 0; i <strlen(name) ; i++)
    {
        int counter=0;
        if (name[i] == ' ')
        {
            counter++;
        }
    }
    if (counter >= 3)
    {
        return 1;
    }
    puts("!!! You need to  enter your first 4 names as in your National ID Card");
    return 0;*/

    printf("\nEnter the age: ");
    scanf("%d",&add.age);
 //--------------if user age less then 18-----------
    if (add.age<=18){
     printf("\nEnter the Gurdian National ID: ");
     scanf("%d",&add.gardian_national_id);
//--------------make sure user enter the full 14 digits id number-------------
         if (strlen(add.gardian_national_id) != 14)
    {
puts("!!!You need to enter  a 14 digits for the National ID Number");
       close();
    }

}else
    {
    printf("\nEnter the address: ");
    scanf("%s",add.address);
    printf("\nEnter 14 National ID Number : ");
    scanf("%s",&add.national_id);

////------test1------
//--------------make sure user enter the full 14 digits id number-------------

    if (strlen(national_id) == 14)
    {
  puts("!!!You need to enter  a 14 digits for the National ID Number");
       close();
    }


}
    printf("\nEnter the amount to deposit: EGP");
    scanf("%f",&add.amount_to_deposite);
    printf("\nType of account:\n\t#ACTIVE\n\t#CLOSED\n\t#RESTRICTED\tEnter your choice:");
    scanf("%s",&add.account_staus);
    fprintf(ptr,"%d %s %d %s %d %s %f %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
    fclose(ptr);
    printf("\nAccount created successfully!");

    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        Admin_menu();

    else if(main_exit==0)
        close();



 else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

 //-----------------function to open existing account with sub-menus---------------------
 void Open_An_Existing_Account(){
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("Bank_Data_Base.dat","r");
    printf("Check account by\n1.Account no.\n:");
    printf("Enter the account number:");
    scanf("%d",&check.account_id);

        while (fscanf(ptr,"%d %s %d %s %d %s %lf  %d/%d/%d",&add.account_id,add.name,add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
{
            if(add.account_id==check.account_id)
{
                system("cls");
                test=1;               // account found

                printf("\nAccount NO.:%d\nName:%s\nAge:%d\nAddress:%s \nNational ID :%s\nAccount Staus:%s \nAmount deposited:$ EGP .2f \nDate Of Deposit:%d/%d/%d\n\n",add.account_id,add.name,add.age,add.address,add.national_id,
                add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\t\t\tAdmin..What actions do you wish to make:?\n");
                printf("\t\t 1-Make a Transaction.\n");
                printf("\t\t 2-Change Account status.\n");
                printf("\t\t 3-Get Cash.\n");
                printf("\t\t 4-Deposit in Account.\n");

                scanf("%d",&choice);
switch(choice)
{
        case 1:Make_Transaction();
        break;
        case 2:Change_Account_Status();
        break;
        case 3:Get_Cash();
        break;
        case 4:Deposit_in_Account();
    }

            }

fclose(ptr);
     if(test!=1)           // account was not found
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    Admin_menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    Open_An_Existing_Account();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
 }
 }

//-------------------------make transaction function------------------
 void Make_Transaction(){
 int choice,test=0;
    FILE *old,*newrec;
    old=fopen("Bank_Data_Base.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the Account ID  of the Client:");
    scanf("%d",&transaction.account_id);
    while (fscanf(old,"%d %s %d %s %d %s %lf %d/%d/%d",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.account_id==transaction.account_id)
            {   test=1;
                if(strcmpi(add.account_staus,"closed")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN CLOSED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    Admin_menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:EGP ");
                    scanf("%f",&transaction.amount_to_deposite);
                    add.amount_to_deposite+=transaction.amount_to_deposite;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:EGP ");
                    scanf("%f",&transaction.amount_to_deposite);
                    add.amount_to_deposite-=transaction.amount_to_deposite;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_id,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
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
        transact();
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
     else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
          Admin_menu();
        else
            close();
        }

}

//---------------------------change account status function ----------------
void Change_Account_Status(){
 int choice,test=0;
    FILE *old,*newrec;
    old=fopen("Bank_Data_Base.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.account_id);
    while(fscanf(old,"%d %s %d %s %d %s %d %d/%d/%d",&add.account_id,add.name,&add.age,add.address,add.national_id,&add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.account_id==upd.account_id)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Account Status\n2.Name\n\nEnter your choice(1 for Account Status and 2 for Name):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new Account Status:");
                scanf("%s",upd.account_staus);
                fprintf(newrec,"%d %s %d %d %s %lf %d/%d/%d\n",add.account_id,add.name,add.age,upd.account_staus,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new Name:");
                scanf("%lf",&upd.name);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_id,upd.name,add.age,add.address,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
        fprintf(newrec,"%d %s %d %d %s %lf %d/%d/%d\n",add.account_id,add.name,add.age,upd.account_staus,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);

    }
    fclose(old);
    fclose(newrec);
    remove("Bank_Data_Base.dat");
    rename("new.dat","Bank_Data_Base.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    Admin_menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
          Admin_menu();
        else
            close();
        }
}


//-----------------------------deposit in account function------------------
void Deposit_in_Account(){
     int choice,test=0;
    FILE *old,*newrec;
    old=fopen("Bank_Data_Base.dat","r");
    newrec=fopen("new.dat","w");
    printf("\n\t\t\tEnter Account ID : ");
    scanf("%s",&account_id);

     while(fscanf(old,"%d %s %d %s %d %s %d %d/%d/%d",&add.account_id,add.name,&add.age,add.address,add.national_id,&add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)

    {
     printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice:");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:EGP ");
                    scanf("%f",&transaction.amount_to_deposite);
                    add.amount_to_deposite+=transaction.amount_to_deposite;
                    fprintf(newrec,"%d %s %d %d %s %lf  %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else if(choice==2)
                {
                    printf("Enter the amount you want to withdraw:EGP ");
                    scanf("%f",&transaction.amount_to_deposite);
                    add.amount_to_deposite-=transaction.amount_to_deposite;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_id,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }else{

       fprintf(newrec,"%d %s %d %d %s %lf %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_staus,upd.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                }
        }


    fclose(old);
    fclose(newrec);
}

//------------------------view the database of the bank--------------------------

void view_list(){

    FILE *view;
    view=fopen("Bank_Data_Base.dat","r");  //read from data file that is already created
    int test=0;
    system("cls");
    printf("\nACC. NO.\t\tNAME\t\t\tADDRESS\t\t\tAge\t\t\tNational ID\n");

    while(fscanf(view,"%d %s %d %s %d %s %f %d/%d/%d\n",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t\t%12s\t\t%10s\t\t%14d\n",add.account_id,add.name,add.address,add.national_id);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            Admin_menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}


//-------------------------------random password generation function----------------------------
void Randum_Password_Generation(){

	char password[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$^&*()_- +=QWERTYUIOPASDFGHJKLZXCVBNM':\"<>,.?";

	srand(time(NULL));
	for(u8 i = 0; i < 9; i++)
	{
		printf("%c", password[rand() % (sizeof password - 1)]);
	}
}

