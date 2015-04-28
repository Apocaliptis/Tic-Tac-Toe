#include <stdio.h>
//#include "score.h"
#define ERROR 666

	/*Define difficulty level*/
#define EASY 1
#define MEDIUM 2
#define HARD 3

int menu();
void getName();
void getSymbol();
void askDifficulty();
int gameMain();
int checkWin();

char name[20] = "Anonimous";
char symbol = 'X';
int difficulty = MEDIUM;


int main(int argc, char const *argv[])
 {
 	int menuState = menu();

 	if (menuState == 5)
 	{
 		system("cls");
 		printf("Starting the game!\n\n\n");
 		printf("Your name is: \"%s\".\tYou're playing as \"%c\".\tDifficulty is: %d.\n\n", name, symbol, difficulty);
 		int gameStatus = gameMain();
 	}
 	else if (menuState == 6)
 	{
 		printf("Exiting the game!\n");
 		return 0;
 	}
 	
 	
 }

 int menu()
 {
 	int menuState;
 	while (menuState != 5 && menuState != 6)
 	{
 		menuState = 0;
 		printf("What do you whant to do?\n");
 		printf("\t 1. Enter your name. \n");
 		printf("\t 2. Choose \"X\" or \"0\" symbol (default: \"X\" symbol).\n");
 		printf("\t 3. Choose difficulty. (Default Medium difficulty is selected)\n");
 		printf("\t 4. Read Score.\n");
 		printf("\t 5. Start game.\n");
 		printf("\t 6. Exit game.\n");
 		printf("Select number: ");
 		
 		scanf ("%d", &menuState);
 		fflush(stdin);

 		if (menuState < 1 || menuState > 6)
 			printf("Error! Please enter correct menu number");
 		else if (menuState == 1)
 			getName();
 		else if (menuState == 2)
 			getSymbol();
 		else if (menuState == 3)
 			askDifficulty();
		else if (menuState == 4)
			printf("showScore();\n");
//			showScore();
 			
 	}
 	return (menuState);
 }


void getName ()
{
	printf("\nPlease input your name: ");
	gets(name);
	printf("\nOk! Your name now is: %s\n\n", name);
}

void getSymbol()
{
	printf("\nPlease select your symbol: \"X\" or \"0\": ");
 	symbol = getchar();
 	fflush(stdin);
 	if (symbol == 'X' || symbol == '0')
 		printf("\nOk! Your symbol now is: \"%c\"\n\n", symbol);
 	else
 	{
 		symbol = 'X';
 		printf("\nError! You've input wrong symbol! The symbol wasn't changed. Symbol is: \"%c\" (default value)\n\n", symbol);
 	}
}

void askDifficulty()
{
	printf("Difficulty levels:\n");
	printf("\t%d. Easy.\n", EASY);
	printf("\t%d. Medium.\n", MEDIUM);
	printf("\t%d. Hard.\n", HARD);
	printf ("Please select difficulty number: ");
	scanf ("%d", &difficulty);
	fflush(stdin);
}

int gameMain()
{
	while (checkWin() != 1)
	{
		if (symbol == 'X')
		{
			humanMove('X');
			if (checkWin() == 1)
				return 1;
			computerMove('0');
			if (checkWin() == 1)
				return 0;
		}
		else if (symbol == '0')
		{
			computerMove('X');
			if (checkWin() == 1)
				return 1;
			humanMove('0');
			if (checkWin() == 1)
				return 0;
		}
	}
	return (ERROR);
}

int checkWin()
{

}