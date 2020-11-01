#include <stdlib.h>
#include <unistd.h>
//*/*/*/*/*/*/*/*//
#include <stdio.h>
int size = 4;

int ft_factorial(int n)
{
    if(n == 0)
        return 1;
    return n * ft_factorial(n - 1);
}

void wrong_n(int *n, int *j, int fact)
{
  *n += 1;//Genero il prosimo
  *j = -1;//E torno all'inizio della riga
}

int gen_n(int **matrix, int row, int col, int range)
{
    int n;
    int j;
    int i;
    int fact;
    int temp;

    fact = ft_factorial(range - col - 1);
    n = 1;
    j = -1;
    while(++j < col)//Cerco in tutta la riga il numero generato
        if(matrix[row][j] == n)//Se lo trovo
          wrong_n(&n, &j, fact);
        else
        {
            i = -1;
            temp = row - fact;
            while (temp >= 0 && ++i < (range - col - 1) && j != -1)
            {
                if (matrix[temp][col] == n)
                  wrong_n(&n, &j, fact);
                temp -= fact;
            }
        }
    return n;//Il numero generato torna alla funzione chiamante
}

int call_gen(int **matrix, int row, int col, int range)
{
    int fact;

    fact = ft_factorial(range - col - 1);
    if(row == 0) //Se sto nello prima riga il numero sara' il primo valore della colonna
      return (col + 1);
    if(col == 0 && row >= fact)
      return matrix[row - fact][col]+1;
    return (gen_n(matrix, row, col, range));
}

int gen_rec(int **matrix, int row, int col, int range)
{
    int i;
    int fact;

    if (col == (range - 1))
    {
        matrix[row][col] = call_gen(matrix, row, col, range);
        return (row + 1);
    }
    else
    {
        i = 0;
        fact = ft_factorial(range);
        while (i < fact)
        {
            matrix[row][col] = call_gen(matrix, row, col, range);
            if(row != gen_rec(matrix, row, col + 1, range))
                if(col != 0)
                    return row + 1;
                row++;
                    
            i++;
        }
        return row;
    }
}
/****************************************************************************************************/
int new_max(int *reads, int **matrix, int row, int col)
{
  *reads = *reads + 1;
  return (matrix[row][col]);
}

void generate_borders(int **matrix, int range, int rows)
{
  int i;
  int reads;
  int max;
  int j;

  i = -1;
  while(++i < rows)
  {
    j = 0;
    reads = 1;
    max = matrix[i][0];
    while(++j< range)
      if(matrix[i][j] > max)
        max = new_max(&reads, matrix, i, j);
    matrix[i][range] = reads;
    reads = 1;
    max = matrix[i][range - 1];
    while(--j >= 0)
      if(matrix[i][j] > max)
        max = new_max(&reads, matrix, i, j);
    matrix[i][range + 1] = reads;
    matrix[i][range + 2] = -1;
  }
}
/****************************************************************************/

void excludecombs(int **combs, int i,int row)
{
	int n;
	int k;

	n = 0;
	while (n < size)
	{	
		k = 0;
		while(k < ft_factorial(size))
		{
			if (combs[k][size+2] == -1)
			{
				if (combs[k][n] == combs[i][n])
				{
					combs[k][size + 2] = row; 
				}
			}
			k++;
		}
		n++;
	}

        printf("Start\n");
int j;
int max = size;
    i = 0;
    while(i<ft_factorial(size))
    {
        j = 0;
        while(j<max+3)
        {
            printf("%d ", combs[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
        printf("End\n");
}

void clearcombs(int **combs, int i,int row)
{
        printf("!!!!!!!!!!!!!!!!Clear\n");
	int n;

	n = 0;
	while (n < ft_factorial(size))
	{	
		if (combs[n][size + 2] == row)
		{
			combs[n][size + 2] = -1;
		}
		n++;
	}
}

int recursive(int **res, int **combs, int riga, int **inputs )
{
	int i =0;
  int j;

	if (riga == size)
		return 1;
	while (i < ft_factorial(size))
	{
		while (i < ft_factorial(size) && combs[i][size + 2] != -1)
		{
      if(i == 23)
        break;
      i++;
		}
		if (combs[i][size] == inputs[2][i] && combs[i][size+1] == inputs[3][i])
		{
      j = -1;
      while(++j< size)
        res[riga][j] = combs[i][j];
			excludecombs(combs, i, riga);
			if(recursive(res, combs, riga + 1, inputs))
				return 1;
			else
				clearcombs(combs, i, riga);	
		}
		i++;
	}
	return 0;

}
/************************************************************************************/
int get_inputs(char *str, int **inputs, int size)
{
  int i;
  int j;

  i = 0;
  while(i < 4)
  {
    j = 0;
    while(j < size)
    {
      inputs[i][j] = str[2 * ((i * size) + j)] - '0';
      if(i % 2 == 1)
      {
        if((inputs[i][j] + inputs[i - 1][j]) > size + 1
        ||(inputs[i][j] + inputs[i - 1][j]) < 3)
          return (0);
      }
      if(inputs[i][j] > size || inputs[i][j] == 0)
        return (0);
      j++;
    }
    i++;
  }
  return (1);
}

int checkArgs(char *str)
{
  int i;
  int isValid;
  int j;

  j = 0;
  i = 0;
  isValid = 0;
  while(*(str + i) != '\0')
  {
    if(*(str + i) < '0' || *(str + i) > '9')
    {
      if(*(str + i) == ' ')
        if (isValid == 0)
          isValid = 1;
        else
          return (0);
      else
        return (0);
    }
    else
    {
      j++;
      isValid = 0;
    }
    i++;
  }
  i = 1;
  while(i * i <= j)
  {
    if((i * i) == j)
      return (i);
    i++;
  }
  return 0;
}

void error(int n)
{
  char c = n + '0';
  write(1, &c, 1);
  write(1, "Error\n", 6);
}

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    error(10 + argc);
    return 0;
  }
  int max;
  max = checkArgs(argv[1]);
  if(max == 0)
  {
    error(2);
    return 0;
  }
  /**/
    int **matrix  = (int **)(malloc(ft_factorial(max) * sizeof(int *)));
    int **inputs  = (int **)(malloc(4 * sizeof(int *)));
    int **res  = (int **)(malloc(max * sizeof(int *)));
    int i = 0;
    int j = 0;
    while(i<ft_factorial(max))
    {
        *(matrix + i) = (int *)(malloc((max + 3) * sizeof(int)));//Dx -Sx - Used
        i++;
    }
    i = 0;
    while(i < 4)
    {
      *(inputs + i) = (int *)(malloc(max * sizeof(int)));
      i++;
    }
    i = 0;
    while(i < max)
    {
      *(res + i) = (int *)(malloc(max * sizeof(int)));
      i++;
    }
    if(get_inputs(argv[1], inputs, max) == 0)
    {
      error(3);
      return (0);
    }
    gen_rec(matrix, 0, 0, max);
    generate_borders(matrix, max, ft_factorial(max));
    
    recursive(res, matrix, 0, inputs);
    printf("\n***********************\n");
    i = 0;
    while(i<ft_factorial(max))
    {
        j = 0;
        while(j<max + 3)
        {
          if(j == max)
          {
            printf("- ");
          }
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
        printf("\n");
        printf("\n");
    i = 0;
    while(i<4)
    {
        j = 0;
        while(j<max)
        {
            printf("%d ", inputs[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
        printf("\n");
        printf("\n");
    i = 0;
    while(i<max)
    {
        j = 0;
        while(j<max)
        {
            printf("%d ", res[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
