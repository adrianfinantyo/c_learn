#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define bool int

struct user{
  char name[50];
  char username[20];
  char pass[20];
  char id[5];
  struct user *next;
}*headUser, *tailUser, *nodeUser;

struct detailFilm{
  char title[60];
  char genre[50];
  char duration[30];
  char censorRating[10];
  char synopsis[700];
};

void fetch_user(){
  headUser = NULL;
  FILE *fuser = fopen("userdb.txt", "r");
  while(!feof(fuser)){
    nodeUser = (struct user*)malloc(sizeof(struct user));
    fscanf(fuser, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nodeUser->id, nodeUser->username, nodeUser->pass, nodeUser->name);
    if(headUser==NULL)
      headUser = tailUser = nodeUser;
    else{
      tailUser->next = nodeUser;
      tailUser = nodeUser;
    }
    nodeUser->next = NULL;
  }
  fclose(fuser);
}

void addUser(){
	struct user newUser;
	system("cls");
	printf("Add New User\n");
	printf("Name\t\t: "); scanf("%[^\n]", newUser.name);getchar();
	printf("Username\t: "); scanf("%s", newUser.username); getchar();
	printf("Password\t: "); scanf("%s", newUser.pass); getchar();
	printf("ID\t\t: "); scanf("%s", newUser.id); getchar();
	printf("%s#%s#%s#%s\n", newUser.id, newUser.username, newUser.pass, newUser.name);
	FILE *fp = fopen("userdb.txt", "a");
	fprintf(fp, "%s#%s#%s#%s\n", newUser.id, newUser.username, newUser.pass, newUser.name);
	fclose(fp);
	fetch_user();
	printf("\nSuccess! New user added to database\nPress any key to continue...\n"); getchar();
}

int login(){
  struct user logtmp;
  int login_menu;
  bool flag=0;

  do{
	system("cls");
	printf("          Welcome to Cinema BOBO!\n");
	printf("---------------------------------------------\n\n");
	printf("1. Signup\n");
	printf("2. Login\n");
	printf("3. EXIT\n");
	printf("\nChoose : ");
	scanf("%d", &login_menu); getchar();
	if(login_menu == 1){
		addUser();
		flag = 1;
	}
	else if(login_menu == 2){
		system("cls");
		printf("    User Login Interface\n");
		printf("-------------------------------\n\n");
	    printf("Username\t : "); scanf("%s", logtmp.username); getchar();
	    printf("Password\t : "); scanf("%s", logtmp.pass); getchar();
	
	    nodeUser = headUser;
	    if(headUser != NULL){
	      while(nodeUser != NULL){
	        if(!strcmp(nodeUser->username, logtmp.username))
	        	if(!strcmp(nodeUser->pass, logtmp.pass)){
	        		flag = 1; break;
				}
				else
					break;
	        else
	          	nodeUser = nodeUser->next;
	      }
	    }
	    if(flag == 0){
	    	printf("\a\nInvalid username or password\n");
	    	printf("Press any key to continue...");
	    	getchar();
		}
	}
	else if(login_menu == 3){
		return 1;
	}

  }while(flag == 0);
 printf("\nLOGIN SUCCESS\n"); getchar();

 return 0;
}

