#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

  typedef struct date{                  // struct to define the date important while enquiring about
    int month;                         //deposits ,withdraw or transaction dates
    int day;
    int year;
};

 typedef enum { Active, Restricted,Closed } Status;
 typedef struct {                 // the different information in any account

    char   name[60];
    char   address[100];
    char   national_id[14];
    int    account_id[6];
    int    age;
    char   password[5];
    float  amount_to_deposite;
    char   gardian_national_id[14];       // if age is less than 21
    struct date deposit;
    struct date withdraw;
    Status account_staus ;   //active is default
    }add,upd,check,rem,transaction,deposite;     //objects from struct

//----------Admin resbonsibilities-------------

void Admin_menu(void);
void Create_New_Account();
void Open_An_Existing_Account();
void Make_Transaction();
void Change_Account_Status();
void Get_Cash();
void Deposit_in_Account();
void Randum_Password_Generation();
void view_list();
void fordelay(long long int j);        //delay function  wait till the next menu will appear
void close(void);

#endif // ADMIN_H_INCLUDED
