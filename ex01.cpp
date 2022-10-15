//指针处理一维数组
#include"stdio.h"
int main()
{
	int a[10];
	int *p,max,k,i;
	for(i=0;i<10;i++)
	 scanf("%d",&a[i]);//scanf("%d",a+i);
	 max=a[0];k=0;
	 p=a;
	 for(i=1;i<10;i++)
	   if(*(p+i)>max)// (a[i]>max)
	    {
	    	max=*(p+i);
	    	k=i;
		}
	 printf("max=%d,k=%d\n",max,k) ;
 } 
 

