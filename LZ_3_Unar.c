//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int Equal_V(int **M, int v_1, int v_2, int Size)
{
	int i, j, min, max;
	if (v_1 < v_2) {min=v_1-1; max=v_2-1;}
	else {min=v_2-1; max=v_1-1;}
	
//������� �������������� ������

	//������� min �������� ���. ���� �� ������� max �� �������� ���. ���
	for(i=min, j=0;j<Size;j++)
	{	
		if (M[min][j]+M[max][j]>=1) 
			M[min][j]=1;
	}
	for(j=min, i=0;i<Size;i++)
	{	
		if (M[i][min]+M[i][max]>=1) 
			M[i][min]=1;
	}

	//�������� ������� max
	for(i=0;i<Size-1;i++)
	{
		for(j=max;j<Size-1;j++)
		{
			M[i][j]=M[i][j+1];
		}
	}
	for(j=0;j<Size-1;j++)
	{
		for(i=max;i<Size-1;i++)
		{
			M[i][j]=M[i+1][j];
		}
	}
	for(i=0;i<Size-1;i++)
	{
		if (i==min)
			M[i][i]=1;
		else
			M[i][i]=0;
	}

//����� �������� �������
	for(i=0;i<Size-1;i++)
	{
		if(i==min)
			printf("\n%2d/%2d|", min+1, max+1);
		else
		{
			if(i>=max)
				printf("\n%5d|", i+2);
			else
				printf("\n%5d|", i+1);
		}
		for(j=0;j<Size-1;j++)
			{
				M[j][i]=M[i][j];
				printf("%2d", M[i][j]);
			}
	}
	return(Size-1);
}

int Rib_S(int **M, int v_1, int v_2, int Size)
{
	int i, j, min, max;
	if (v_1 < v_2) {min=v_1-1; max=v_2-1;}
	else {min=v_2-1; max=v_1-1;}
	
//������� �������������� ������

	//������� min �������� ���. ���� �� ������� max �� �������� ���. ���
	for(i=min, j=0;j<Size;j++)
	{	
		if (M[min][j]+M[max][j]>=1) 
			M[min][j]=1;
	}
	for(j=min, i=0;i<Size;i++)
	{	
		if (M[i][min]+M[i][max]>=1) 
			M[i][min]=1;
	}

	//�������� ������� max � "������������" ���� ������ �� ������
	for(i=0;i<Size-1;i++)
	{
		for(j=max;j<Size-1;j++)
		{
			M[i][j]=M[i][j+1];
		}
	}
	for(j=0;j<Size-1;j++)
	{
		for(i=max;i<Size-1;i++)
		{
			M[i][j]=M[i+1][j];
		}
	}
	for(i=0;i<Size-1;i++)
			M[i][i]=0;

//����� ������ �������
	for(i=0;i<Size-1;i++)
	{
		if(i==min)
			printf("\n%2d.%2d|", min+1, max+1);
		else
		{
			if(i>=max)
				printf("\n%5d|", i+2);
			else
				printf("\n%5d|", i+1);
		}
		for(j=0;j<Size-1;j++)
			{
				M[j][i]=M[i][j];
				printf("%2d", M[i][j]);
			}
	}
	return(Size-1);
}

int Del_V(int **M, int v, int Size)
{
	int i=0, j=0;

//�������� ������� v
	for(i=0;i<Size-1;i++)
	{
		for(j=v-1;j<Size-1;j++)
		{
			M[i][j]=M[i][j+1];
		}
	}
	for(j=0;j<Size-1;j++)
	{
		for(i=v-1;i<Size-1;i++)
		{
			M[i][j]=M[i+1][j];
		}
	}

//����� �������� �������
	for(i=0;i<Size-1;i++)
		M[i][i]=0;
	for(i=0;i<Size-1;i++)
	{
		if(i>=v-1)
			printf("\n%4d|", i+2);
		else
			printf("\n%4d|", i+1);
		for(j=0;j<Size-1;j++)
			{
				M[j][i]=M[i][j];
				printf("%2d", M[i][j]);
			}
	}
	return(Size-1);
}	

