#include <stdio.h> 

int main()
{
	int sum[5],table[5][10];
	float avg[5];
	int counter=0,a,yn;
	char *issue[5]={"Political","Golobal enviromental","World Hunger","Disease","Educational Deficiencies"};
	
	//initialize
	for(int i=0;i<5;i++){
		avg[i]=0;
		sum[i]=0;
		for(int k=0;k<10;k++){
			table[i][k]=0;
		}
	}
	
	//poll
	printf("rate each issue from 1-10 (10 being most important) \n");
	do{
		for(int i=0;i<5;i++){
			printf("(%d).%s�G",i+1,issue[i]);
			scanf("%d",&a);
			table[i][a-1]+=1;
		}
		printf("Enter for another user? (yes:0-no:1)\n");
		scanf("%d",&yn);
		counter++;
	}while(yn==0);
	printf("\n");
	
	//AVERAGE 
	for(int i=0;i<5;i++){
		for(int k=0;k<10;k++){
			sum[i]=sum[i]+((k+1)*table[i][k]);
		}
		avg[i]=(float)sum[i]/counter;
	}
	
	//print result
	printf("%-25s","Issues");
	for(int i=1;i<11;i++){
		printf("%4d",i);
	}
	printf("%6s\n","AVG");
	for(int i=0;i<5;i++){
		printf("%-25s",issue[i]);
		for(int k=0;k<10;k++){
			printf("%4d",table[i][k]);
		}
		printf("%6.2f\n\n",avg[i]);
	}
	
	//Highest &�@lowest 02
	int hold,hisum=sum[0],losum=sum[0],temphigh=0,templow=0;
	for(int i=0;i<5;i++){
		if(sum[i]>hisum){
			hisum=sum[i];
			temphigh=i;
		}
		if(sum[i]<losum){
			losum=sum[i];
			templow=i;
		} 
	}
	printf("The highest issue is %s receiving %d points\n",issue[temphigh],hisum);
	printf("The lowest  issue is %s receiving %d points\n",issue[templow],losum);
	 
	return 0;
}
