#include<stdio.h>
#include<stdlib.h>

int main()
{
	float tc,sal,tstc,cs,ss;
	printf("Enter total amount collected : ");
	scanf("%f$",&tc);
	printf("Total collections : %f$\n",tc);
	sal=tc/1.09;
	printf("Sales :%f$\n",sal);
	tstc=sal*0.09;
	cs=tstc*0.5555556;
	printf("County sales : %f$\n",cs);
	ss=tstc*0.4444444;
	printf("State sales : %f$\n",ss);
	printf("Total sales tax collected :%f$\n",tstc);

	system ("PAUSE");
	return 0;
}