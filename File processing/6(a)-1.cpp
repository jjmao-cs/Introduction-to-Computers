#include<stdio.h>

int main()
{
	int account;
	char name[30];
	float balance,cost;
	
	FILE *cfptr;
	
	if((cfptr=fopen("clients.txt","a"))==NULL){
		printf("ERROR\n");
	}
	else{
		printf("Enter the account, name, balance, and cost.\n");
		printf("Enter EOF to end input.\n");
		printf( "? " );
		scanf( "%d%s%f%f", &account, name, &balance, &cost ); 
		while ( !feof( stdin ) ) {
			fprintf( cfptr, "%d %s %.2f %.2f\n", account, name, balance, cost );
			printf( "? " );
			scanf( "%d%s%f%f", &account, name, &balance, &cost );
		} 
		
		fclose( cfptr ); 
	}
	
	return 0;
	
 } 
