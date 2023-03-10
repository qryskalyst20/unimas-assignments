#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_menu(int*, int*, float*, float*);
float CalculatePrice(int*, float*, int, int, int, int);
void DisplayReceipt(int*, int, int, int, int, int, float);
void Continue();
void dailyTransaction(int*, int*, float*, float*);

int main(){
	
	int choice, totalstudent, totaladult;
	float totalprice=0, totalshoes=0;
	
	do{
		puts("/===========================/");
		puts("           MENU               ");
		puts("/============================/");
		puts("1. Enter user's order");
		puts("2. Summary of Daily Transaction");
		puts("3. Summary of Monthly Avenue Report");
		puts("4. Exit");
		printf("\n>> ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1 : 
				print_menu(&totalstudent, &totaladult, &totalprice, &totalshoes);
				system("cls"); break;
			case 2 :
				dailyTransaction(&totalstudent, &totaladult, &totalprice, &totalshoes);
				system("cls"); break;
			case 3 :
				puts("SUMMARY OF MONTHLY AVENUE REPORT"); break;
			case 4 : 
				puts("EXIT"); break;
			default :
				puts("INVALID INPUT!");
		}	
	}while(choice!=4);
	
	puts("Thankyou for using our program xoxo");
	
	return 0;
}

void print_menu(int *totalstudent, int *totaladult, float *totalprice, float *totalshoes){
	//Print the menu
	int i, package, time, adult, student, shoes;
	float price[i];
	char yn;
		
	for(i=0; i<2; i++){
		system("cls");
		printf("\tWELCOME TO ROLL & BOWL!!\n\n");
		printf("Lane #%d:\n\n", i+1);
		
		printf("How many players for each category: \n");
		printf("Student: ");
		scanf("%d", &student);
		*totalstudent+=student;
		
		printf("Adult: ");
		scanf("%d", &adult);
		*totaladult+=adult;
		
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
		
		price[i] = CalculatePrice(&shoes, &totalshoes, student, adult, package, time);
		*totalprice+=price[i];

		DisplayReceipt(&shoes, i, adult, student, package, time, price[i]);
		Continue();
	}
		
}

float CalculatePrice(int *shoes, float *totalshoes, int s, int a, int p, int t){
	
	int student[4][3] = {{5, 8, 8}, {7, 10, 10}, {9, 12, 12}, {7, 0, 0}};
	int adult[3][3] = {{8, 12, 10}, {10, 14, 12}, {12, 16, 14}};
	int time, temp;
	float price;
	
	*shoes=4*(s+a);
	*totalshoes+=*shoes;
	
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

void DisplayReceipt(int *shoes, int i, int adult, int student, int p, int t, float price){

	FILE* data;
	
	printf("\n\n=======================================\n");
	printf("\tRECEIPT\n");
	printf("=======================================\n");
	
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
	
	//write into datafile
	data = fopen("data.txt", "a");
	
	fprintf(data, "Lane #: %d\n\n", i+1);
	fprintf(data, "--Players--\n");
	fprintf(data, "Student: %d\n", student);
	fprintf(data, "Adult: %d\n\n", adult);
	
	fprintf(data, "Package: ");
	switch(p){
		case 1:
			fprintf(data, "\tWeekday\n"); break;
		case 2:
			fprintf(data, "\tWeekend\n"); break;
		case 3:
			fprintf(data, "\tPublic Holiday\n"); break;
		default:
			fprintf(data, "\tSchool Holiday Special\n"); break;
	}
	
	fprintf(data, "Time: ");
	if(t>=1000 && t<=1800){
		fprintf(data, "\t\tNormal Hour\n");
	}else if(t>1800 && t<=2200){
		fprintf(data, "\t\tPeak Hours\n");
	}else{
		fprintf(data, "\t\tMidnight Special\n");
	}
	
	fprintf(data, "\nBowling Shoes Rental: RM%d\n", *shoes);
	
	fprintf(data, "=======================================\n");
	fprintf(data, "Total Price: RM%.2f\n", price);
	fprintf(data, "=======================================\n\n\n");
	
	fclose(data);
}

void dailyTransaction(int *totalstudent, int *totaladult, float *totalprice, float *totalshoes){
	
	system("cls");
	printf("--------------------Daily Transaction--------------------\n\n");
	
	printf("Total number of student: %d\n", *totalstudent);
	printf("Total number of adult: %d\n", *totaladult);
	printf("Total price is: RM%.2f\n", *totalprice);
	printf("Total price of bowling shoes rent: RM%.2f\n\n", *totalshoes);
	
	Continue();
	
}

void Continue(){
	
	printf("Press any key to continue");
	getch();
}










