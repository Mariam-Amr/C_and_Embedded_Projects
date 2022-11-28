#include <stdio.h>
#include <stdlib.h>
int main(){
int num1,num2,add,sub,and,or,xor;

  printf("Please Enter Number 1 : ");
  scanf("%d",&num1);
  printf("Please Enter Number 2 : ");
  scanf("%d",&num2);

  add= num1 + num2;
  sub= num1 - num2;
  and= num1 & num2;
  or = num1 | num2;
  xor= num1 ^ num2;
  printf("Number 1 + Number 2 =%d\n",add);
  printf("Number 1 - Number 2 =%d\n",sub);
  printf("Number 1 & Number 2 =%d\n",and);
  printf("Number 1 | Number 2 =%d\n",or);
  printf("Number 1 ^ Number 2 =%d\n",xor);
    return 0;
}
