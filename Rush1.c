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

int gen_n(int **matrix, int row, int col, int range)
{
    int n;
    int j;
    int fact;
    int temp;
    
    fact = ft_factorial(range - col - 1);
    if(row == 0) //Se sto nello prima riga il numero sara' il primo valore della colonna
        return (col + 1);
    n = 1;
    j = 0;
    while(j < col || j == 0)//Cerco in tutta la riga il numero generato
    {
        if(matrix[row][j] == n || matrix[row][col] == 0)//Se lo trovo
            {
                n++;//Genero il prosimo
                j = -1;//E torno all'inizio della riga
            }
        else
        {
            temp = row - fact;
            while (temp >= 0 && j != -1)
            {
                if (matrix[row - fact][col] == n)
                {
                    n++;//Genero il prosimo
                    j = -1;//E torno all'inizio della riga
                }
                temp -= fact;
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
                else
                    row++;
            i++;
        }
        return row;
    }
}

int main()
{
    int **matrix  = (int **)(malloc(24 * sizeof(int *)));
    int i = 0;
    while(i<24)
    {
        *(matrix + i) = (int *)(malloc(4 * sizeof(int)));
        i++;
    }
    gen_rec(matrix, 0, 0, 4);
    
    int j = 0;
    printf("\n***********************\n");
    i = 0;
    while(i<24)
    {
        j = 0;
        while(j<4)
        {
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}
