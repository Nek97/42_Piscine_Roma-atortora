/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:07:27 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/01 18:23:16 by atortora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
//*/*/*/*/*/*/*/*//
#include <stdio.h>

int ft_factorial(int n);
void wrong_n(int *n, int *j, int fact);
int gen_n(int **matrix, int row, int col, int range);
int call_gen(int **matrix, int row, int col, int range);
int gen_rec(int **matrix, int row, int col, int range);
int new_max(int *reads, int **matrix, int row, int col);
void generate_borders(int **matrix, int range, int rows);
void excludecombs(int **combs, int i,int row, int size);
void clearcombs(int **combs,int row, int size);
int recursive(int ***very_big_pp, int riga, int size );
int get_inputs(char *str, int **inputs, int size);
int check_args(char *str);
void error(int n);

int main(int argc, char **argv)
{
  if(argc != 2)
  {
    error(10 + argc);
    return 0;
  }
  int max;
  max = check_args(argv[1]);
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
    

    int ***very_big_pp;
    very_big_pp = (int ***)malloc(sizeof(int **) * 3);
    very_big_pp[0] = matrix;
    very_big_pp[1] = inputs;
    very_big_pp[2] = res;


    if(recursive(very_big_pp, 0, max) == 0)
      return 0;
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
