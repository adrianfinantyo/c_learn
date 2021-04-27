// GLobal module
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
// Local module
#include "kursi_bioskop.h"
#include "randomize.h"

// time_t t = time(NULL);
// char * time_str = ctime(&t);
// time_str[strlen(time_str)-1] = '\0';

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
    char location[5][30];
};

void fetch_user(){
    headUser = NULL;
    FILE *fuser = fopen("userdb.txt", "r");
    while(!feof(fuser)){
        nodeUser = (struct user*)malloc(sizeof(struct user));
        fscanf(fuser, "%[^#]#%[^#]#%[^#]#%[^\n]\n", nodeUser->id, nodeUser->username, nodeUser->pass, nodeUser->name);
        if(headUser == NULL)
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

    int random;
    system("cls");
    printf("\n\n\t=============================================\n");
    printf("\t|                  SIGN UP                  |\n");
    printf("\t=============================================\n");
    printf("\tNAME\t\t: "); scanf("%[^\n]", newUser.name); getchar();
    printf("\tUSERNAME\t: "); scanf("%s", newUser.username); getchar();
    printf("\tPASSWORD\t: "); scanf("%s", newUser.pass); getchar();
    //printf("\tID\t\t: "); scanf("%s", newUser.id); getchar();
    //random = randomNumber(4);
    //itoa(random, newUser.id, 10);
    snprintf(newUser.id, sizeof(newUser.id), "%d", randomNumber(4));
    bool match = 0;
    nodeUser = headUser;
    if(headUser != NULL){
        while(nodeUser != NULL){
            if(!strcmp(newUser.username, nodeUser->username)){
                match = 1;
                printf("\a\n\tUsername already exists!\n");
                printf("\tPress any key to continue...\n\t");
                getchar();
                addUser();
                break;
            }
            else
                nodeUser = nodeUser->next;
        }
    }
    if(!match){
        printf("\t%s#%s#%s#%s\n", newUser.id, newUser.username, newUser.pass, newUser.name);
        fetch_user();
        printf("\n\tSuccess! New user added to database\n\tPress any key to continue...\n\t");
        getchar();
    }
    
    FILE *fp = fopen("userdb.txt", "a");
    fprintf(fp, "%s#%s#%s#%s\n", newUser.id, newUser.username, newUser.pass, newUser.name);
    fclose(fp);
}

int login(){
    struct user logtmp;
    int login_menu;
    bool flag = 0;

    time_t t = time(NULL);
    char * time_str = ctime(&t);
    time_str[strlen(time_str)-1] = '\0';

    do{
        system("cls");
        printf("\n\n\t=============================================\n");
        printf("\t|           WELCOME TO CINEMA BOBO!         |\n");
        printf("\t|\t   %s         |\n", time_str);
        printf("\t=============================================\n");
        printf("\t|  1. SIGNUP                                |\n");
        printf("\t|  2. LOGIN                                 |\n");
        printf("\t|  3. EXIT                                  |\n");
        printf("\t=============================================\n");
        printf("\n\tChoose : "); scanf("%d", &login_menu); getchar();
        if(login_menu == 1){
            addUser();
            fetch_user();
            flag = 1;
        }
        else if(login_menu == 2){
            system("cls");
            printf("\n\n\t=============================================\n");
            printf("\t|                   LOGIN                   |\n");
            printf("\t=============================================\n");
            printf("\tUSERNAME\t : "); scanf("%s", logtmp.username); getchar();
            printf("\tPASSWORD\t : "); scanf("%s", logtmp.pass); getchar();

            nodeUser = headUser;
            if(headUser != NULL){
                while(nodeUser != NULL){
                    if(!strcmp(nodeUser->username, logtmp.username))
                        if(!strcmp(nodeUser->pass, logtmp.pass)){
                            flag = 1;
                            break;
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
    } while(flag == 0);
    printf("\n\tLOGIN SUCCESS\n\n"); 
    printf("\tHello %s, Welcome!\n\n", nodeUser->name);
    getchar();

    return 0;
}

int movieDetails(){
    struct detailFilm film[8];
    int pilih, choose, i = 0;
    FILE *fp = fopen("fmdetail.txt", "r");
    while(!feof(fp)){
        fscanf(fp, "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", film[i].title, film[i].genre, film[i].duration, film[i].censorRating, film[i].synopsis);
        i++;
    }
    fclose(fp);
    system("cls");
    printf("=====================================================================================\n");
    printf("					MOVIES                                      |\n");
    printf("=====================================================================================\n");

    printf("1.\n");
    printf("--------------------------------------------------------------\n");
    printf("| ****   ***  ****      ****  **** *    * ***** *    *  **** |\n");
    printf("| *   * *   * *	  *    *      *    **   *   *   *    * *     |\n");
    printf("| ****  ***** *   *    * **** **** * *  *   *   *    *  ***  |\n");
    printf("| *   * *   * *   *    *    * *    *  * *   *   *    *     * |\n");
    printf("| ****  *   * ****      ****  **** *   ** *****  ****  ****  |\n");
    printf("--------------------------------------------------------------\n\n");

    printf("2.\n");
    printf("------------------------------------------------------------------------------------\n");
    printf("| ***** ****    ***  ***** *    *   *****  ****    ****  *    *  ****  ***  *    * |\n");
    printf("|   *   *   *  *   *   *   **   *     *   *    *   *   * *    * *     *   * **   * |\n");
    printf("|   *   ****   *****   *   * *  *     *   *    *   ****  *    *  ***  ***** * *  * |\n");
    printf("|   *   *   *  *   *   *   *  * *     *   *    *   *   * *    *     * *   * *  * * |\n");
    printf("|   *   *    * *   * ***** *   **     *    ****	   ****   ****  ****  *   * *   ** |\n");
    printf("------------------------------------------------------------------------------------\n\n");

    printf("3.\n");
    printf("-----------------------------\n");
    printf("|  ****  ****  *    * *     |\n");
    printf("| *     *    * *    * *     |\n");
    printf("|  ***  *    * *    * *     |\n");
    printf("|     * *    * *    * *     |\n");
    printf("| ****   ****   ****  ***** |\n");
    printf("-----------------------------\n\n");

    printf("4.\n");
    printf("----------------------------------------------------------------------\n");
    printf("| ****  *****  ****     ****  ****    ****  ***** *   * ***** ****   |\n");
    printf("| *   *   *   *         *   * *   *  *    *   *   *   * *     *   *  |\n");
    printf("| ****    *   * ****    ****  ****   *    *   *   ***** ***** ****   |\n");
    printf("| *   *   *   *	   *    *   * *   *  *    *   *   *   * *     *   *  |\n");
    printf("| ****  *****  ****     ****  *    *  ****    *   *   * ***** *    * |\n");
    printf("----------------------------------------------------------------------\n\n");

    printf("5.\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("| ***** ***** *    * ****  ***** *    *  ****      ****  *   *  ***  *    *  ***  |\n");
    printf("| * 	  *   **   * *   *   *   **   * *         *    * *   * *   * **   * *   * |\n");
    printf("| *****   *   * *  * *   *   *   * *  * * ****    *    * ***** ***** * *  * ***** |\n");
    printf("| *	  *   *  * * *   *   *   *  * * *    *    *    * *   * *   * *  * * *   * |\n");
    printf("| *     ***** *   ** ****  ***** *   **  ****      ****  *   * *   * *   ** *   * |\n");
    printf("-----------------------------------------------------------------------------------\n\n");

    printf("6.\n");
    printf("-----------------------------------------------------------------\n");
    printf("| **** *   * ***** ****    ***   **** ***** *****  ****  *    * |\n");
    printf("| *     * *    *   *   *  *   * *	*     *   *    * **   * |\n");
    printf("| ****   *     *   ****   ***** *	*     *   *    * * *  * |\n");
    printf("| *     * *    *   *   *  *   * *       *     *   *    * *  * * |\n");
    printf("| **** *   *   *   *    * *   *  ****   *   *****  ****  *   ** |\n");
    printf("-----------------------------------------------------------------\n\n");

    printf("7.\n");
    printf("-----------------------------\n");
    printf("|  ****  ****   ****  ****  |\n");
    printf("| *     *    * *     *    * |\n");
    printf("| *     *    * *     *    * |\n");
    printf("| *     *    * *     *    * |\n");
    printf("|  ****  ****   ****  ****  |\n");
    printf("-----------------------------\n\n");

    printf("8.\n");
    printf("--------------------------------------------\n");
    printf("| *     *  ****  *    * ****  ***** ****   |\n");
    printf("| *     * *    * **   * *   * *     *   *  |\n");
    printf("| *  *  * *    * * *  * *   * ***** ****   |\n");
    printf("| * * * * *    * *  * * *   * *     *   *  |\n");
    printf("|  *   *   ****  *   ** ****  ***** *    * |\n");
    printf("--------------------------------------------\n\n");

    printf("\nChoose movie : "); scanf("%d", &pilih); getchar();
    system("cls");
    printf("Title         : %s\n", film[pilih - 1].title);
    printf("Genre         : %s\n", film[pilih - 1].genre);
    printf("Duration      : %s\n", film[pilih - 1].duration);
    printf("Censor Rating : %s\n", film[pilih - 1].censorRating);
    printf("Synopsis      :\n%s\n\n", film[pilih - 1].synopsis);
    printf("1. Choose this movie\n");
    printf("2. Back\n");
    printf("Choose : ");
    scanf("%d", &choose);

    if(choose == 2){
        movieDetails();
    }
    return pilih;
}

void movieDetails_locs(){
    char cinemas[30];
    int lokasi, i = 1;
    struct detailFilm film[8];

    int pilih = movieDetails();
    system("cls"); //system("cls");
    printf("---------------------------\n");
    printf("          CINEMAS\n");
    printf("---------------------------\n");
    FILE *loc = fopen("filmlokasi.txt", "r");
    while(!feof(loc) && i <= 4){
        fscanf(loc, "%[^#]#%[^#]#%[^#]#%[^#]#%[^\n]\n", film[pilih - 1].title, film[pilih - 1].location[0], film[pilih - 1].location[1], film[pilih - 1].location[2], film[pilih - 1].location[3]);
        printf("%d. %s\n", i, film[pilih - 1].location[i - 1]);
        i += 1;
    }
    fclose(loc);
    printf("\nChoose location : "); scanf("%d", &lokasi); getchar();
    system("cls");
}

int main(){
    int menu;
    // Menload data dari txt
    fetch_user();
    system("color 4f");
    if(login())
        return 0;
    else{
        system("cls");
        movieDetails_locs();
        inputChair();
        getchar();
    }

    return 0;
}