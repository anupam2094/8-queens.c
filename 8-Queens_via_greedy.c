#include<stdio.h>
#include<conio.h>

int arena[8][8];
int t_arena[8][8];
int ctr = 1;


void initilize()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			arena[i][j] = 0;
			t_arena[i][j] = 0;
		}
	}
}

void cover(int p1, int p2)
{
	int i, j;
	int m, n;
	m = p1 + p2;
	n = p1 - p2;
	for (i = 0; i < 8; i++)
	{
		if (t_arena[p1][i] != 1 && t_arena[p1][i] != 8)
		{
			t_arena[p1][i] = 8;
			ctr++;
		}
		if (t_arena[i][p2] != 8 && t_arena[i][p2] != 1)
		{
			ctr++;
			t_arena[i][p2] = 8;
		}
		for (j = 0; j < 8; j++)
		{
			if (i + j == m || i - j == n)
			{
				if (t_arena[i][j] != 8 && t_arena[i][j] != 1)
				{
					t_arena[i][j] = 8;
					ctr++;
				}
			}
		}
	}
}
void cpyArr()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			t_arena[i][j] = arena[i][j];
		}
	}
}

void revCpyArr()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			arena[i][j] = t_arena[i][j];
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


void main()
{
	int x, y, i, j, m, k = 0, z = 0;
	int min = 64, counter = 0, flag = 0;
	printf("Enter the loc of the 1st queen(i-row;j-col<8):");
	scanf_s("%d %d", &x, &y);
	printf("%d %d\n", x, y);
	initilize();
	arena[x][y] = 1;
	cpyArr();
	cover(x, y);
	revCpyArr();
	for (m = 0; m <=8; m++)
	{
		flag = 0;
		for (j = 0; j < 8; j++)
		{
			for (i = 0; i < 8; i++)
			{
				cpyArr();
				if (arena[i][j] == 0)
				{
					flag = 1;
					ctr = 1;
					t_arena[i][j] = 1;
					cover(i, j);
					//printf("%d   ", ctr);
					if (min > ctr)
					{
						min = ctr;
						k = i;
						z = j;
					}
				}
			}
		}
		arena[k][z] = 1;
		cpyArr();
		cover(k, z);
		revCpyArr();
		printf("%d   %d   %d\n", min, k, z);
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				printf("%d  ", t_arena[i][j]);
			}
			printf("\n");
		}
		printf("..........\n");
	}
	//printf("%d   %d   %d\n", min, k, z);

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d  ", t_arena[i][j]);
		}
		printf("\n");
	}


}
