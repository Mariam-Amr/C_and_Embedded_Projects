#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i,space=0;
    for(int i=1; i<=5; ++i ,x=0){
        for( space=1 ;space<=5-i ;++space){
            printf(" ");
    }
    while(x !=2 * i-1){
        printf("*");
        ++x;
    }
    printf("\n");
    }



    return 0;
}
