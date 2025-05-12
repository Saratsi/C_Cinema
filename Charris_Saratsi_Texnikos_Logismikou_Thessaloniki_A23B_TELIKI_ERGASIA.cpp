#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MONTHS 12           //ДГКЫСГ СТАХЕЯЫМ
#define ROWS 10
#define MAX_WORDS 20

int main(void)
{
	system("CHCP 1253 > nul");
	
	char room[ROWS][MAX_WORDS],month[MONTHS][MAX_WORDS];
	float money[ROWS][MONTHS], average[ROWS], counter, min;        //ДГКЫСГ ЛЕТАБКГТЫМ
	int i, j, k, breaker;
	
	//омолафомтас окоус тоус лгмес циа олояжиа.
	strcpy(month[0], "иамоуаяио");
    strcpy(month[1], "жебяоуаяио");
    strcpy(month[2], "лаятио");
    strcpy(month[3], "апяикио");
    strcpy(month[4], "лаио");
    strcpy(month[5], "иоумио");
    strcpy(month[6], "иоукио");
    strcpy(month[7], "ауцоусто");
    strcpy(month[8], "септелбяио");
    strcpy(month[9], "ойтыбяио");
    strcpy(month[10], "моелбяио");
    strcpy(month[11], "дейелбяио");	
	//фгтаеи апо том пекатг тоус йыдийоус тым аихоусым.
    for (i = 0; i<ROWS; i++)
    {
        printf("дЫСЕ ТОУР ЙЫДИЙО ТГР АИХОУСАР %d: ", i + 1);
        gets(room[i]);
        printf("\n");
        k=i;
        //екемвеи ам о йыдийос йапоиас аиуоусас еимаи идиос ле лиа аккг ле strcmp йаи нама фгта йыдийо.
        while(k>0)
        {
        	strcmp(room[i],room[k-1]);
        	if(strcmp(room[i],room[k-1])==0)
        	{
        	  printf("O ЙЫДИЙО ТГР АИХОУСАР %d ЕИМАИ ИДИОР ЛЕ ТОМ ЙЫДИЙО ТГР АИХОУСАР %d.дЫСЕ ПАКИ ЙЫДИЙО \a: ", i + 1, k);
        	  gets(room[i]);
			  printf("\n");       	  
			}
        	else
        	k--;      	
		}
	}
	//ZHTAEI апо том пекатг тис лгмиаиес еиспяанеис йахе аихоусас йаи екемвеи ам г тилг еимаи хетийг.
	for ( i = 0; i<ROWS; i++)
	{
		for(j = 0; j<MONTHS; j++)
		{
		  counter=0;
		  do
		  {
		  	printf("дЫСЕ ТГМ ЛГМИАИА ЕИСПАЯНГ ТГР АИХОУСАР \033[94m%s\033[0m ЦИА ТОМ ЛГМА \033[33m%s\033[0m: ", room[i], month[j]);
		  	scanf("%f", &money[i][j]);
		  	printf("\n");
		  	if(money[i][j]<0)
		    {
		      printf("аЯМГТИЙГ ЛГМИАИА ЕИСПАЯНГ.пЯОСПАХГСЕ ПАКИ :)\n\n\a");
		      breaker=1;
			}
			else
			breaker=0;
		  }while(breaker==1);
		  //летяаеи тис сумокийес еиспанеис йахе аихоусас.
		  counter=counter+money[i][j];
		}
		//бягсйеи тгм лесг тилг еиспанеис йахе аихоусас йаи тгм лийяотеяг лесг тилг.
		average[i]=counter/MONTHS;
		if(i==0)
		min=average[i];
	    if(average[i]<min)
		min=average[i];			
	}
	printf("Please wait while data is being saved...\n\n\n");
	for(i=0; i<15; i++)
	{
		printf("#");
		usleep(200000);
	}
	system("CLS");
	printf("\n\n");
	printf("\t\tMесес_лгмиаиес_еиспяанеис йахе ехоусас\n");
	printf("\t      ---------------------------------------\n\n");
	//елжамифеи лийяотеяг лесг лгмиаиа тилг.
	for ( i = 0; i<ROWS; i++)
	{
		printf("\t\t\033[94m%s\033[0m:\033[32m%.2f$\033[0m\n\n\n",room[i],average[i]);
	}
	printf("\n\n\n");
	//елжамифеи тгм/тис аихоуса/ес ле тгм лийяотеяг лесг лгмиаиа тилг.
	printf("г АИХОУСА/ЕР ЛЕ ТИР ЛИЙЯОТЕЯЕР ЛГМИАИЕР ЕИСПЯАНЕИР ЕИМАИ Г/ОИ: ");	
	for ( i = 0; i<ROWS; i++)
	{
	    if(average[i]==min)
		printf("\033[31m%s\033[0m\t", room[i]);
	}
	printf("\n\n\n");	
	system("PAUSE");
	return 0;
}
