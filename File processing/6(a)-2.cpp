#include<stdio.h>

int main()
{
	int account;
	char name[30];
	float balance,cost;
	
	FILE *cfptr;
	
	if((cfptr=fopen("clients.txt","r"))==NULL){
		printf("ERROR\n");
	}
	else{
		printf( "%-11s%-14s%-9s%-10s\n", "account", "name", "balance", "cost" );
		fscanf( cfptr, "%d %s %f %f", &account, name, &balance, &cost );
	while ( !feof( cfptr ) ) {
			printf( "%-10d %-13s %-7.2f %-7.2f\n", account, name, balance, cost );
			fscanf( cfptr, "%d %s %f %f", &account, name, &balance, &cost );
			
		} 
		
		fclose( cfptr ); 
	}
	
	return 0;
	
 } 
