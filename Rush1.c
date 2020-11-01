
#include <stdio.h>
#include <stdlib.h>

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
  }
}

int main()
{
  int max = 4;
    int **matrix  = (int **)(malloc(ft_factorial(max) * sizeof(int *)));
    int i = 0;
    while(i<ft_factorial(max))
    {
        *(matrix + i) = (int *)(malloc((max + 2) * sizeof(int)));
        i++;
    }
    gen_rec(matrix, 0, 0, max);
    generate_borders(matrix, max, ft_factorial(max));
    
    int j = 0;
    printf("\n***********************\n");
    i = 0;
    while(i<ft_factorial(max))
    {
        j = 0;
        while(j<max + 2)
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

    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>

int ft_factorial(int n)
{
    if(n == 0)
        return 1;
    return n * ft_factorial(n - 1);
}

int gen_n(int **matrix, int row, int col, int range)
{
    int n;
    int j;
    int i;
    int fact;
    int temp;

    fact = ft_factorial(range - col - 1);
    if(row == 0) //Se sto nello prima riga il numero sara' il primo valore della colonna
        return (col + 1);
    if(col == 0 && row >= fact)
      return matrix[row - fact][col]+1;
    n = 1;
    j = 0;
    while(j < col)//Cerco in tutta la riga il numero generato
    {
        if(matrix[row][j] == n)//Se lo trovo
            {
                n++;//Genero il prosimo
                j = -1;//E torno all'inizio della riga
            }
        else
        {
            i = 0;
            temp = row - fact;
            while (temp >= 0 && i < (range - col - 1) && j != -1)
            {
                printf("temp => %d\n", temp);
                if (matrix[temp][col] == n)
                {
                    n++;//Genero il prosimo
                    j = -1;//E torno all'inizio della riga
                }
                temp -= fact;
                i++;
            }
        }
        j++;
    }
    printf("%d - %d - %d\n", row, col, n);
    return n;//Il numero generato torna alla funzione chiamante
}

int gen_rec(int **matrix, int row, int col, int range)
{
    int i;
    int fact;

    if (col == (range - 1))
    {
        matrix[row][col] = gen_n(matrix, row, col, range);
        return (row + 1);
    }
    else
    {
        i = 0;
        fact = ft_factorial(range);
        while (i < fact)
        {
            matrix[row][col] = gen_n(matrix, row, col, range);
            if(row != gen_rec(matrix, row, col + 1, range))
                if(col != 0)
                    return row + 1;
                row++;
                    
            i++;
        }
        return row;
    }
}

int main()
{
  int max = 4;
    int **matrix  = (int **)(malloc(ft_factorial(max) * sizeof(int *)));
    int i = 0;
    while(i<ft_factorial(max))
    {
        *(matrix + i) = (int *)(malloc(max * sizeof(int)));
        i++;
    }
    gen_rec(matrix, 0, 0, max);
    
    int j = 0;
    printf("\n***********************\n");
    i = 0;
    while(i<ft_factorial(max))
    {
        j = 0;
        while(j<max)
        {
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
*/

/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int ft_factorial(int n)
{
    if(n == 0)
        return 1;
    return n * ft_factorial(n - 1);
}

void wrong_n(int *n, int *j, int *temp, int fact)
{
  *n += 1;//Genero il prosimo
  *j = -1;//E torno all'inizio della riga
  *temp = *temp - fact;
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
    /*if(row == 0) //Se sto nello prima riga il numero sara' il primo valore della colonna
      return (col + 1);
    if(col == 0 && row >= fact)
      return matrix[row - fact][col]+1;*/
    while(++j < col)//Cerco in tutta la riga il numero generato
        if(matrix[row][j] == n)//Se lo trovo
          wrong_n(&n, &j, &temp, fact);
        else
        {
            i = -1;
            temp = row - fact;
            while (temp >= 0 && ++i < (range - col - 1) && j != -1)
            {
                if (matrix[temp][col] == n)
                  wrong_n(&n, &j, &temp, fact);
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

int main()
{
  int max = 4;
    int **matrix  = (int **)(malloc(ft_factorial(max) * sizeof(int *)));
    int i = 0;
    while(i<ft_factorial(max))
    {
        *(matrix + i) = (int *)(malloc(max * sizeof(int)));
        i++;
    }
    gen_rec(matrix, 0, 0, max);
    
    int j = 0;
    printf("\n***********************\n");
    i = 0;
    while(i<ft_factorial(max))
    {
        j = 0;
        while(j<max)
        {
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
