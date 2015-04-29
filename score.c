#include <stdio.h>

FILE *fp;
void addHumanScore(int);
void addComputerScore(int);
void showScore();

int res;
char count = 1;
int score_old;


int main (void)
{
addHumanScore(365);
addComputerScore(5);
}
void addHumanScore(int score)
{
if ((fp = fopen("score","r"))== NULL)
	{
	fp = fopen ("score","wb");
	fprintf(fp, "%d", score);
	fprintf(fp, "%d", |);
	fclose(fp);
	}
else
	{
	fclose(fp);
	fp = fopen ("score","w");
	fseek(fp,0,SEEK_SET);
	fscanf(fp,"%d",&score_old);
	score = score_old + score; 
	fprintf(fp, "%d", score);
	fclose(fp);
	}
}
void addComputerScore(int score)
{
if ((fp = fopen ("score","r")) == NULL)
	{
	fp = fopen ("score","w");
	fprintf(fp, "%d", 0);
	fprintf(fp, "%d", score);
	fclose(fp);
	}
else
	{
	fclose(fp);
	fp = fopen ("score","w");
	fseek(fp,sizeof(int),SEEK_SET);

	fscanf(fp,"%d",&score_old);
	score = score_old + score; 
	fprintf(fp, "%d", score);
	fclose(fp);
	}
}
void showScore()
{


}