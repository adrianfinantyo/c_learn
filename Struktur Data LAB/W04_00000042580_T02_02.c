#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

struct student{
	char name[50];
	char major[50];
	int nim[50];
	int task;
	int mid;
	int final;
	float total;
	char grade[2];
	struct student *prev, *next;
}*head, *tail, *node;

// Fungsi untuk menampilkan menu
void show_menu(int currList){
	system("cls");
	printf("Welcome to simple student database (%d/Unlimited)\n", currList);
	printf("1. Input new students\n");
	printf("2. Show all students\n");
	printf("3. Show all scores\n");
	printf("4. Delete student\n");
	printf("0. Exit\n");
	printf("Choose : ");
}

// Fungsi untuk mengecek jumlah mahasiswa
int currList(){
	int count;
	char c;
	FILE *fdm = fopen("dataMahasiswa.txt", "r");
	
    for (c = getc(fdm); c != EOF; c = getc(fdm)){
    	if (c == '\n')
        	count = count + 1; 
	}
	fclose(fdm);
	
	return count;
}

// Fungsi untuk me-return grade
int studentGrade(float total, char grade[]){
	if(total >= 95)
			strcpy(grade,"A+");
		else if(total >= 85)
			strcpy(grade,"A");
		else if(total >= 80)
			strcpy(grade,"A-");
		else if(total >= 75)
			strcpy(grade,"B+");
		else if(total >= 70)
			strcpy(grade,"B");
		else if(total >= 65)
			strcpy(grade,"C");
		else if(total >= 60)
			strcpy(grade,"C-");
		else if(total >= 55)
			strcpy(grade,"D");
		else if(total >= 0)
			strcpy(grade,"E");
}

// Fungsi untuk melakukan input newStudent
void inputStudent(){
	struct student newStudent;
	
	system("cls");
	printf("    Insert Student Information\n");
	printf("----------------------------------\n");
	printf("NIM\t\t: "); scanf("%[^\n]", newStudent.nim); fflush(stdin);
	printf("Name\t\t: "); scanf("%[^\n]", newStudent.name); fflush(stdin);
	printf("Major\t\t: "); scanf("%[^\n]", newStudent.major); fflush(stdin);
	printf("\n    Insert Student Score\n");
	printf("----------------------------------\n");	
	printf("Task\t\t: "); scanf("%d", &newStudent.task); fflush(stdin);
	printf("Mid Term\t: "); scanf("%d", &newStudent.mid); fflush(stdin);
	printf("Final Term\t: "); scanf("%d", &newStudent.final); fflush(stdin);
	printf("Final Score\t: %.2f\n", newStudent.total = (0.3 * newStudent.task + 0.3 * newStudent.mid + 0.4 * newStudent.final));
	printf("Grade\t\t: %s\n", studentGrade(newStudent.total, newStudent.grade));
	printf("\n----------------------------------\n");	
	printf("Press any key to PUSH data..."); getchar();
	FILE *fdm = fopen("dataMahasiswa.txt", "a");
	fprintf(fdm, "%s#%s#%s\n", newStudent.nim, newStudent.name, newStudent.major);
	fclose(fdm);
	FILE *fnm = fopen("nilaiMahasiswa.txt", "a");
	fprintf(fnm, "%s#%d#%d#%d#%.2f#%s\n", newStudent.nim, newStudent.task, newStudent.mid, newStudent.final, newStudent.total, newStudent.grade);
	fclose(fnm);
	printf("\nSuccess! New student added to database\nPress any key to continue..."); getchar();
}

