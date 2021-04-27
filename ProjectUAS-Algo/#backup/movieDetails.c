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
            printf("* 	    *   **   * *   *   *   **   * *         *    * *   * *   * **   * *   *\n");
            printf("*****   *   * *  * *   *   *   * *  * * ****    *    * ***** ***** * *  * *****\n");
            printf("*	    *   *  * * *   *   *   *  * * *    *    *    * *   * *   * *  * * *   *\n");
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