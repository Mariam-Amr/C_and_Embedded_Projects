#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <string.h>
#include "Admin.h"
#include "Client.h"

//-------------Client main menu-----------------

void Client_menu(void){
    int choice;
    system("cls");
    system("color 9");        //  9 light blue color
    printf("\n\n\t\t\t\t\tITI ACCOUNT BANKING SYSTEM");
    printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB3 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Make Transaction\n\t\t2.Get Cash\n\t\t\n\t\t3.Cash Deposite\n\t\t\n\t\t4.Change Passward\n\n\n\n\n\t\t5.Return to main menue\n\n\n\n\n\t\t6. Enter your choice:");
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
        case 5; Client_menu();
        break;
        case 6:close();
        break;
        default: printf("Please Enter A valid chois!!");
        break;
    }
}

//-------client make transaction--------------------------
Client_Make_Transaction(){




}
