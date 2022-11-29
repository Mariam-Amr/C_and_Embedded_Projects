#include <stdio.h>
#include <stdlib.h>

int addition(int x, int y){
return (x+y);
}

int subtraction(int x, int y){
return (x-y);
}

int multiplication(int x, int y){
return (x*y);
}

int devesion(int x, int y){
if(y!= 0){
    return(x/y);
}else{
printf("You can't deveid by zero");
}
}

int AND(int x, int y){
return (x&y);
}

int OR(int x, int y){
return (x|y);
}

int NOT(int x){
return (!x);
}

int XOR(int x, int y){
return (x^y);
}

int reminder (int x, int y){
return (x%y);
}

 int increment(int x){
 return (++x);
 }

int decrement(int x){
return (--x);
}

int main()
{
    int op_id;
    int num1,num2;
printf("\n");
printf("\t\t\t-----------Welcome To ITI Calculator----------\t\t\t\n\n");
printf(" ID\t\tOperation\t\tNumber of Operands\n");
printf(" 1\t\t  Add\t\t\t       2\n");
printf(" 2\t\t  Subtract\t\t       2\n");
printf(" 3\t\t  Multiply\t\t       2\n");
printf(" 4\t\t  Devide\t\t       2\n");
printf(" 5\t\t  AND\t\t\t       2\n");
printf(" 6\t\t  OR\t\t\t       2\n");
printf(" 7\t\t  NOT\t\t\t       1\n");
printf(" 8\t\t  XOR\t\t\t       2\n");
printf(" 9\t\t  Reminder\t\t       2\n");
printf(" 10\t\t  Increment\t\t       1\n");
printf(" 11\t\t  Decrement\t\t       1\n");
printf("\n");
while(1){
printf("Please Choose The Operation ID Number : ");
scanf("%d",&op_id);
switch(op_id){
    case 1 ... 6: printf("This is 2 Operands Operation \n");
    printf("Enter First Operand : ");
    scanf("%d",&num1);
    printf("Enter Second Operand : ");
    scanf("%d",&num2);
    break;
    case 7:
    case 10:
    case 11: printf("This is one Operand Operation \n");
    printf("Enter The Operand : ");
    scanf("%d",&num1);
    break;
    case 8:
    case 9:  printf("This is 2 Operands Operation \n");
    printf("Enter First Operand : ");
    scanf("%d",&num1);
    printf("Enter Second Operand : ");
    scanf("%d",&num2);
    break;
    default: printf("Please Enter a valid Operation ID\n");
    break;
}
    int add=addition(num1,num2);
    int sub=subtraction(num1,num2);
    int mult=multiplication(num1,num2);
    double dev=devesion(num1,num2);
    int and=AND(num1,num2);
    int or=OR(num1,num2);
    int xor=XOR(num1,num2);
    int not=NOT(num1);
    int rem=reminder(num1,num2);
    int inc=increment(num1);
    int dec=decrement(num1);
switch(op_id){
    case 1 : printf("%d + %d= %d\n",num1,num2,add);
    break;
    case 2 : printf("%d - %d= %d\n",num1,num2,sub);
    break;
    case 3 : printf("%d * %d= %d\n",num1,num2,mult);
    break;
    case 4 : printf("%d / %d= %d\n",num1,num2,dev);
    break;
    case 5 : printf("%d & %d= %d\n",num1,num2,and);
    break;
    case 6 : printf("%d | %d= %d\n",num1,num2,or);
    break;
    case 7 : printf("%d ! = %d\n",num1,not);
    break;
    case 8 : printf("%d ^ %d= %d\n",num1,num2,xor);
    break;
    case 9 : printf("%d %% %d= %d\n",num1,num2,rem);
    break;
    case 10 : printf("%d ++ = %d\n",num1,inc);
    break;
    case 11 : printf("%d -- = %d\n",num1,dec);
    break;
}
}

    return 0;
}
