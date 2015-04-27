#include <stdio.h>
//#include "score.h"

int menu();
void getName();
void getSymbol();
int gameMain();

char name[20] = "Anonimous";
char symbol = 'X';


int main(int argc, char const *argv[])
 {
 	int menuState = menu();

 	if (menuState == 4)
 	{
 		system("cls");
 		printf("Starting the game!\n\n\n");
 		printf("Your name is: \"%s\". You're playing as \"%c\" \n\n", name, symbol);
 		int gameStatus = gameMain();
 	}
 	else if (menuState == 5)
 	{
 		printf("Exiting the game!\n");
 		return 0;
 	}
 	
 	
 }

 int menu()
 {
 	int menuState;
 	while (menuState != 4 && menuState != 5)
 	{
 		menuState = 0;
 		printf("What do you whant to do?\n");
 		printf("\t 1. Enter your name. \n");
 		printf("\t 2. Choose \"X\" or \"0\" symbol (default: \"X\" symbol).\n");
 		printf("\t 3. Read Score.\n");
 		printf("\t 4. Start game.\n");
 		printf("\t 5. Exit game.\n");
 		printf("Select number: ");
 		
 		scanf ("%d", &menuState);
 		fflush(stdin);

 		if (menuState < 1 || menuState > 5)
 			printf("Error! Please enter correct menu number");
 		else if (menuState == 1)
 			getName();
 		else if (menuState == 2)
 			getSymbol();
		else if (menuState == 3)
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
 		printf("\nError! You've input wrong symbol! The symbol wasn't changed. symbol is: \"%c\" (default value)\n\n", symbol);
 	}
}

int gameMain()
{

}