// Fungsi untuk menampilkan dataMahasiswa
void showStudent(){
	int i=1;
	node = head;

	// Print list dataMahasiswa
	system("cls");
	printf("                       List of Student Information\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("| No.|                   Name                   |        Major        |     NIM     |\n");
	printf("-------------------------------------------------------------------------------------\n");
	if(head != NULL)
		while(node != NULL){
			printf("| %2d | %-40s | %-19s | %11s |\n", i++, node->name, node->major, node->nim);
			node = node->next;
		}
	else
		printf("                               NO DATA!\n");
	printf("-------------------------------------------------------------------------------------\n");
}

// Fungsi untuk menampilkan nilaiMahasiswa
void showScore(){
	int i=1;
	node = head;
	
	// Print list nilaiMahasiswa
	system("cls");
	printf("                       List of Student Information\n");
	printf("--------------------------------------------------------------------\n");
	printf("| No.|     NIM    |  Task  | Mid Term | Final Term | Total | Grade |\n");
	printf("--------------------------------------------------------------------\n");
	if(head != NULL)
		while(node != NULL){
			printf("| %2d | %11s |  %3d  |   %3d    |    %3d     | %.2f |   %-2s  |\n", i++, node->nim, node->task, node->mid, node->final, node->total, node->grade);
			node = node->next;
		}
	else
		printf("                               NO DATA!\n");
	printf("--------------------------------------------------------------------\n");
}

void fetchData(){
	
	system("cls");
	printf("Fetching data in progress....\n");
	
	head = NULL;
	
	FILE *fdm = fopen("dataMahasiswa.txt", "r");
	FILE *fnm = fopen("nilaiMahasiswa.txt", "r");
	while(!feof(fdm)){
		node = (struct student*)malloc(sizeof(struct student));
		fscanf(fdm, "%[^#]#%[^#]#%[^\n]\n", node->nim, node->name, node->major);
		fscanf(fnm, "%[^#]#%d#%d#%d#%f#%[^\n]\n", node->nim, &node->task, &node->mid, &node->final, &node->total, node->grade);
		if(head==NULL)
			head = tail = node;
		else{
			tail->prev = tail;
			tail->next = node;
			tail = node;
		}
	}
	fclose(fdm);
	fclose(fnm);
	node->next = NULL;
	printf("\n\nFetching data success\nPress any key to continue...");
}

void removeStudent(){
	char tempNIM[50];
	bool flag = 1;
	struct student *trash, *tempBefore, *tempAfter;

	system("cls");
	printf("      Remove student\n");
	printf("---------------------------\n");
	printf("Student NIM : "); scanf("%[^\n]", tempNIM);
	
	trash = head;
	if(head != NULL)
		while(strcmp(trash->next->nim, tempNIM)){
			trash = trash->next;
			if(trash->next == NULL){
				flag = 0;
				break;	
			}
		}
	if(flag == 1){
		tempBefore = trash->prev;
		tempAfter = trash->next;
		tempBefore->next = tempAfter;
		tempAfter->prev = tempBefore;
		trash->next = NULL;
		trash->prev = NULL;
		free(trash);

		//Mengirim Output ke file .txt
		FILE *fdm = fopen("dataMahasiswa", "w");
		FILE *fnm = fopen("nilaiMahasiswa", "w");
		node = head;
		if(head != NULL)
			while(node != NULL){
				fprintf(fdm, "%s#%s#%s\n", node->nim, node->name, node->major);
				fprintf(fnm, "%s#%d#%d#%d#%.2f#%s\n", node->nim, &node->task, &node->mid, &node->final, &node->total, node->grade);
				node = node->next;
			}
		fclose(fdm);
		fclose(fnm);
		
		printf("Student removed!\nPress any key to continue..."); getchar();
	}
	else
		printf("Student not found!\nPress any key to continue..."); getchar();
}

// MAIN FUNCTION
int main(){
	int stdTotal, menu;
	
	stdTotal = currList();
	do{
		fetchData();
		show_menu(stdTotal);
		scanf("%d", &menu); fflush(stdin);
		if (menu == 1){
			inputStudent();
			stdTotal += 1;
		}
		else if (menu == 2){
			showStudent();
			getchar();
		}
		else if (menu == 3){
			showScore();
			getchar();
		}
		else if (menu == 4){
			removeStudent();
		}
				
	}while (menu != 0); 
	
	return 0;
}
