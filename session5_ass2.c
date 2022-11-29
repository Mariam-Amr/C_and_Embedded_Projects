#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n=4;
   int class_1[n];
   int class_2[n];
   int class_3[n];
   int total_grade=100;
   int passing_grade=50;

    printf("Please Enter Class 1 Grads :\n");
    for (int i =0 ; i<n; i++){
        scanf("%d",&class_1[i]);
    }

    printf("Please Enter Class 2 Grads :\n");
    for (int i =0 ; i<n; i++){
        scanf("%d",&class_2[i]);
    }

    printf("Please Enter Class 3 Grads :\n");
    for (int i =0 ; i<n; i++){
        scanf("%d",&class_3[i]);
    }
//sorting class 1
    int i, j, swap;
  for(i=0;i<n-1;i++){
	for(j=0;j<n-i-1;j++){
		if (class_1[j]>class_1[j+1]){
		  swap    =class_1[j];
		  class_1[j]  =class_1[j+1];
		  class_1[j+1]=swap;
		}
	}
}
//sorting class2

  for(i=0;i<n-1;i++){
	for(j=0;j<n-i-1;j++){
		if (class_2[j]>class_2[j+1]){
		  swap    =class_2[j];
		  class_2[j]  =class_2[j+1];
		  class_2[j+1]=swap;
		}
	}
}
//sorting class3

  for(i=0;i<n-1;i++){
	for(j=0;j<n-i-1;j++){
		if (class_3[j]>class_3[j+1]){
		  swap    =class_3[j];
		  class_3[j]  =class_3[j+1];
		  class_3[j+1]=swap;
		}
	}
}

// highest and lowest grades in each class
// class1
int max=class_1[0];
int min=class_1[0];
for (int i =0; i<n; i++){
    if (class_1[i]>max){
        max=class_1[i];
    }
    if(class_1[i]<min){
        min=class_1[i];
    }

}
printf("Highest Grade in Class 1 is %d\n",max);
printf("Lowest  Grade in Class 1 is %d\n\n",min);

//class2 grads
int max_2=class_2[0];
int min_2=class_2[0];
for (int i =0; i<n; i++){
    if (class_2[i]>max_2){
        max_2=class_2[i];
    }
    if(class_2[i]<min_2){
        min_2=class_2[i];
    }

}
printf("Highest Grade in Class 2 is %d\n",max_2);
printf("Lowest  Grade in Class 2 is %d\n\n",min_2);

//class 3 grads
int max_3=class_3[0];
int min_3=class_3[0];
for (int i =0; i<n; i++){
    if (class_3[i]>max_3){
        max_3=class_3[i];
    }
    if(class_3[i]<min_3){
        min_3=class_3[i];
    }

}
printf("Highest Grade in Class 3 is %d\n",max_3);
printf("Lowest  Grade in Class 3 is %d\n\n",min_3);

//average grads for each class
//class 1
float count =0;
for(int i=0; i<n ;i++){
    count= count+class_1[i];
}
count=count/n;
printf("Average Grads in Class 1 is %0.1f\n",count);

//class 2
float count_2 =0;
for(int i=0; i<n ;i++){
    count_2= count_2+class_2[i];
}
count_2=count_2/n;
printf("Average Grads in Class 2 is %0.1f\n",count_2);

//class 3
float count_3 =0;
for(int i=0; i<n ;i++){
    count_3= count_3+class_3[i];
}
count_3=count_3/n;
printf("Average Grads in Class 3 is %0.1f\n\n",count_3);

// passed and failed students in each class
int pass=0;
int faill=0;
for(int i=0; i<n; i++){
    if (class_1[i]<=100){
        pass++;
    }
    if (class_1[i]<50){
        faill++;
    }
}
printf("Number of passed students in Class 1 is %d\n",pass);
printf("Number of Failed students in Class 1 is %d\n\n",faill);

//class 2
int pass_2=0;
int faill_2=0;
for(int i=0; i<n; i++){
    if (class_2[i]<=100){
        pass_2++;
    }
    if (class_2[i]<50){
        faill_2++;
    }
}
printf("Number of passed students in Class 2 is %d\n",pass_2);
printf("Number of Failed students in Class 2 is %d\n\n",faill_2);

//class 3
int pass_3=0;
int faill_3=0;
for(int i=0; i<n; i++){
    if (class_3[i]<=100){
        pass_3++;
    }
    if (class_3[i]<50){
        faill_3++;
    }
}
printf("Number of passed students in Class 3 is %d\n",pass_3);
printf("Number of Failed students in Class 3 is %d\n\n",faill_3);
    return 0;
}
