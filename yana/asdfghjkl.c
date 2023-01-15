#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct System{
	int person;
	int seatType;
	int seatCategory;
	int destination;
	int seatAmount;
	int food;
	int drink;
};

int menu();
void displayTickets();
double seatReservation(int time, struct System ticket, struct System tic[]);
void displayReceipt();
void displayTransaction();

int main(){
	
	struct System ticket;
	struct System tic[3];
	
	printf("\n\t\t\t\t\t_WELCOME TO BUS RESERVATION SYSTEM!_\n");
	
	int choose;
	int time=1;
	double total;
	double sum = 0;
	
	FILE *record = fopen("transaction.txt", "a");
	fprintf(record , "\n__________________________________________________________________________________________________________________\n");
	fprintf(record , "|Receipt No |  Package  |  Seat Type  |  Seat Category  |  Destination  |  Quantity  |  Food  |  Drink  |  Amount |\n");
	fprintf(record , "|___________|___________|_____________|_________________|_______________|____________|________|_________|_________|");
	
	FILE *resit = fopen("receipt.txt", "a");
	fprintf(resit , "__ | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | __\n");
	fprintf(resit , "__                                                                         __\n");
	
	fclose(record);
	fclose(resit);
	
	choose = menu();
	while(choose != 5){
		
		switch(choose){
			
			case 1: 
				displayTickets();
				break;
				
			case 2:{
				   
				total = seatReservation(time,ticket,tic);
				time++;
				sum = sum + total;
				printf("Full total : RM %.2lf", sum);
				break;
			}
			
			case 3:
				displayReceipt();
				break;
				
			case 4:
				displayTransaction();
				break;
			
		}
		choose = menu();
		
	}
	printf("\n\t\t\t\t\tTHANK YOU !");  
		
}
	
int menu(){
	
	int choose ;
 	
	while( choose<1 || choose>5){
			
		printf("\n\n\n\n\t\t\t\t\tThese are the services provided - \n\n");
		printf("\t\t\t\t\t1 - Show Ticketing details\n");            
		printf("\t\t\t\t\t2 - Book seats.\n");
		printf("\t\t\t\t\t3 - Print receipt.\n");
		printf("\t\t\t\t\t4 - Display all transactions\n");
		printf("\t\t\t\t\t5 - Exit.\n");
		
		printf("\n\nPlease choose your preference : ");
		scanf("%d", &choose);
		
		if(choose<1 || choose>5){
			printf("\n\nService invalid!\n\n");
		}
	
   	return choose;
	}
}
   
   

void displayTickets(){
	
	printf("______________________________________________________________________________________________________ \n");
	printf("|              |                               Seat Type                               | Food & Drink |\n");
	printf("|              |_______________________________________________________________________|______________|\n");
	printf("|   Package    |              Hot Seat             |           Normal Seat             |              |\n");
	printf("|              |___________________________________|___________________________________|______________|\n");
	printf("|              | Kuching  | Serian | Kota Samarahan| Kuching  | Serian | Kota Samarahan| Food | Drink |\n");     
	printf("|______________|__________|________|_______________|__________|________|_______________|_(RM)_|__(RM)_|\n");	
	printf("|a) Adult :    |          |        |               |          |        |               |      |       |\n");   
	printf("|    Executive |  15.00   | 25.00  |    20.00      |   12.00  |  20.00 |     18.00     | 5.00 |  2.00 |\n");        
	printf("|______________|__________|________|_______________|__________|________|_______________|______|_______|\n");
	printf("|b) Adult :    |          |        |               |          |        |               |      |       |\n");   
	printf("|    Economy   |  12.00   | 20.00  |    17.00      |   10.00  |  18.00 |     15.00     | 4.00 |  1.50 |\n");        
	printf("|______________|__________|________|_______________|__________|________|_______________|______|_______|\n");
	printf("|c) Kids :     |          |        |               |          |        |               |      |       |\n");   
	printf("|    Executive |  7.50    | 12.50  |    10.00      |   6.00   |  10.00 |     9.00      | 3.50 |  1.20 |\n");        
	printf("|______________|__________|________|_______________|__________|________|_______________|______|_______|\n");
	printf("|d) Kids :     |          |        |               |          |        |               |      |       |\n");   
	printf("|    Economy   |  6.00    | 10.00  |    8.50       |   5.00   |  9.00  |     7.50      | 3.00 |  1.00 |\n");        
	printf("|______________|__________|________|_______________|__________|________|_______________|______|_______|\n");
	
}

