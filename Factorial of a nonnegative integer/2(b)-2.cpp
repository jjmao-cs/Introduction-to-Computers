#include<stdio.h>
#include<stdlib.h>

int main()
{
	double a,r,i,e=1;

	for(i=1;i<=10;i++)
	{
		for(r=i,a=1;r>=1;r--)
		{
			a=a*r;
		}
		e=e+1/a;
	}
	printf("1+1/1!+1/2!+1/3!+1/4!+1/5!+...=%lf\n",e);
	system ("PAUSE");
	return 0;
}