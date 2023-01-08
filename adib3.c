#include <stdio.h>
#include <string.h>

void Login();
float CalculatePrice(int, int, int, int);
void DisplayReceipt(float, int, int, int, int, int, float);
void Continue();

int main(){
	
	int i, package, time, adult, student;
	float price[10], shoes=0;
	char yn;
	
	Login();
		
	for(i=0; i<10; i++){
		system("cls");
		printf("\tWELCOME TO ROLL & BOWL!!\n\n");
		printf("Lane #%d:\n\n", i+1);
		
		printf("Enter player for each category: \n");
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
		
		price[i] = CalculatePrice(student, adult, package, time);
		
		printf("\nDo you want to rent shoes?(y/n): ");
		scanf("%s", &yn);
		if(yn=='y' || yn=='Y'){
			shoes=4*(student+adult);
			price[i]+=shoes;
		}
		DisplayReceipt(shoes, i, adult, student, package, time, price[i]);
		Continue();
	}
	
	return 0;
}

float CalculatePrice(int s, int a, int p, int t){
	
	int student[4][3] = {{5, 8, 8}, {7, 10, 10}, {9, 12, 12}, {7, 0, 0}};
	int adult[3][3] = {{8, 12, 10}, {10, 14, 12}, {12, 16, 14}};
	int time;
	float price;
	
	if(t>=1000 && t<=1800){
		time=0;
	}else if(t>1800 && t<=2200){
		time=1;
	}else{
		time=2;
	}
	
	price = s*(student[p-1][time]) + a*(adult[p-1][time]);
	
	return price;
}

void DisplayReceipt(float s, int i, int adult, int student, int p, int t, float price){

	printf("\n\n=======================================\n");
	printf("\tRECEIPT\n");
	printf("=======================================\n");
	
	printf("Lane #: %d\n\n", i+1);
	printf("Category:\n");
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
	
	printf("Bowling Shoes Rental: RM%.2f\n", s);
	
	printf("=======================================\n");
	printf("Total Price: RM%.2f\n", price);
	printf("=======================================\n\n\n");
}

void Continue(){
	
	printf("Press any key to continue");
	getch();
}

void Login(){
	
	char username[30], password[30];
	
	printf("\t\tLOG IN\n\n");
	printf("\tUsername: ");
	scanf("%s", username);
	printf("\tPassword: ");
	scanf("%s", &password);
	
	if(strcmp(username, "quddus")==0 && strcmp(password, "hensem")==0){
		system("cls");
	}else{
		printf("Invalid username or password!\n");
		printf("Press any key to try again");
		getch();
		system("cls");
		Login();
	}
	
	
}









