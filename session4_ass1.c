#include <stdio.h>
#include <stdlib.h>

int max(int x,int y,int z,int n){
if ((x>y)&(x>z)&(x>n) ){
    return x;
}else if((y>x)&(y>z)&(y>n) ){
   return y;
}else if ((z>x)&(z>y)&(z>n) ){
   return z;
}else{
return n;
}
}

int min(int x,int y,int z,int n){
if ((x<y)&(x<z)&(x<n) ){
    return x;
}else if((y<x)&(y<z)&(y<n) ){
   return y;
}else if ((z<x)&(z<y)&(z<n) ){
   return z;
}else{
return n;
}
}


int main()
{
int num1,num2,num3,num4;
printf("Please Enter 1st Number ");
scanf("%d",&num1);
printf("Please Enter 2nd Number ");
scanf("%d",&num2);
printf("Please Enter 3rd Number ");
scanf("%d",&num3);
printf("Please Enter 4th Number ");
scanf("%d",&num4);

int maxi= max(num1,num2,num3,num4);
printf("Max Number is %d\n",maxi);

int mini= min(num1,num2,num3,num4);
printf("Minimum Number is %d\n",mini);
    return 0;
}