double seatReservation(int time, struct System ticket, struct System *tic){
	
	int i, j, k, m, n;
	
	FILE *record = fopen("transaction.txt", "a");
	fprintf(record , "\n   00%d       ", time);	
	
	FILE *resit = fopen("receipt.txt" , "a");
	
	
	int exit = 1;  //entire loop
	
	double total[3];  //maximum 3 categories
	
	double subtotal=0;  //without food & drink
	
	double fulltotal=0;   //with food & drink
	
	int keluar=1;    //to break out the category loop
	
	int count = 0;   //loops for calculation
	
	int set = 1;    //person ke berapa
	
	//amount of tickets for the category
	double ticKuch1 = 0; 
	double ticSeri1 = 0;  //HOT Seat
	double ticKS1 = 0;
	
	double ticKuch2 = 0;
	double ticSeri2 = 0;   //NORMAL Seat
	double ticKS2 = 0;
	
	int drink; //drink confrimation
	int food;  //food confirmation
	
	int payment;  //cash or online banking 
	
	while(exit != 0){
		
		
		printf("\nPerson >> 1-Adult // 2-Kid : ");       //the person ADULT or KID
		scanf("%d",&ticket.person);
		
		while(ticket.person != 1 && ticket.person != 2 || getchar()!='\n'){   
			printf("Invalid! \n\n");
			printf("\nPerson >> 1-Adult // 2-Kid : ");
			scanf("%d",&ticket.person);
		}
		
		if(ticket.person == 1){
			printf("Person %d : Adult\n\n", set);
			fprintf(record , "  Adult    ");	
			fprintf(resit , "__     PERSON     :    Adult                                               __\n");
			fprintf(resit , "__                                                                         __\n");	
		}
		
		else if(ticket.person == 2){
			printf("Person %d : Kid\n\n", set);
			fprintf(record , "   Kid     ");	
			fprintf(resit , "__     PERSON     :    Kid                                                 __\n");
			fprintf(resit , "__                                                                         __\n");
		}
		
		
		//----------------------------------------------------------------------------------------
		
		
		printf("\nSeat Type >> 1-Executive // 2-Economy : ");         //EXECUTIVE or ECONOMY
		scanf("%d", &ticket.seatType);
		
		while(ticket.seatType != 1 && ticket.seatType != 2 || getchar()!='\n'){ 
			printf("Invalid! \n\n");  
			printf("Seat Type >> 1-Executive // 2-Economy : ");
			scanf("%d",&ticket.seatType);
		}
		
		if(ticket.seatType == 1){
			printf("Seat Type : Executive\n\n");
			fprintf(record , "   Executive  ");	
			fprintf(resit , "__     TYPE       :    Executive                                           __\n");
			fprintf(resit , "__                                                                         __\n");
			fprintf(resit , "__     CATEGORY   :    ");
		}
		
		else if(ticket.seatType == 2){
			printf("Seat Type : Economy\n\n");
			fprintf(record , "    Economy   ");	
			fprintf(resit , "__     TYPE       :    Economy                                             __\n");
			fprintf(resit , "__                                                                         __\n");
			fprintf(resit , "__     CATEGORY   :    ");
		}
		
	
	   //-------------------------------------------------------------------------------------
		
			
		for(i=0;i<3;i++){
		
		
				printf("\nSeat Category >> 1-HOT // 2-NORMAL : ");         //HOT or NORMAL
				scanf("%d", &tic[i].seatCategory);
				
				while((tic[i].seatCategory != 1) && (tic[i].seatCategory != 2) || getchar()!='\n'){  
					printf("Invalid! \n");
					printf("\nSeat Category >> 1-HOT // 2-NORMAL : ");
					scanf("%d",&tic[i].seatCategory);
				}
				
				if(tic[i].seatCategory == 1){
					printf("Seat Category : Hot seat\n\n");
					fprintf(record , "    Hot Seat      ");
					fprintf(resit , "Hot Seat     -- ");	
				}   
				
				else if(tic[i].seatCategory == 2){
					printf("Seat Category : Normal seat\n\n");
					fprintf(record , "    Normal Seat   ");
					fprintf(resit , "Normal Seat  -- ");
				}
					
				
				//--------------------------------------------------------------------------------------------------
				
				
				
				printf("\nChoose destination(1-Kuching ,2-Serian ,3-Kota Samarahan) : ");     //DESTINATION
				scanf("%d", &tic[i].destination);
				
				while(tic[i].destination != 1 && tic[i].destination != 2 && tic[i].destination != 3 || getchar()!='\n'){  
					printf("Invalid! \n");
					printf("Destination(1-Kuching ,2-Serian ,3-Kota Samarahan) : ");
					scanf("%d",&tic[i].destination);
				}
				
				if(tic[i].destination == 1){
					printf("Destination : Kuching\n\n");
					fprintf(record , "     Kuching    ");
					fprintf(resit , " Kuching        -- ");
				}
				
				if(tic[i].destination == 2){
					printf("Destination : Serian\n\n");
					fprintf(record , "     Serian     ");
					fprintf(resit , " Serian         -- ");
				}
				
				if(tic[i].destination == 3){
					printf("Destination : Kota Samarahan\n\n");
					fprintf(record , " Kota Samarahan ");
					fprintf(resit , " Kota Samarahan -- ");
				}
					
				
				//--------------------------------------------------------------------------------------------
				
				
				printf("\nEnter number of seats : ");                   //Amount of tickets
				scanf("%d", &tic[i].seatAmount); 
				printf("Seat quantity : %d\n\n", tic[i].seatAmount);       
				fprintf(record , "     %d       ", tic[i].seatAmount);
				
				fprintf(resit , " %d               __", tic[i].seatAmount);
					
				
				if(tic[i].seatCategory == 1){
					
					if(tic[i].destination == 1)
						ticKuch1 = ticKuch1 + tic[i].seatAmount;
						
					if(tic[i].destination == 2)
						ticSeri1 = ticSeri1 + tic[i].seatAmount;
						
					if(tic[i].destination == 3)
						ticKS1 = ticKS1 + tic[i].seatAmount;
						
				}
				
				else if(tic[i].seatCategory == 2){
					
					if(tic[i].destination == 1)
						ticKuch2 = ticKuch2 + tic[i].seatAmount;
						
					if(tic[i].destination == 2)
						ticSeri2 = ticSeri2 + tic[i].seatAmount;
						
					if(tic[i].destination == 3)
						ticKS2 = ticKS2 + tic[i].seatAmount;
						
				}
				
				
				if(count<2){
					printf("\nBack to seat Category ?(1-Yes , 2-No) : ");            //To continue category or go to food 
					scanf("%d", &keluar);
					
					while(keluar!= 1 && keluar != 2 || getchar()!='\n'){
						printf("Invalid!\n");
						printf("\nBack to seat Category ?(1-Yes , 2-No) : ");
						scanf("%d", &keluar);
					}
					
					printf("\n\n");
					
				}
				
				
				if(keluar == 1 && count<2){
				
					fprintf(record , "                              ");
					fprintf(record , "\n                                      ");	
					
					fprintf(resit , "\n__                :    ");   
				}
				
				count++;
				
				if(keluar == 2 )
					break;
	
		}
				
		//------------------------------------------------------------------------------------------	
	
		
		
		printf("\nFood? >> 1-Yes // 2-No : ");                 //FOOD pilihan
		scanf("%d", &food);
		
		while(food != 1 && food != 2 || getchar()!='\n'){ 
			printf("Invalid! \n");
			printf("Food >> 1-Yes // 2-No : ");
			scanf("%d",&ticket.food);
		}
		
		if(food == 1){
			
			printf("Enter quantity : ");
			scanf("%d", &ticket.food);
			printf("Food quantity : %d", ticket.food);
			fprintf(record , "    %d     ", ticket.food);
			fprintf(resit , "\n__     FOOD       :    %d                                                   __\n", ticket.food);
			fprintf(resit , "__                                                                         __\n");
		}
		
		if(food == 2){
			ticket.food = 0;
			fprintf(record , "    %d     ", ticket.food);
			fprintf(resit , "\n__     FOOD       :    %d                                                   __\n", ticket.food);
			fprintf(resit , "__                                                                         __\n");
		}
	
	
	
		//-----------------------------------------------------------------------------------
	
	
		printf("\n\nDrink >> 1-Yes // 2-No : ");                //DRINK pilihan
		scanf("%d", &drink);
		
		while(drink != 1 && drink != 2 || getchar()!='\n'){ 
			printf("Invalid! \n\n");
			printf("Drink >> 1-Yes // 2-No : ");
			scanf("%d",&ticket.drink);
		}
		
		if(drink == 1){
			
			printf("Enter quantity : ");
			scanf("%d", &ticket.drink);
			printf("Drink quantity : %d", ticket.drink);
			fprintf(record , "    %d     ", ticket.drink);
			fprintf(resit , "__     DRINK      :    %d                                                   __\n", ticket.drink);
			fprintf(resit , "__                                                                         __\n");
		}
		
		if(drink == 2){
			ticket.drink = 0;
			fprintf(record , "    %d     ", ticket.drink);
			fprintf(resit , "__     DRINK      :    %d                                                   __\n", ticket.drink);
			fprintf(resit , "__                                                                         __\n");
		}
		
		
		
		//--------------------------------------------------------------------------------------
		
		
		
		if(ticket.person == 1 ){
		
			if (ticket.seatType == 1){
				
				for(j=0;j<count;j++){
					
					if (tic[j].seatCategory == 1){  //Adult-Executive-Hot seat
							
						if(tic[j].destination == 1){
							total[j] = ticKuch1*15;	
						}
						
						if(tic[j].destination == 2){
							total[j] = ticSeri1*25;	
						}
						
						if(tic[j].destination == 3){
							total[j] = ticKS1*20 ;	
						}	
					}
					
					if (tic[j].seatCategory == 2){  //Adult-Executive-Normal seat
						
						if(tic[j].destination == 1){
							total[j] = ticKuch2*12 ;	
						}
						
						if(tic[j].destination == 2){
							total[j] = ticSeri2*20;	
						}
						
						if(tic[j].destination == 3){
							total[j] = ticKS2*18;	
						}			
					}
					
					subtotal = subtotal+total[j];
				}
			
			}
			
			if (ticket.seatType == 2){  //Adult-Economy-Hot seat
				
				for(k=0;k<count;k++){
				
					if (tic[k].seatCategory == 1){
						
						if(tic[k].destination == 1){
							total[k] = ticKuch1*12;	
						}
						
						if(tic[k].destination == 2){
							total[k] = ticSeri1*20 ;	
						}
						
						if(tic[k].destination == 3){
							total[k] = ticKS1*17;	
						}			
						
					}
			
			
					if (tic[k].seatCategory == 2){ //Adult-Economy-Normal seat
						
						if(tic[k].destination == 1){
							total[k] = ticKuch2*10;	
						}
						
						if(tic[k].destination == 2){
							total[k] = ticSeri2*18 ;	
						
						}
						
						if(tic[k].destination == 3){
							total[k] = ticKS2*15;	
						
						}			
						
					}
					subtotal = subtotal+total[k];
				}
			}
		}
		
		
		
		
	
		if(ticket.person == 2 ){   
		
			if (ticket.seatType == 1){
				
				for(m=0;m<count;m++){
					
					if (tic[m].seatCategory == 1){   //Kid-Executive-Hot seat
						
						if(tic[m].destination == 1){
							total[m] = ticKuch1*7.5;	
							
						}
						
						if(tic[m].destination == 2){
							total[m] = ticSeri1*12.5 ;	
							
						}
						
						if(tic[m].destination == 3){
							total[m] = ticKS1*10;	
							
						}	
					}
					
					if (tic[m].seatCategory == 2){   //Kid-Executive-Normal seat
						
						if(tic[m].destination == 1){
							total[m] = ticKuch2*6;	
						
						}
						
						if(tic[m].destination == 2){
							total[m] = ticSeri2*10;	
							
						}
						
						if(tic[m].destination == 3){
							total[m] = ticKS2*9;	
							
						}			
					}
					subtotal = subtotal+total[m];
				}
			}
		
			if (ticket.seatType == 2){     //Kid-Economy-Hot seat
				
				for(n=0;n<count;n++){
				
					if (tic[n].seatCategory == 1){
						
						if(tic[n].destination == 1){
							ticKuch1 = ticKuch1*6;
							total[n] = ticKuch1;	
							
						}
						
						if(tic[n].destination == 2){
							ticSeri1 = ticSeri1*10;
							total[n] = ticSeri1;	
						
						}
						
						if(tic[n].destination == 3){
							ticKS1 = ticKS1*8.5;
							total[n] = ticKS1;	
							
						}			
						
					}
			
			
					if (tic[n].seatCategory == 2){     //Kid-Economy-Normalseat
						
						if(tic[n].destination == 1){
							ticKuch2 = ticKuch2*5;
							total[n] = ticKuch2;	
							
						}
						
						if(tic[n].destination == 2){
							ticSeri2 = ticSeri2*9;
							total[n] = ticSeri2;	
							
						}
						
						if(tic[n].destination == 3){
							ticKS2 = ticKS2*7.5;
							total[n] = ticKS2;	
		
						}			
						
					}
					subtotal = subtotal+total[n];
				}
			}
		}
		
		if(ticket.person == 1 && ticket.seatType == 1){
			if(food == 1 && drink == 2)
				subtotal = subtotal+(5*ticket.food);
		
			if(drink == 1 && food == 2)
				subtotal = subtotal+(2*ticket.drink);
			
			if(drink == 1 && food == 1)
				subtotal = subtotal + (5*ticket.food + 2*ticket.drink);		
		} 
			

		if(ticket.person == 1 && ticket.seatType == 2){
			if(food == 1&& drink == 2)
				subtotal = subtotal+(4*ticket.food);
		
			if(drink == 1 && food == 2) 
				subtotal = subtotal+(1.5*ticket.drink);
			
			if(drink == 1 && food == 1)
				subtotal = subtotal + (4*ticket.food + 1.5*ticket.drink);		
		} 
			
			
		
		if(ticket.person == 2 && ticket.seatType == 1){
			if(food == 1 && drink == 2 )
				subtotal = subtotal+(3.5*ticket.food);
		
			if(drink == 1  && food == 2)
			subtotal = subtotal+(1.2*ticket.drink);
			
			if(drink == 1 && food == 1)
				subtotal = subtotal + (3.5*ticket.food + 1.2*ticket.drink);
		} 
			
			
			
			
		if(ticket.person == 2 && ticket.seatType == 2){
			
			if(food == 1 && drink == 2)
				subtotal = subtotal+(3*ticket.food);
		
			if(drink == 1 && food == 2)
				subtotal = subtotal+(1*ticket.drink);
			
			if(drink == 1 && food == 1)
				subtotal = subtotal + (3*ticket.food + 1*ticket.drink);	
		}
		 
				
		
		fulltotal = fulltotal+subtotal;
		printf("\n\nYou have to pay RM %.2lf", fulltotal);
		
		printf("\n\nContinue = 1  ||  Exit = 0 : ");
		scanf("%d", &exit);
				
		if(exit == 1){
			
			set++;
			
//			total[0] = '{0}';
//			total[1] = '{0}';
//			total[2] = '{0}';
			subtotal=0;
			
			keluar = 1;
			count = 0;
			
			ticKuch1 = 0;
			ticSeri1 = 0;
			ticKS1 = 0;
			
			ticKuch2 = 0;
			ticSeri2 = 0;
			ticKS2 = 0;
			
			fprintf(record , "\n             ");	
			
			fprintf(resit , "__          *****************************************************          __\n");
			
		}
		   
		if(exit == 0){
			
			//transaction file
			fprintf(record , "  %.2lf  ", fulltotal);
			fprintf(record , "\n------------------------------------------------------------------------------------------------------------------");
			
			
			//receipt file
			printf("\n\nPayment >> 1-Cash // 2-Online Banking : ");
			scanf("%d", &payment);
	
			while(payment != 1 && payment != 2 || getchar() != '\n'){
				printf("Invalid!\n");
				printf("\n\nPayment >> 1-Cash // 2-Online Banking : ");
				scanf("%d", &payment);
			}	
			
			fprintf(resit , "__     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   __\n");
			fprintf(resit , "__                                                                         __\n");
			fprintf(resit , "__     TOTAL          : RM   %.2lf                                        __\n", fulltotal);
			fprintf(resit , "__                                                                         __\n");
			
			if(payment == 1){
				fprintf(resit , "__     PAYMENT METHOD :  Cash                                              __\n");  	
			}
	
			if(payment == 2){
				fprintf(resit , "__     PAYMENT METHOD :   Online Banking                                   __\n");
			}
			
			fprintf(resit , "__                                                                         __\n");
			fprintf(resit , "__                                                                         __\n");          
			fprintf(resit , "__                                                                         __\n");
			fprintf(resit , "__                   THANK YOU FOR USING OUR SERVICE !                     __\n");
			fprintf(resit , "__                                                                         __\n");
			fprintf(resit , "__                      WE HOPE TO SEE YOU AGAIN !                         __\n");
			fprintf(resit , "__                                                                         __\n");
			fprintf(resit , "__                             AU REVOIR                                   __\n");
			fprintf(resit , "__                                                                         __\n");
			fprintf(resit , "__ | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | __\n\n"); 
			
			fclose(record);
			fclose(resit);
			
			break;
		}	
	}
	return (fulltotal);
}

void displayReceipt(){
	
	char read[5000];
	
	FILE *resit = fopen( "receipt.txt", "r" ) ;
	
	while(!feof(resit)){
			fgets(read , 5000 , resit);
			printf("%s", read);
		}
	
	fclose(resit);
}

void displayTransaction(){
	
	char read[2000];
	
	FILE *record = fopen( "transaction.txt", "r" );
	
	while(!feof(record)){
			fgets(read , 2000 , record);
			printf("%s", read);
	}
	
	fclose(record);
}


