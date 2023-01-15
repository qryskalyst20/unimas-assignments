#include <stdio.h>
#include <string.h>

void print_menu();
float CalculatePrice(int*, int, int, int, int);
void DisplayReceipt(int*, int, int, int, int, int, float,int,int,int);
void Continue();
void dailyTransaction();

int main(){
	int choice;
	
	do{
		puts("/===========================/");
		puts("           MENU               ");
		puts("/============================/");
		puts("1. Enter user's order");
		puts("2. Summary of Daily Transaction");
		puts("3. Summary of Monthly Avenue Report");
		puts("4. Exit");
		printf(">> ");
		scanf("%d", &choice);
		fflush(stdin);
		
		
		switch(choice){
			case 1 : 
				print_menu(); 
				system("cls");
				break;
			case 2 :
				dailyTransaction();
				getch();
				system("cls");
				break;
			case 3 :
				puts("SUMMARY OF MONTHLY AVENUE REPORT");
				break;
			case 4 : 
				puts("EXIT"); break;
			default :
				puts("INVALID INPUT!");
		}	
	}while(choice!=4);
	
	puts("Thankyou for using our program xoxo");
	
	return 0;
}



void print_menu(){
	//Print the menu
	float *totalprice_weekdaynormalhour = 0;
	float totalprice_weekdaypeakhour = 0;
	float totalprice_weekdaymidnight = 0;
	float totalprice_weekendnormalhour = 0;
	float totalprice_weekendpeakhour = 0;
	float totalprice_weekendmidnight = 0;
	int i, package, time, adult, student, shoes;
	int day,month,year;
	float price[10];
	char yn;
		
	for(i=0; i<2; i++){
		system("cls");
		printf("\tWELCOME TO ROLL & BOWL!!\n\n");
		printf("Enter day : ");
		scanf("%d",&day);
		printf("Enter month : ");
		scanf("%d",&month);
		printf("Enter year : ");
		scanf("%d",&year);
		
		printf("\nToday's date: %d/%d/%d", day, month, year);
		printf("\n\nLane #%d:\n\n", i+1);
		
		printf("How many players for each category: \n");
		printf("Student: ");
		scanf("%d", &student);
		printf("Adult: ");
		scanf("%d", &adult);
		
		printf("\nSelect Package:\n(1) Weekday\t\t(2) Weekend\n(3) Public Holiday\t(4) School Holiday Special");
		printf("\n=> ");
		scanf("%d", &package);
		
		do{
			printf("\nEnter time in 24h format (eg: 1000-2400)\n=> ");
			scanf("%d", &time);
			
			if(time<1000 || time>2400){
				printf("Time not available!");
			}
		}while(time<1000 || time>2400);
		
		price[i] = CalculatePrice(&shoes, student, adult, package, time);
		DisplayReceipt(&shoes, i, adult, student, package, time, price[i],day,month,year);
		
		if(package==1 && (time>=1000 && time<=1800)){
		*totalprice_weekdaynormalhour += price[i];
		printf("Total Weekday normal hour price : RM%.2f \n",*totalprice_weekdaynormalhour);
	}
		if(package==1 && (time>=1900 && time<=2200)){
		totalprice_weekdaypeakhour += price[i];
		printf("Total Weekday peak hour price : RM%.2f \n",totalprice_weekdaypeakhour);
	}
		if(package==1 && (time>=2200 && time<=2400)){
		totalprice_weekdaymidnight += price[i];
		printf("Total Weekday midnight price : RM%.2f \n",totalprice_weekdaymidnight);
	}
		if(package==2 && (time>=1000 && time<=1800)){
		totalprice_weekendnormalhour += price[i];
		printf("Total Weekend normal hour price : RM%.2f \n",totalprice_weekendnormalhour);
	}
		if(package==2 && (time>=1900 && time<=2200)){
		totalprice_weekendpeakhour += price[i];
		printf("Total Weekend peak hour price : RM%.2f \n",totalprice_weekendpeakhour);
	}
		if(package==2 && (time>=2200 && time<=2400)){
		totalprice_weekendmidnight += price[i];
		printf("Total Weekend midnight price : RM%.2f \n",totalprice_weekendmidnight);
	}

		Continue();
	}
	
		
}

float CalculatePrice(int *shoes, int s, int a, int p, int t){
	
	int student[4][3] = {{5, 8, 8}, {7, 10, 10}, {9, 12, 12}, {7, 0, 0}};
	int adult[3][3] = {{8, 12, 10}, {10, 14, 12}, {12, 16, 14}};
	int time, temp;
	float price;
	
	*shoes=4*(s+a);
	
	if(t>=1000 && t<=1800){
		time=0;
		if(p==4 && s%3==0){
			temp=s/3;
			s-=temp;
		}
	}else if(t>1800 && t<=2200){
		time=1;
	}else{
		time=2;
		if((p==1 || p==2) && s%3==0){
			temp=s/3;
			s-=temp;
		}
		
		if((p==1 || p==2) && a%3==0){
			temp=a/3;
			a-=temp;
		}
	}
	
	return *shoes+s*(student[p-1][time]) + a*(adult[p-1][time]);
}

void DisplayReceipt(int *shoes, int i, int adult, int student, int p, int t, float price,int day, int month, int year){
	
	printf("\n\n=======================================\n");
	printf("\tRECEIPT\n");
	printf("=======================================\n");
	printf("Date : %d/%d/%d \n",day,month,year);
	printf("Lane #: %d\n\n", i+1);
	printf("--Players--\n");
	printf("Student: %d\n", student);
	printf("Adult: %d\n\n", adult);
	
	printf("Package: ");
	switch(p){
		case 1:
			printf("\tWeekday\n"); break;
		case 2:
			printf("\tWeekend\n"); break;
		case 3:
			printf("\tPublic Holiday\n"); break;
		default:
			printf("\tSchool Holiday Special\n"); break;
	}
	
	printf("Time: ");
	if(t>=1000 && t<=1800){
		printf("\t\tNormal Hour\n");
	}else if(t>1800 && t<=2200){
		printf("\t\tPeak Hours\n");
	}else{
		printf("\t\tMidnight Special\n");
	}
	
	printf("\nBowling Shoes Rental: RM%d\n", *shoes);
	
	printf("=======================================\n");
	printf("Total Price: RM%.2f\n", price);
	printf("=======================================\n\n\n");
	
	
}


void Continue(){
	
	printf("Press any key to continue");
	getch();
}

void dailyTransaction(){
	int day, year, month;
	float *totalprice_weekdaynormalhour = 0;
	printf("=========== DAILY TRANSACTION =============\n");
	printf("Date : %d/%d/%d",day,month,year);
	printf("Total Weekday normal hour price : RM%.2f",*totalprice_weekdaynormalhour);
	
}

