#include <stdio.h>
#include <windows.h>
#include <string.h>

struct student{
	char name[50];
	char major[50];
	int nim[50];
	int task;
	int mid;
	int final;
	float total;
	char grade[2];
};

// Fungsi untuk menampilkan menu
void show_menu(int currList){
	system("cls");
	printf("Welcome to simple student database (%d/100)\n", currList);
	printf("1. Input new students\n");
	printf("2. Show all students\n");
	printf("3. Show all scores\n");
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
void showStudent(int stdTotal){
	int i=0;
	struct student Students[100];
	
	// Fetch dataMahasiswa.txt
	FILE *fdm = fopen("dataMahasiswa.txt", "r");
	while(!feof(fdm)){
		fscanf(fdm, "%[^#]#%[^#]#%[^\n]\n", Students[i].nim, Students[i].name, Students[i].major);
		i++;
	}
	fclose(fdm); 
	// Print list dataMahasiswa
	system("cls");
	printf("                       List of Student Information\n");
	printf("-------------------------------------------------------------------------------------\n");
	printf("| No.|                   Name                   |        Major        |     NIM     |\n");
	printf("-------------------------------------------------------------------------------------\n");
	for(i=0; i < stdTotal; i++){
		printf("| %2d | %-40s | %-19s | %11s |\n", i+1, Students[i].name, Students[i].major, Students[i].nim);
	}
	printf("-------------------------------------------------------------------------------------\n");
}

// Fungsi untuk menampilkan nilaiMahasiswa
void showScore(int stdTotal){
	int i=0;
	struct student Students[100];
	char x[50];
	
	// Fetch nilaiMahasiswa.txt
	FILE *fnm = fopen("nilaiMahasiswa.txt", "r");
	while(!feof(fnm)){
		fscanf(fnm, "%[^#]#%d#%d#%d#%f#%[^\n]\n", Students[i].nim, &Students[i].task, &Students[i].mid, &Students[i].final, &Students[i].total, Students[i].grade);
		/*printf("nim: %s - task: %d - mid: %d - final: %d - total: %.2f - grade: %s\n",
		Students[i].nim, Students[i].task, Students[i].mid, Students[i].final, Students[i].total, Students[i].grade);
		// Buka comment line ini, untuk lihat error saat return variable */
		i++;
	}
	fclose(fnm);
	/*getchar(); // Buka comment line ini, untuk lihat error saat return variable */
	// Print list nilaiMahasiswa
	system("cls");
	printf("                       List of Student Information\n");
	printf("---------------------------------------------------------------------\n");
	printf("| No.|     NIM     |  Task  | Mid Term | Final Term | Total | Grade |\n");
	printf("---------------------------------------------------------------------\n");
	for(i=0; i < stdTotal; i++){
		printf("| %2d | %11s |  %.2f  |   %.2f   |    %.2f    | %.2f |   %-2s  |\n", i+1, Students[i].nim, Students[i].task, Students[i].mid, Students[i].final, Students[i].total, Students[i].grade);
	}
	printf("---------------------------------------------------------------------\n");
}

int main(){
	int stdTotal, menu;
	
	stdTotal = currList();
	do{
		show_menu(stdTotal);
		scanf("%d", &menu); fflush(stdin);
		if (menu == 1){
			inputStudent();
			stdTotal += 1;
		}
		else if (menu == 2){
			showStudent(stdTotal);
			getchar();
		}
		else if (menu == 3){
			showScore(stdTotal);
			getchar();
		}
				
	}while (menu != 0); 
	
	return 0;
}
