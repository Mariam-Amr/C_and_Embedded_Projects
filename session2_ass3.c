#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3;
    printf("Please Enter 1st Number :");
    scanf("%d",&num1);
    printf("Please Enter 2nd Number :");
    scanf("%d",&num2);
    printf("Please Enter 3rd Number :");
    scanf("%d",&num3);
(num1>num2 && num1>num3)?(printf("%d this is the Max Number",num1)):\
(num2>num1 && num2>num3)?(printf("%d this is the Max Number",num2)):\
(printf("%d this is the Max Number",num3));

    return 0;
}
