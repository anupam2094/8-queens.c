#include<stdio.h>
#include<conio.h>



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

swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
      1. String
	     2. Starting index of the string
		    3. Ending index of the string. */
void permute(int *a, int i, int n)
{
	int j, c;
	static int k = 0;
	if (i == n)
	{
		for (c = 0; c <= n; c++)
		{
			soln[k][c] = a[c];
		}
		k++;
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			swap((a + i), (a + j));
			permute(a, i + 1, n);
			swap((a + i), (a + j)); //backtrack
		}
	}
}


void aplySoln(int k)
{
	initilize();
	int i = 0, j = 0;
	while (i < 8)
	{
		j = soln[k][i];
		arena[i][j] = 1;
		i++;
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
	int i, j, k = 0, chk = 1;
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	permute(a, 0, 7);
	//arena[7][7] = 1;
	//printf("%d\n", willBeAttacked(0, 1));

	for (k = 0; k < 40320; k++)
	{
		aplySoln(k);
		//printf(".................\n");
		chk = 1;
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				if (arena[i][j] == 1)
				{
					//printf("%d %d %d \n",willBeAttacked(i, j), i, j);
					if (willBeAttacked(i, j))
					{
						//printf("%d %d %d\n", k, i, j);
						chk = 0;
						i = 8;
						j = 8;
					}
				}
			}
		}
		if (chk)
		{
			//printf("%d\n", k);
			break;

		}
	}
	prntArena();
	
}
