#include<stdio.h>

//NewDatatype
struct data{
	int record;
	char toolname[30];
	int quantity;
	float cost;
};

//Prototypes
void additem(FILE *aptr);
void deleteitem(FILE *dptr);
void updateitem(FILE *uptr);
void printchart(FILE *pptr);
//Prototypes unfinshed  
void initializechart(FILE *iptr);

//Main
int main()
{
	
	//Initialize
	int c=0;
	FILE *cfptr,*wptr;
	struct data newdata={0,"",0,0.0};
	
	//Program
	if((cfptr=fopen("hardware.dat","rb+"))==NULL){
		printf("FILE ERROR");
	}else{
		
		
		while(c!=5){
			
			printf("\n\nWhat do you want to do?\n");
			printf("1. Add an item.\n");
			printf("2. Delete an item.\n");
			printf("3. Update an item.\n");
			printf("4. Show an item.\n");
			printf("5. End this program.\n");
			printf("\nYour Choice�G");
			scanf("%d",&c);
			
			if(c==1){
				additem(cfptr);
			}else if(c==2){
				deleteitem(cfptr);
			}else if(c==3){
				updateitem(cfptr);
			}else if(c==4){
				printchart(cfptr);
			}else if(c!=5){
				printf("Entering an Illegal Number!\n");
			}
		}
		printf("End of This Program.\n");
		
		//write binary to text
		if((wptr=fopen("hardware.txt","w"))==NULL){
			printf("FILE ERROR\n");
			fclose(wptr);
		}else{
			rewind(cfptr);
			fprintf(wptr,"%-10s%-20s%-15s%-8s\n","Record#","Toolname","Quantity","Cost");
			while(!feof(cfptr)){
				fread(&newdata,sizeof(struct data),1,cfptr);
				if(newdata.record!=0){
					fprintf(wptr,"%-10d%-20s%-15d%-8.2f\n",newdata.record,newdata.toolname,newdata.quantity,newdata.cost);
				}	
			}
			fclose(wptr);
		}
		
		fclose(cfptr);
	}
	return 0;
 } 
 
 //Functions
 void additem(FILE *aptr){
 	
 	struct data newdata={0,"",0,0.0};
 	int recordnum;
 	
 	printf("Enter the record num you want to add:");
 	scanf("%d",&recordnum);
 	
 	fseek(aptr,(recordnum-1)*sizeof(struct data),SEEK_SET);
 	fread(&newdata,sizeof(struct data),1,aptr);
 	
 	if(newdata.record !=0 ){
 		printf("Record #%d already exists\n",newdata.record); 
	 }else{
	 	printf("Enter toolname, quantity, and cost.");
	 	scanf("%s%d%f",&newdata.toolname,&newdata.quantity,&newdata.cost);
	 	newdata.record=recordnum;
	 	
	 	fseek(aptr,(newdata.record-1)*sizeof(struct data),SEEK_SET);
	 	fwrite(&newdata,sizeof(struct data),1,aptr);
	 }
 }
 void deleteitem(FILE *dptr){
 	
 	struct data fulldata;
 	struct data newdata={0,"",0,0.0};
 	int recordnum;
 	
 	printf("Enter the record num you want to delete:");
 	scanf("%d",&recordnum);
 	
 	fseek(dptr,(recordnum-1)*sizeof(struct data),SEEK_SET);
 	fread(&fulldata,sizeof(struct data),1,dptr);
 	
 	if(fulldata.record ==0 ){
 		printf("Record #%d couldn't be found\n'",recordnum); 
	 }else{
	 	fseek(dptr,(recordnum-1)*sizeof(struct data),SEEK_SET);
	 	fwrite(&newdata,sizeof(struct data),1,dptr);
		printf("Successful\n\n");
 	 }

 }
 void updateitem(FILE *uptr){
 	
 	struct data newdata={0,"",0,0.0};
 	int recordnum,c;
 	
 	printf("Please enter a record num to update�G");
 	scanf("%d",&recordnum);
 	
 	fseek(uptr,(recordnum-1)*sizeof(struct data),SEEK_SET);
 	fread(&newdata,sizeof(struct data),1,uptr);
 	
 	if(newdata.record==0){
 		printf("Item #%d is empty.\n",recordnum);
	 }else{
		printf("You want to change\n 1)Toolname.\n 2)Quantity.\n 3)Cost.\n 4)End this record update.\n ?");	 	
	 	while(scanf("%d",&c)!=4){	
	 		switch(c){
	 			case 1:
	 				printf("The origin #%d toolname is %s\n Please enter a new toolname :",newdata.record,newdata.toolname);
	 				scanf("%s",newdata.toolname);
	 				printf("The new toolname is %s\n ",newdata.toolname);
	 				fseek(uptr,(newdata.record-1)*sizeof(struct data),SEEK_SET);
	 				fwrite(&newdata,sizeof(struct data),1,uptr);
	 				return;
	 			case 2:
	 				printf("The origin Quantity of #%d %s is %d\n Please enter a new quantity :",newdata.record,newdata.toolname,newdata.quantity);
	 				scanf("%d",&newdata.quantity);
	 				printf("\n\nThe quantity has been changed\nThe new quantity is %d\n\n ",newdata.quantity);
	 				fseek(uptr,(newdata.record-1)*sizeof(struct data),SEEK_SET);
	 				fwrite(&newdata,sizeof(struct data),1,uptr);
	 				return;
	 			case 3:
	 				printf("The origin Cost of #%d %s is %f\n Please enter a new Cost :",newdata.record,newdata.toolname,newdata.cost);
	 				scanf("%f",&newdata.cost);
	 				printf("\n\nThe cost has been changed\nThe new cost is %f\n\n ",newdata.cost);
	 				fseek(uptr,(newdata.record-1)*sizeof(struct data),SEEK_SET);
	 				fwrite(&newdata,sizeof(struct data),1,uptr);
	 				return;
	 			case 4:
	 				return;
	 			default:
	 				printf("Entering an Illegal Number!\n");
					break;
			 }

		 }

	 }
 }
void printchart(FILE *pptr){
	
	struct data newdata{0,"",0,0.0};
	int recordnum;
	 
	printf("Please enter the item you want to show: ");
	scanf("%d",&recordnum);
	//rewind(pptr);
	fseek(pptr,(recordnum-1)*sizeof(struct data),SEEK_SET);
	fread(&newdata,sizeof(struct data),1,pptr);
	/*if(recordnum==0){
		//printf("The record #%d you entered is empty!",recordnum);
	}else{*/
	printf("\n%-10s%-15s%-15s%-8s\n","Record#","Toolname","Quantity","Cost");
	printf("%-10d%-15s%-15d%-8.2f\n",recordnum,newdata.toolname,newdata.quantity,newdata.cost);
	//}
}
 
 
 
 
