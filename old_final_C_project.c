
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>//this to include file,color and cls functions to make the application easy to use


// this is bank account system that contains Admin and client windows
//each has it's owen menu and options
// ADMIN Password is iti
int i,j;                       //counters in loops over the code (to be global)
int main_exit;                 //variable to exite the main menu

struct date{                  // struct to define the date important while enquiring about
    int month;                //deposits ,withdraw or transaction dates
    int day;
    int year;
};

struct {                 // the different information in any account

    char   name[60];
    char   address[100];
    char   national_id[14];
    char   account_id[6];
    int    age;
    float  amount_to_deposite;
    char   gardian_national_id[14];       // if age is less than 21
    char   account_staus[10];            //active is default
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;     //objects from struct


void fordelay(int j){         //delay function  wait till the next menu will appear
   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


void Admin_menu(void){          //admain menu
    int choice;
    system("cls");
    system("color 9");        //  9 light blue color
    printf("\n\n\t\t\t\t\tITI ACCOUNT BANKING SYSTEM");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB3 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;/*
        case 5:erase();
        break;
*/
        case 6:view_list();
        break;

        case 7:close();
        break;

    }
}

void close(void){          // to close the whole project

    printf("\n\n\n\t\tThis project was created by ITI student, Mariam Amr Zayed \n\n\n");
}

//---------------------creat new account

void new_acc(){      //function to creat new account(only available for admain mode)
    int choice;
    FILE *ptr;

    ptr=fopen("Bank_Data_Base.dat","a+"); //add and creat a file to save all data in
    account_no:
    system("cls");
    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2 ADD RECORD \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    //save the date to deposits
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter Account ID:");
    scanf("%d",&check.account_id);
    while(fscanf(ptr,"%d %s %d %s %d %s %f %d/%d/%d\n",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.account_id==add.account_id)
            {printf("Account No. Already Exist!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.account_id == check.account_id;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the age: ");
    scanf("%d",&add.age);
    printf("\nEnter the address: ");
    scanf("%s",add.address);
    printf("\nEnter 14 National ID Number : ");
    scanf("%s",&add.national_id);
    printf("\nEnter the amount to deposit: EGP");
    scanf("%f",&add.amount_to_deposite);
    printf("\nType of account:\n\t#ACTIVE\n\t#CLOSED\n\t#RESTRICTED\tEnter your choice:");
    scanf("%s",add.account_staus);

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


void view_list(){              //view list

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

void see(void) {     //Check the details of existing account

    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("Bank_Data_Base.dat","r");
    printf("Do you want to check account by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.account_id);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.account_id==check.account_id)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s\nAge:%d \nAddress:%s \nNational ID :%s\nAccount Staus:%s \nAmount deposited:$ EGP .2f \nDate Of Deposit:%d/%d/%d\n\n",add.account_id,add.name,add.age,add.address,add.national_id,
                add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.account_staus,"active")==0)
                    {
                         printf("\n\nThis Account is Active on %d/%d/%d",add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.account_staus,"closed")==0)
                    {

                        printf("\n\nThis Account was Closes on %d/%d/%d",add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
            }

            }
            }

    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s\nAge:%d \nAddress:%s \nNational ID :%s\nAccount Status:%s \nAmount deposited:EGP %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.account_id,add.name,add.age,add.address,add.national_id,
                add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.account_staus,"active")==0)
                    {
                         printf("\n\nYou will get EGP as interest on %d/%d/%d",add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmpi(add.account_staus,"passive")==0)
                    {

                        printf("\n\nYou will get $EGP as interest on %d/%d/%d",add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
            }
        }
    }

    fclose(ptr);
     if(test!=1)
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
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            Admin_menu();
        }

        else
           {

             system("cls");
            close();
            }

}

//----------------------------make transactions
void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("Bank_Data_Base.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the Account ID  of the Client:");
    scanf("%d",&transaction.account_id);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
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

}

//---------------------------- edit the information
void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("Bank_Data_Base.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.account_id);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.account_id,add.name,&add.age,add.address,add.national_id,add.account_staus,&add.amount_to_deposite,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.account_id==upd.account_id)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Account Status\n2.Name\n\nEnter your choice(1 for Account Status and 2 for Name):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new Account Status:");
                scanf("%s",upd.account_staus);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_id,add.name,add.age,upd.account_staus,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
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
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.account_id,add.name,add.age,add.address,add.national_id,add.account_staus,add.amount_to_deposite,add.deposit.month,add.deposit.day,add.deposit.year);
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

void client_menu(){          //customer menu





}

// main function and user interface
//-------------------------------------------------------------------------//main
    int main(){

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
           client_menu();
        }

return 0;
}
