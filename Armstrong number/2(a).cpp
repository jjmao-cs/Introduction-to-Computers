#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int a,b,c,d,e=0;

	for (a=100; a<=999;a++)
	{
		b=a/100;
		c=a/10-10*b;
		d=a-10*c-100*b;
		
		b=pow(b,3.0);
		c=pow(c,3.0);
		d=pow(d,3.0);

		e=b+c+d;

		if(e==a){
			printf("%d\n",a);
	
		}
	}
		
	system("pause");
	return 0;

}