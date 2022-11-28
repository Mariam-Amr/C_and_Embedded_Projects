#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hight;
    printf("Please Inter the Hight of the Pyramid !!");
    scanf("%d",&hight);
    int x,space=0;
    for(int i=1; i<=hight; ++i ,x=0){
        for( space=1 ;space<=hight-i ;++space){
            printf(" ");
    }
    while(x !=2 * i-1){
        printf("*");
        x++;

    }
    printf("\n");
    }
return 0;
}