int movieDetails(){
  struct detailFilm film[8];
  int i=0;
  char pilih[60];
  FILE *fp = fopen("fmdetail.txt", "r");
  while(!feof(fp)){
    fscanf(fp, "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", film[i].title, film[i].genre, film[i].duration, film[i].censorRating, film[i].synopsis);
    i++;
  }
  fclose(fp);
  system("cls");
  for(i=0; i<8; i++){
        if(i==0)
        {
            printf("****   ***  ****      ****  **** *    * ***** *    *  ****\n");
            printf("*   * *   * *	*    * 	    *    **   *   *   *    * *\n");
            printf("****  ***** *   *    * **** **** * *  *   *   *    *  ***\n");
            printf("*   * *   * *   *    *	  * *    *  * *   *   *    *     *\n");
            printf("****  *   * ****      ****  **** *   ** *****  ****  ****\n");
        }
        else if(i==1)
        {
            printf("***** ****    ***  ***** *    *    *****  ****     ****  *    *  ****  ***  *    *\n");
            printf("  *   *   *  *   *   *   **   *      *	 *    *	   *   * *    * *     *   * **   *\n");
            printf("  *   ****   *****   *   * *  *      *	 *    *	   ****  *    *  ***  ***** * *  *\n");
            printf("  *   *   *  *   *   *   *  * *      *	 *    *	   *   * *    *     * *   * *  * *\n");
            printf("  *   *    * *   * ***** *   **      *	  ****	   ****   ****  ****  *   * *   **\n");
        }
        else if(i==2)
        {
            printf(" ****  ****  *    * *\n");
            printf("*     *    * *    * *\n");
            printf(" ***  *    * *    * *\n");
            printf("    * *    * *    * *\n");
            printf("****   ****   ****  *****\n");
        }
        else if(i==3)
        {
            printf("****  *****  ****     ****  ****    ****  ***** *   * ***** ****\n");
            printf("*   *   *   *         *   * *   *  *    *   *   *   * *     *   *\n");
            printf("****    *   * ****    ****  ****   *    *   *   ***** ***** ****\n");
            printf("*   *   *   *	 *    *   * *   *  *    *   *   *   * *     *   *\n");
            printf("****  *****  ****     ****  *    *  ****    *   *   * ***** *    *\n");
        }
        else if(i==4)
        {
            printf("***** ***** *    * ****  ***** *    *  ****      ****  *   *  ***  *    *  *** \n");
            printf("* 	*   **   * *   *   *   **   * *         *    * *   * *   * **   * *   *\n");
            printf("*****   *   * *  * *   *   *   * *  * * ****    *    * ***** ***** * *  * *****\n");
            printf("*	*   *  * * *   *   *   *  * * *    *    *    * *   * *   * *  * * *   *\n");
            printf("*     ***** *   ** ****  ***** *   **  ****      ****  *   * *   * *   ** *   *\n");
        }
        else if(i==5)
        {
            printf("**** *   * ***** ****    ***   **** ***** *****  ****  *    *\n");
            printf("*     * *    *   *   *  *   * *	      *	    *   *    * **   *\n");
            printf("****   *     *   ****   ***** *	      *	    *   *    * * *  *\n");
            printf("*     * *    *   *   *  *   * *	      *	    *   *    * *  * *\n");
            printf("**** *   *   *   *    * *   *  ****   *	  *****  ****  *   **\n");
        }
        else if(i==6)
        {
            printf(" ****  ****   ****  ****\n");
            printf("*     *    * *     *    *\n");
            printf("*     *    * *     *    *\n");
            printf("*     *    * *     *    *\n");
            printf(" ****  ****   ****  ****\n");
        }
        else
        {
            printf("*     *  ****  *    * ****  ***** ****\n");
            printf("*     * *    * **   * *   * *     *   *\n");
            printf("*  *  * *    * * *  * *   * ***** ****\n");
            printf("* * * * *    * *  * * *   * *     *   *\n");
            printf(" *   *   ****  *   ** ****  ***** *    *\n");
        }

        printf("Title         : %s\n", film[i].title);
        printf("Genre         : %s\n", film[i].genre);
        printf("Duration      : %s\n", film[i].duration);
        printf("Censor Rating : %s\n", film[i].censorRating);
        printf("Synopsis      :\n%s\n\n", film[i].synopsis);
  }
  getchar();
  printf("Choose movie : ");
  scanf("%[^\n]", pilih); getchar();
  system("cls");
}

void location(){
  char cinemas[30];
  int i = 0;
  char lokasi[30];

  system("cls");
  printf("          Cinemas\n");
  printf("---------------------------\n");
  FILE *loc = fopen("location.txt", "r");
  if(loc){
    while (!feof(loc)){
      fscanf(loc, "%[^\n]\n", cinemas);
      i += 1;
      printf("%d. %s\n", i, cinemas);
    }
  }
  fclose(loc);
  printf("Choose location : "); getchar();
  scanf("%[^\n]", lokasi); getchar();
  printf("Congratulation, this movie is available at %s\n", lokasi);
  getchar();
  system("cls");
}

void showmenu(){
	//system("cls");
	//printf("Hello %s, Welcome!\n\n", nodeUser->name);
  int pilih;
  system("cls");
  printf("Hello %s, Welcome!\n\n", nodeUser->name);
	printf("1. Movie Details \n");
	printf("2. Choose Location\n");
	printf("3. Choose Seat\n");
	printf("4. Ticket Checkout\n");
	printf("0. Exit\n");
	printf("Choose menu : ");
  scanf("%d", &pilih); fflush(stdin);
  printf("\n");
  if(pilih==1)
  {
    movieDetails();
    showmenu();
  }
  else if(pilih==2)
  {
    location();
    showmenu();
   }
  else if(pilih==0)
  {
    exit(0);
  }
  else{
	printf("This menu is not ready for now, please come back soon.\n"); getchar();
	showmenu();
  }
	
}

int main() {
	int menu;
	fetch_user();	//Menload data dari txt
	if(login())
		return 0;
	else{
		do{
      system("cls");
			showmenu();
			scanf("%d", &menu); fflush(stdin);
			if(menu == 1)
			getchar();
		}while(menu != 0);
	}
  	return 0;
}

