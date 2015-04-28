#include <stdio.h>
//#include "score.h"


	/*Define cell type*/
#define EMPTY 0
#define Symbol_X 1
#define Symbol_0 2


	/*Define end of game status*/
#define NO_WIN 0
#define DRAW 1
#define WIN 2
#define WIN_X 3
#define WIN_0 4

	/*Define difficulty level*/
#define EASY 1
#define MEDIUM 2
#define HARD 3

int menu();
void askName();
void askSymbol();
void askDifficulty();
int gameMain();
int checkWin();
char *getName();
int getDifficulty();
char getSymbol();

char name[100] = "Anonimous";
char symbol = 'X';
int difficulty = MEDIUM;


int main(int argc, char const *argv[])
 {
 	int menuState;
 	CONTINUE:
 	menuState = menu();

 	if (menuState == 5)
 	{
 		system("cls");
 		printf("Starting the game!\n\n\n");
 		printf("Your name is: \"%s\".\tYou're playing as \"%c\".\tDifficulty is: %d.\n\n", name, symbol, difficulty);
 		initfield();
 		int gameStatus = gameMain();
 		if ((gameStatus == WIN_0 && symbol == '0') || (gameStatus == WIN_X && symbol == 'X'))
 		{
 			printf("\nCongratulations! %s wins!\n", name);
 			addHumanScore();
 		}
 		if ((gameStatus == WIN_0 && symbol == 'X') || (gameStatus == WIN_X && symbol == '0'))
 		{
 			printf("\nYou lose... Don't be sad!\n");
 			addComputerScore();
 		}
 		if (gameStatus == DRAW)
 			printf("\nDraw game!\n");
 	}
 	else if (menuState == 6)
 	{
 		printf("Exiting the game!\n");
 		return 0;
 	}
 	printf("Do you want to play again?\n\t1. Yes\n\t2. No\n");
 	int contin;
 	scanf ("%d", &contin);
 	fflush(stdin);
 	if (contin == 1)
 		goto CONTINUE;
 	else
 		return 0;
 }

 int menu()
 {
 	int menuState;
 	while (menuState != 5 && menuState != 6)
 	{
 		menuState = 0;
 		printf("What do you want to do?\n");
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
 			askName();
 		else if (menuState == 2)
 			askSymbol();
 		else if (menuState == 3)
 			askDifficulty();
		else if (menuState == 4)
			printf("showScore();\n");
//			showScore();
 			
 	}
 	return (menuState);
 }


void askName ()
{
	printf("\nPlease input your name: ");
	gets(name);
	printf("\nOk! Your name now is: %s\n\n", name);
}

void askSymbol()
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
	while (checkWin() == NO_WIN)
	{
		if (symbol == 'X')
		{
			humanMove('X');
			if (checkWin() == WIN)
				return (WIN_X);
			computerMove('0');
			if (checkWin() == WIN)
				return (WIN_0);
		}
		else if (symbol == '0')
		{
			computerMove('X');
			if (checkWin() == WIN)
				return (WIN_X);
			humanMove('0');
			if (checkWin() == WIN)
				return (WIN_0);
		}
	}
	return (DRAW);
}

int checkWin()
{
	int template[3][3];
	int i, j;
	int k = 0;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
		{
			template[i][j] = getField(i, j);
			if (template[i][j] == EMPTY)
				++k;
		}
	
	if (k == 0)
		return (DRAW);

	for (i = 0, j = 0; i < 4; ++i)
			if (template[i][j] == template[i][j + 1] == template[i][j + 2])
				return (WIN);
	for (i = 0, j = 0; j < 4; ++j)
			if (template[i][j] == template[i + 1][j] == template[i + 2][j])
				return (WIN);
	if ((template[1][1] == template[2][2] == template[3][3]) || (template[1][3] == template[2][2] == template[3][1]))
		return (WIN);
	
	return NO_WIN;
}

char *getName()
{
	return (name);
}

int getDifficulty()
{
	return (difficulty);
}

char getSymbol()
{
	return(symbol);
}