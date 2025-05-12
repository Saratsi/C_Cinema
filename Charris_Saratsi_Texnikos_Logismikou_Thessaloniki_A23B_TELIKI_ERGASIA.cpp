#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MONTHS 12           //������ ��������
#define ROWS 10
#define MAX_WORDS 20

int main(void)
{
	system("CHCP 1253 > nul");
	
	char room[ROWS][MAX_WORDS],month[MONTHS][MAX_WORDS];
	float money[ROWS][MONTHS], average[ROWS], counter, min;        //������ ����������
	int i, j, k, breaker;
	
	//����������� ����� ���� ����� ��� �������.
	strcpy(month[0], "���������");
    strcpy(month[1], "����������");
    strcpy(month[2], "������");
    strcpy(month[3], "�������");
    strcpy(month[4], "����");
    strcpy(month[5], "������");
    strcpy(month[6], "������");
    strcpy(month[7], "��������");
    strcpy(month[8], "����������");
    strcpy(month[9], "��������");
    strcpy(month[10], "��������");
    strcpy(month[11], "���������");	
	//������ ��� ��� ������ ���� �������� ��� ��������.
    for (i = 0; i<ROWS; i++)
    {
        printf("���� ���� ������ ��� �������� %d: ", i + 1);
        gets(room[i]);
        printf("\n");
        k=i;
        //������� �� � ������� ������� �������� ����� ����� �� ��� ���� �� strcmp ��� ���� ���� ������.
        while(k>0)
        {
        	strcmp(room[i],room[k-1]);
        	if(strcmp(room[i],room[k-1])==0)
        	{
        	  printf("O ������ ��� �������� %d ����� ����� �� ��� ������ ��� �������� %d.���� ���� ������ \a: ", i + 1, k);
        	  gets(room[i]);
			  printf("\n");       	  
			}
        	else
        	k--;      	
		}
	}
	//ZHTAEI ��� ��� ������ ��� �������� ���������� ���� �������� ��� ������� �� � ���� ����� ������.
	for ( i = 0; i<ROWS; i++)
	{
		for(j = 0; j<MONTHS; j++)
		{
		  counter=0;
		  do
		  {
		  	printf("���� ��� ������� �������� ��� �������� \033[94m%s\033[0m ��� ��� ���� \033[33m%s\033[0m: ", room[i], month[j]);
		  	scanf("%f", &money[i][j]);
		  	printf("\n");
		  	if(money[i][j]<0)
		    {
		      printf("�������� ������� ��������.���������� ���� :)\n\n\a");
		      breaker=1;
			}
			else
			breaker=0;
		  }while(breaker==1);
		  //������� ��� ��������� ��������� ���� ��������.
		  counter=counter+money[i][j];
		}
		//������� ��� ���� ���� ��������� ���� �������� ��� ��� ��������� ���� ����.
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
	printf("\t\tM����_��������_���������� ���� �������\n");
	printf("\t      ---------------------------------------\n\n");
	//��������� ��������� ���� ������� ����.
	for ( i = 0; i<ROWS; i++)
	{
		printf("\t\t\033[94m%s\033[0m:\033[32m%.2f$\033[0m\n\n\n",room[i],average[i]);
	}
	printf("\n\n\n");
	//��������� ���/��� �������/�� �� ��� ��������� ���� ������� ����.
	printf("� �������/�� �� ��� ���������� �������� ���������� ����� �/��: ");	
	for ( i = 0; i<ROWS; i++)
	{
	    if(average[i]==min)
		printf("\033[31m%s\033[0m\t", room[i]);
	}
	printf("\n\n\n");	
	system("PAUSE");
	return 0;
}
