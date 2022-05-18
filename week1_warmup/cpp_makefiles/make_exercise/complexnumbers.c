#include<stdio.h>
#include "functions.h"
int complexnumbers(){
	int a,b,c,d;
	printf(" enter the 1st complex number(a+ib): ");
	scanf("%d%d",&a,&b);
	printf(" enter the 2nd complex number(c+id): ");
	scanf("%d%d",&c,&d);
	int real,img;
	real=a+c;
	img=b+d;
	printf("result:%d+i%d",real,img);
	return 0;
}
