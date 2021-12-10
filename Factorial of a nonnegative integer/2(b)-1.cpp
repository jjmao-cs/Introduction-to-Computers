#include<stdio.h>
#include<stdlib.h>

int main()
{
	double a,total=1;
	
	printf("Please enter a number:\n");
	scanf("%lf",&a);
	printf("The factorial you get is:\n");

		for(;a>1.0;a--)
		{
			printf("%d*",(int)a);
			total=total*a;
		}


		printf("1= %lf\n",total);

	system("pause");
	return 0;

}