#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x=77;
  int y=66;
  int z=88;

  int* p=&x;
  int* q=&y;
  int* r=&z;
  printf("value of x : %d\n",x);
  printf("value of y : %d\n",y);
  printf("value of z : %d\n",z);
  printf("value of p : %d\n",p);
  printf("value of q : %d\n",q);
  printf("value of r : %d\n",r);
  printf("value of *p : %d\n",*p);
  printf("value of *q : %d\n",*q);
  printf("value of *r : %d\n\n",*r);

  printf("Swapping Pointers..\n\n");
  r=p;
  p=q;
  q=r;
  printf("value of x : %d\n",x);
  printf("value of y : %d\n",y);
  printf("value of z : %d\n",z);
  printf("value of p : %d\n",p);
  printf("value of q : %d\n",q);
  printf("value of r : %d\n",r);
  printf("value of *p : %d\n",*p);
  printf("value of *q : %d\n",*q);
  printf("value of *r : %d\n",*r);
    return 0;
}