void Del_Rib(int **M, int v_1, int v_2, int Size)
{
	int i=v_1-1, j=v_2-1;
	M[i][j]=0;M[j][i]=0;

//�������� ����� ����� ������ v_1 � v_2
	for(i=0;i<Size;i++)
	{
		printf("\n%4d|", i+1);
		for(j=0;j<Size;j++)
			{
				M[j][i]=M[i][j];
				printf("%2d", M[i][j]);
			}
	}
}

void main()
{
	int **G=NULL, i=0, j=0, t_1=0, t_2=0, S=0;
	int Type;
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	printf("������� ����������� ������� ���������: ");
	scanf("%d", &S);
	while(S<=0)
	{
		printf("����������� �������� �����! ������� ����� ������������� �����: ");
		scanf("%d", &S);
	}
	G=(int**)malloc(S*sizeof(int));
	for(i=0;i<S;i++)
	{
		G[i]=(int*)malloc(S*sizeof(int));
		for(j=0;j<S;j++)
		{
			G[i][j]=rand()%2;
			if(G[i][i]!=0)
				G[i][j]=0;
		}
	}
	for(i=0;i<S;i++)
	{
		printf("\n%4d|", i+1);
		for(j=0;j<S;j++)
			{
				G[j][i]=G[i][j];
				printf("%2d", G[i][j]);
			}
	}

	printf("\n������� ��� ��������: 1-�������������� ������, 2-���������� �����, 3-�������� �������, 4-�������� �����\n");
	scanf("%d", &Type);
	while(Type<1 || Type>4)
	{
		printf("����������� �������� ����� ���� ��������! ������� ����� �� 1 �� 4.\n");
		scanf("%d", &Type);
	}
	
	switch(Type)
	{
	case(1):
		{
			printf("����� ������� ����� ������������?\n");
			scanf("%d%d", &t_1, &t_2);
			while (t_1==t_2)
			{
				printf("����� ����� ����� � ��� �� �������! ������� ������ ������ ������.\n");
				scanf("%d%d", &t_1, &t_2);
			}
			while((t_1<1 || t_1>S)||(t_2<1 || t_2>S))
			{
				printf("����� ����� �������������� �������! ������� ����� � �������� ������� ������� ���������.\n");
				scanf("%d", &t_1, &t_2);
			}
			S=Equal_V(G, t_1, t_2,S);
			break;
		}
	case(2):
		{
			printf("����� ����� ������ ��������� ����� �������?\n");
			scanf("%d%d", &t_1, &t_2);
			while (t_1==t_2)
			{
				printf("����� ����� ����� � ��� �� �������! ������� ������ ������ ������.\n");
				scanf("%d%d", &t_1, &t_2);
			}
			while((t_1<1 || t_1>S)||(t_2<1 || t_2>S))
			{
				printf("����� ����� �������������� �������! ������� ����� � �������� ������� ������� ���������.\n");
				scanf("%d", &t_1, &t_2);
			}
			S=Rib_S(G, t_1, t_2,S);
			break;
		}
	case(3):
		{
			printf("����� ������� ����� �������? ");scanf("%d", &t_1);
			while(t_1<1 || t_1>S)
			{
				printf("����� ������� �� ����������! ������� ����� � �������� ������� ������� ���������.\n");
				scanf("%d", &t_1);
			}
			S=Del_V(G, t_1, S);
			break;
		}
	case(4):
		{
			printf("����� ����� ������ ��������� ����� �������?\n");scanf("%d%d", &t_1, &t_2);
			while (t_1==t_2)
			{
				printf("����� ����� ����� � ��� �� �������! ������� ������ ������ ������.\n");
				scanf("%d%d", &t_1, &t_2);
			}
			while((t_1<1 || t_1>S)||(t_2<1 || t_2>S))
			{
				printf("����� ����� �������������� �������! ������� ����� � �������� ������� ������� ���������.\n");
				scanf("%d", &t_1, &t_2);
			}
			Del_Rib(G, t_1, t_2, S);
			break;
		}
	}
	printf("\n");
	free(G);
}