#include <evm_operations.h>


/*	printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s",ctime(&t));
	printf("---------------------------------------------------------------------------------------------------------\n");

 printf("\n\n ###### Welcome to Election/Voting 2020 #####");
printf("\n\n 1. Cast the Vote");
printf("\n 2. Find Vote Count(only for admin)");
printf("\n 3. Find leading Candidate(only for admin)");
printf("\n 4. exit");

printf("\n\n Please enter your choice : ");
scanf("%d", &choice);
int a;
switch(choice)
{
case 1: castVote();break;
case 2: votesCount();break;
case 3: a=leadingCandidate(1,1);



        break;
case 4:printf("THANKYOU FOR USING EVM");getch();system("cls");main();
default: printf("\n Error: Invalid Choice!!!\n Please enter a valid Choice");getch();system("cls");
}
}while(choice!=0);

//hold the screen
getchar();

}
*/
int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0;
void menu()
{
    int choice;
    do{
        time_t t;
	time(&t);
	printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s",ctime(&t));
	printf("---------------------------------------------------------------------------------------------------------\n");

 printf("\n\n ###### Welcome to Election/Voting 2020 #####");
printf("\n\n 1. Cast the Vote");
printf("\n 2. Find Vote Count(only for admin)");
printf("\n 3. Find leading Candidate(only for admin)");
printf("\n 4. exit");

printf("\n\n Please enter your choice : ");
scanf("%d",&choice);
int a;
switch(choice)
{
case 1: castVote();break;
case 2: votesCount();break;
case 3: leadingCandidate();



        break;
case 4:printf("THANKYOU FOR USING EVM");//main();
default: printf("\n Error: Invalid Choice!!!\n Please enter a valid Choice");//getch();system("cls");
}
}while(choice!=0);

//hold the screen
//getchar();

}
void castVote(){
    FILE *fptr;
    FILE *fpt1;

    char word[50];

    int line, col;
    printf("Enter your voter id ");
    scanf("%s", word);


    /* Try to open file */
    fptr = fopen("VoterId.txt", "r");

    /* Exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check you have read/write previleges.\n");

        exit(EXIT_FAILURE);
    }


    // check the voter id
    CheckVoterId(fptr, word, &line, &col);

    if (line != -1){
        printf("YOU HAVE ALREADY VOTED");
        //getch();
        //system("cls");
    }
    else
        {
             fclose(fptr);

   fpt1= (fopen("VoterId.txt", "a"));
   if(fpt1 == NULL)
   {
       printf("Error!");
       exit(1);

   }

        fprintf(fpt1," \n %s \n",word);
int choice;
printf("\n\n ### Please choose your Candidate ####\n\n");
printf("\n 1. %s", CANDIDATE1);
printf("\n 2. %s", CANDIDATE2);
printf("\n 3. %s", CANDIDATE3);
printf("\n 4. %s", CANDIDATE4);
printf("\n 5. %s", "None of These");

printf("\n\n Input your choice (1 - 5) : ");
scanf("%d",&choice);


switch(choice){
    case 1: votesCount1++; break;
    case 2: votesCount2++; break;
    case 3: votesCount3++; break;
    case 4: votesCount4++; break;
    case 5: spoiledtvotes++; break;
    default: printf("\n Error: Wrong Choice !! Please retry");
             //hold the screen
            //getchar();
}
printf("\n THANKYOU FOR VOTING !!");

//getch();

//system("cls");
fclose(fpt1);


        }


    // Close file
    fclose(fptr);


menu();
}
void votesCount(){
    system("cls");
int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="passkey";
    do
{

    printf("\n  ========================  ADMIN LOGIN   ========================  ");
    printf(" \n                        USERNAME:-");
	scanf("%s", uname);
	printf(" \n                        PASSWORD:-");
	scanf("%s", pword);
	//strcpy(uname,"admin");
	   // strcpy(pword,"passkey");
	/*    while(i<10)
	{
	    pword[i]=getc();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';*/
	//char code=pword;
	//i=0;
	//scanf("%s",&pword);
	int y=adLogin(uname,pword);

		if(y==1)
	{printf("\n\n ##### Voting Statics ####");
printf("\n %s - %d ", CANDIDATE1, votesCount1);
printf("\n %s - %d ", CANDIDATE2, votesCount2);
printf("\n %s - %d ", CANDIDATE3, votesCount3);
printf("\n %s - %d ", CANDIDATE4, votesCount4);
printf("\n %s - %d ", "Spoiled Votes", spoiledtvotes);
//getch();
//system("cls");
 //menu(); 
	 printf("thankyou");
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
                break;
		//getch();//holds the screen


	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");
                
		//getch();

		}
		//system("cls");

}


//TO CHECK THE VOTER ID IS UNIQUE
int CheckVoterId(FILE *fptr, const char *word, int *line, int *col)//checks if the voter Id is new
{
    char str[BUFFER_SIZE];
    char *pos;

    *line = -1;
    *col  = -1;

    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        *line += 1;

       // Find first occurrence of word in str
        pos = strstr(str, word);

        if (pos != NULL)
        {
            // First index of word in str is
            // Memory address of pos - memory
            // address of str.
            *col = (pos - str);
            break;
        }
    }


    // If word is not found then set line to -1
    if (*col == -1)
        *line = -1;

    return *col;
}
void leadingCandidate(){
    system("cls");
    int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="passkey";
    do
{

    printf("\n  ========================  ADMIN LOGIN   ========================  ");
    printf(" \n                        USERNAME:-");
	scanf("%s", uname);
	printf(" \n                        PASSWORD:-");
	scanf("%s",pword);
	    //strcpy(uname,"admin");
	   //strcpy(pword,"passkey");
	    /*while(i<10)
	{
	    pword[i]=scanf();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;*/
	//scanf("%s",&pword);
	int p =adLogin(uname,pword);
	if(p==1)
	{
	     printf("\n\n  #### Leading Candiate ####\n\n");
     if(votesCount1>votesCount2 && votesCount1>votesCount3 && votesCount1 >votesCount4)
    {printf("\t%s",CANDIDATE1);
   
    menu();
    }
    else if (votesCount2>votesCount3 && votesCount2>votesCount4 && votesCount2 >votesCount1)
    {printf("\t%s",CANDIDATE2);
    
    menu();}
    else if(votesCount3>votesCount4 && votesCount3>votesCount2 && votesCount3 >votesCount1)
    {printf("\t%s",CANDIDATE3);
   
    menu();}
    else if(votesCount4>votesCount1 && votesCount4>votesCount2 && votesCount4 >votesCount3)
    {printf("\t%s",CANDIDATE4);
    
    menu();}
    else
    {printf("----- Warning !!! No-win situation----");}
    
    menu();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		//getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");

		//getch();

		}
		//system("cls");

   }



int main()
{   int id;
printf("\n  ========================  BOOTH LOGIN   ========================  ");
printf(" \n                        BOOTH ID:-");
 scanf("%d",&id);
 boothid(id);
 return 0;
}
