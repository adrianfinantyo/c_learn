#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

struct user{
  char name[50];
  char username[20];
  char pass[20];
  char id[5];
  struct user *next;
}*headUser, *tailUser, *nodeUser;

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
/*	// Bagian ini hanya untuk test dengan menampilan isi linked list
  node = head;
  if(head != NULL)
	{
		while(node != NULL)
		{
			printf("%s-%s-%s-%s\n", node->name, node->usrname, node->pass, node->id);
			node = node->next;
		}
	}
	else
			printf("TIDAK ADA DATA!\n");
	getchar();
*/
}

void addUser(){
	struct user newUser;
	system("cls");
	printf("Add newUser\n");
	printf("Name\t\t: "); scanf("%[^\n]", newUser.name);
	printf("username\t: "); scanf("%s", newUser.username);
	printf("pass\t\t: "); scanf("%s", newUser.pass);
	printf("id\t\t: "); scanf("%s", newUser.id);
	printf("%s#%s#%s#%s\n", newUser.id, newUser.username, newUser.pass, newUser.name);
	FILE *fp = fopen("userdb.txt", "a");
	fprintf(fp, "%s#%s#%s#%s\n", newUser.id, newUser.username, newUser.pass, newUser.name);
	fclose(fp);
	fetch_user();
	printf("\nSuccess! New user added to database\nPress any key to continue..."); getchar();
}

int login(){
  struct user logtmp;
  int login_menu;
  bool flag=0;

  do{
	system("cls");
	printf("\n          Welcome to Cinema BOBO!\n");
	printf("---------------------------------------------\n\n");
	printf("1. Signup\n");
	printf("2. Login\n");
	printf("0. EXIT\n");
	printf("\nChoose > ");
	scanf("%d", &login_menu); fflush(stdin);
	if(login_menu == 1){
		addUser();
		flag = 1;
	}
	else if(login_menu == 2){
		system("cls");
		printf("\n    User Login Interface\n");
		printf("-------------------------------\n\n");
	    printf("username\t :"); scanf("%s", logtmp.username); fflush(stdin);
	    printf("password\t :"); scanf("%s", logtmp.pass); fflush(stdin);
	
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
	else if(login_menu == 0){
		return 1;
	}

  }while(flag == 0);
 printf("LOGIN SUKSES\n"); getchar();

 return 0;
}

void showmenu(){
	system("cls");
	printf("Halo %s, Selamat Datang!\n\n", nodeUser->name);
	printf("1. Untitled\n");
	printf("2. Untitled\n");
	printf("3. Untitled\n");
	printf("4. Untitled\n");
	printf("0. Exit\n");
	printf("Masukan angka untuk menu > ");
}

int main() {
	int menu;
	fetch_user();	//Menload data dari txt
	if(login())
		return 0;
	else{
		do{
			showmenu();
			scanf("%d", &menu); fflush(stdin);
			if(menu == 1)
			getchar();	
		}while(menu != 0);
	}
	
  	return 0;
}
