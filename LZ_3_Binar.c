#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void Bin_Op(int **M_1, int **M_2, int **M, int Size_1, int Size_2, int Type)
{
	int i, j, min, max;
	if(Size_1<Size_2) {min=Size_1; max=Size_2;}
	else {min=Size_2; max=Size_1;}

	M=(int**)malloc(max*sizeof(int));
	for(i=0;i<max;i++)
	{
		*(M+i)=(int*)malloc(max*sizeof(int));
		for(j=0;j<max;j++)
		{
			if(max==Size_1)
				M[i][j]=M_1[i][j];
			else
				M[i][j]=M_2[i][j];
		}
	}
	switch(Type)
	{
	case(1):
		{
			for(i=0;i<min;i++)
				for(j=0;j<min;j++)
					if((M_1[i][j]==0)&&(M_2[i][j]==0))
						M[i][j]=0;
					else M[i][j]=1;
			break;
		}
	case(2):
		{
			for(i=0;i<min;i++)
				for(j=0;j<min;j++)
					if((M_1[i][j]==1)&&(M_2[i][j]==1))
						M[i][j]=1;
					else M[i][j]=0;
			break;
		}
	case(3):
		{
			for(i=0;i<min;i++)
				for(j=0;j<min;j++)
					if((M_1[i][j]!=M_2[i][j]))
						M[i][j]=1;
					else M[i][j]=0;
			break;
		}
	}

	for(i=0;i<max;i++)
	{
		printf("\n%4d|", i+1);
		for(j=0;j<max;j++)
			{
				printf("%2d", M[i][j]);
			}
	}
	printf("\n");
	free(M);
}

void main()
{
	int **G_1=NULL, **G_2=NULL, **G=NULL, i=0, j=0, S_1=0, S_2=0;
	int Type=0;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	printf("Введите размерности матриц смежности:\n");
	scanf("%d%d", &S_1, &S_2);
	while(S_1<1 || S_2<1)
	{
		printf("Некорректно введённое число! Введите целые положительные числа для указания размеров матриц:\n");
		scanf("%d%d", &S_1, &S_2);
	}
	printf("\nГраф G_1:"); 
	G_1=(int**)malloc(S_1*sizeof(int));
	for(i=0;i<S_1;i++)
	{
		G_1[i]=(int*)malloc(S_1*sizeof(int));
		for(j=0;j<S_1;j++)
		{
			G_1[i][j]=rand()%2;
			if(G_1[i][i]!=0)
				G_1[i][j]=0;
		}
	}
	for(i=0;i<S_1;i++)
	{
		printf("\n%4d|", i+1);
		for(j=0;j<S_1;j++)
			{
				G_1[j][i]=G_1[i][j];
				printf("%2d", G_1[i][j]);
			}
	}
	printf("\n");

	printf("\nГраф G_2:"); 
	G_2=(int**)malloc(S_2*sizeof(int));
	for(i=0;i<S_2;i++)
	{
		G_2[i]=(int*)malloc(S_2*sizeof(int));
		for(j=0;j<S_2;j++)
		{
			G_2[i][j]=rand()%2;
			if(G_2[i][i]!=0)
				G_2[i][j]=0;
		}
	}
	for(i=0;i<S_2;i++)
	{
		printf("\n%4d|", i+1);
		for(j=0;j<S_2;j++)
			{
				G_2[j][i]=G_2[i][j];
				printf("%2d", G_2[i][j]);
			}
	}

	printf("\nУкажите вид операции: 1-Объединение, 2-Пересечение, 3-Кольцевая сумма\n");
	scanf("%d", &Type);
	while(Type<1 || Type>3)
	{
		printf("Некорректно введённой номер вида операции! Введите число от 1 до 3.\n");
		scanf("%d", &Type);
	}

	printf("\nИтоговый граф G:");
	Bin_Op(G_1, G_2, G, S_1, S_2, Type);
	free(G_2);
	free(G_1);
}