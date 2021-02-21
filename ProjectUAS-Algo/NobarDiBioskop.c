#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

struct user{
  char name[50];
  char usrname[20];
  char pass[20];
  int id;
  struct user *next;
}*head, *tail, *curr;

void fetch_user(){
  int i=0;
  
  FILE *fuser = fopen("userdb.txt", "r");
  curr = (struct user*)malloc(sizeof(struct user));
  curr->next = NULL;
  for(i=0; i<2; i++){
    //fscanf(fuser, "%[^#]#%[^#]#%d#%[^\n]\n", curr->usrname, curr->pass, &curr->id, curr->name);
    gets(curr->usrname); gets(curr->pass);
    if(head==NULL)
      head = tail = curr;
    else{
		tail->next = curr;
		tail = curr;
	}
  }
  fclose(fuser);
  getch();
  curr = head;
  if(head != NULL)
	{
		while(curr != NULL)
		{
			printf("%s-%s-%d-%s\n", curr->usrname, curr->pass, curr->id, curr->name);
			curr = curr->next;
		}
	}
	else
			printf("TIDAK ADA DATA!\n");
	getchar();
}

int login(){
  struct user logtmp;
  bool flag;

  fetch_user();
  do{
    printf("username\t :"); scanf("%s", logtmp.usrname); fflush(stdin);
    printf("password\t :"); scanf("%s", logtmp.pass); fflush(stdin);

    curr = head;
    if(head != NULL){
      while(curr != NULL){
        if(strcmp(curr->usrname, logtmp.usrname))
          flag = 1;
        else
          curr = curr->next;
      }
    }
  }while(flag == 0);
 printf("LOGIN SUKSES"); getchar();

 return 0;
}

int main() {
  
  login();

  return 0;
}
