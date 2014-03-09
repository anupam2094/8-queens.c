
#include<stdio.h>
#include<conio.h>

int arena[8][8];


void initilize()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			arena[i][j] = 0;
		}
	}
}

void prntArena()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d  ", arena[i][j]);
		}
		printf("\n");
	}
}

//For backtracking
int willAttack(int f1, int f2, int m1, int m2)
{
	int m, n;
	m = f1 + f2;
	n = f1 - f2;
	if (f1 != m1 && f2 != m2)
	{
		if (m1 - m2 != n && m1 + m2 != m)
			return(1);
	}
	return 0;
}

int willBeAttacked(int x, int y)
{
	int i, j, k = 0;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (i == x && j == y)
				continue;
			else if (arena[i][j] == 1)
			{
				if (!willAttack(i, j, x, y))
				{
					k = 1;
				}
			}
		}
	}
	return k;
}

void main()
{
	printf("enter location of first queen in first coulmn:");
	int i, j, x, y, z, n;
	scanf_s("%d", &n);
	int stack[8];
	initilize();
	arena[n][0] = 1;
	//printf("%d\n",willBeAttacked(2, 6));
	stack[0] = n;
	i = 1; j = 1;
	while (j < 8)
	{
		if (i == 8)
		{
			j--;
			i = stack[j];
			arena[i][j] = 0;
			i++;
		}
		else if( willBeAttacked(i, j))
		{
			i++;
		}
		else
		{
			arena[i][j] = 1;
			stack[j] = i;
			j++;
			i = 0;
		}
	}

	prntArena();

}
