#include <stdio.h>

FILE *fp;
void addHumanScore(int);
void addComputerScore(int);
void showScore();

int res;
char count = 1;
int score_old = 0;
unsigned char fbuf[sizeof(int)];
int humanScore = 0;
int computerScore = 0;


unsigned char * toArray(int number)
    {			
		fbuf[0] = (number >> 24) & 0xFF;
		fbuf[1] = (number >> 16) & 0xFF;
		fbuf[2] = (number >> 8) & 0xFF;
		fbuf[3] = number & 0xFF;
        return fbuf;
    }
int toInt(void)
{
	int old_score = 0;
	old_score = (old_score << 8) + fbuf[0];
	old_score = (old_score << 8) + fbuf[1];
	old_score = (old_score << 8) + fbuf[2];
	old_score = (old_score << 8) + fbuf[3];
	return old_score;
}
void print_score(void)
{
printf("%s","---------------Score Table------------------\n");
printf("human Score - %d      computer Score - %d \n",humanScore,computerScore);

}
void addHumanScore(int score)
{
int score_old = 0;
if ((fp = fopen("score","rb"))== NULL)
	{
	fp = fopen ("score","wb");
	fseek(fp,0,SEEK_SET);
	toArray(score);
	fwrite(&fbuf,sizeof(int),1,fp);
	toArray(0);
	fwrite(&fbuf,sizeof(int),1,fp);
	fclose(fp);
	}
else
	{
	fclose(fp);
	fp = fopen ("score","rb+");
	fread(&fbuf,sizeof(int),1,fp);
	score_old = toInt();
	score = score_old + score; 
	fseek(fp,0,SEEK_SET);
	toArray(score);
	fwrite(&fbuf,sizeof(int),1,fp);
	fclose(fp);
	}
}
void addComputerScore(int score)
{
int score_old = 0;
if ((fp = fopen ("score","rb")) == NULL)
	{
	fp = fopen ("score","wb");
	toArray(0);
	fwrite(&fbuf,sizeof(int),1,fp);
	toArray(score);
	fwrite(&fbuf,sizeof(int),1,fp);
	fclose(fp);
	
	}
else
	{
	fclose(fp);
	fp = fopen ("score","rb+");
	fseek(fp,sizeof(int),SEEK_SET);
	fread(&fbuf,sizeof(int),1,fp);
	score_old = toInt();
	score = score_old + score; 
	fseek(fp,sizeof(int),SEEK_SET);
	toArray(score);
	fwrite(&fbuf,sizeof(int),1,fp);
	fclose(fp);
	}
}
void showScore()
{
if ((fp = fopen("score","rb"))== NULL)
{
	fp = fopen ("score","wb");
	fseek(fp,0,SEEK_SET);
	toArray(0);
	fwrite(&fbuf,sizeof(int),1,fp);
	toArray(0);
	fwrite(&fbuf,sizeof(int),1,fp);
	fclose(fp);
	print_score();
}
else
{
fread(&fbuf,sizeof(int),1,fp);
humanScore = toInt();
fread(&fbuf,sizeof(int),1,fp);
computerScore = toInt();
fclose(fp);
print_score();
}

}