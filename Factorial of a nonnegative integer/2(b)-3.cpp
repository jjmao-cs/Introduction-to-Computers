#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	double a,b,p,r,i,e=1;

	printf("Please enter a x\nin order to finish e^x=1+x/1!+x^2/2!+x^3/3!+... \nthe x is:");
	scanf("%lf",&b);
	printf("\n");


	for(i=1;i<=100;i++)
	{
		p=pow(b,i);
		for(r=i,a=1;r>=1;r--)
		{
			a=a*r;
		}
		e=e+p/a;
	}


	printf("e^%d=1+%d/1!+%d^2/2!+%d^3/3!+... =%lf\n",(int)b,(int)b,(int)b,(int)b,e);
	system ("PAUSE");
	return 0;
}