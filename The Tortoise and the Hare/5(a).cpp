#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void tortoise(int *tPtr);
void hare(int *hPtr);
void position(int *tpPtr,int *hpPtr);

int main()
{
	srand(time(0));
	int T=70,H=70;
	
	//loop while tie
	while(T==70&&H==70)
	{
		//initialize position
		T=1;
		H=1;
		
		//Begin print
		printf("BANG !!!!!\nAND THEY ��RE OFF !!!!!\n");
		printf("START\n"); 
		
		//Gane simulate
		while(T!=70 && H!=70 )
		{
			tortoise(&T);
			hare(&H);
			position(&T,&H);
			Sleep(100);
		}
		
		//result decide
		if(T==70 || H==70)
		{
			if(T>H)
			{
				printf("TORTOISE WINS!!! YA!!!");
			}
			else if (H>T)
			{
				printf("Hare wins. Yuch.");
			}
			else if(H==T)
			{
				printf("It is a tie.");
			}
		}
	}
	return 0;
 } 
 
 //tortoise position change
 void tortoise(int *tPtr)
 {
 	int x=1+rand()%10;
 	
 	if(x>=1 && x<=5){
 		*tPtr+=3;
	 }else if (x==6 || x==7 ){
	 	*tPtr-=6;
	 }else{
	 	*tPtr+=1;
	 } 
	//accident 
	 if(*tPtr<1){
	 	*tPtr=1;
	 }
	 if(*tPtr>70){
	 	*tPtr=70;
	 }	
 }
 
 //hare position change
 void hare(int *hPtr)
 {
 	int x=1+rand()%10;
 	
 	if(x==1 || x==2){
 		*hPtr=*hPtr;
	 }else if (x==3 || x==4 ){
	 	*hPtr+=9;
	 }else if (x==5){
	 	*hPtr-=12;
	 }else if(x>=6 && x<=8){
	 	*hPtr+=1;
	 }else{
	 	*hPtr-=1;
	 }	 
	 //accident 
	 if(*hPtr<1){
	 	*hPtr=1;
	 }
	 if(*hPtr>70){
	 	*hPtr=70;
	 }
 }
 
 //print position
 void position(int *tpPtr,int *hpPtr)
 {
 	char a[70];
 	
 	for(int i=0;i<=69;i++){
 		a[i]=' ';
	}
	
 	if(*tpPtr == *hpPtr){
 		a[*tpPtr]='O';
 		a[*tpPtr+1]='U';
 		a[*tpPtr+2]='C';
 		a[*tpPtr+3]='H';
 		a[*tpPtr+4]='!';
 		a[*tpPtr+5]='!';
 		a[*tpPtr+6]='!';
	 }
	 else{
	 	a[*tpPtr]='T';
	 	a[*hpPtr]='H';
	 }
	 
 	printf("%s\n",a);
 }
 
