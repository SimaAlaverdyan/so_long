/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:15:40 by salaverd          #+#    #+#             */
/*   Updated: 2021/07/15 12:15:44 by salaverd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_RowsCols matrix_row_col(int fd)
{
    t_RowsCols s;
    char *line;
    int row;
    int col;
    printf("5\n");
    line = NULL;
    row = 0;
    printf("66\n");
    while (get_next_line(fd, &line) != 0)
    {
        printf("7\n");
        row++;
        free(line);
        col = ft_strlen(line);
    }
    s.rows = row;
    s.cols = col;
    return s;
}
char **create_matrix(char *path, int fd, int rows, int cols)
{
    int ret;
    int i;
    int j;
    char *line;
    char **matrix;

    i = 0;
    j = 0;
    ret = 0;
    line = NULL;

    matrix = (char **)malloc(rows * sizeof(char *));

    for (int k = 0; k < rows; k++)
        matrix[k] = (char *)malloc(cols * sizeof(char));

    fd = open(path, O_RDONLY);

    while ((ret = get_next_line(fd, &line)) != 0)
    {
        j = 0;
        while (j < cols)
        {
            matrix[i][j] = line[j];
            // write(1, &matrix[i][j], 1);
            j++;
        }
        // write(1, "\n", 1);
        i++;
        free(line);
    }
    close(fd);

    return (matrix);
}

void ft_setmatrixcharacters(t_utilities *util)
{
    int i;
    int j;

    i = 0;
    while (i < util->map.height)
    {
        j = 0;
        while (j < util->map.width)
        {
            if (util->map.matrix[i][j] == 'C')
                util->player.goal++;
            else if (util->map.matrix[i][j] == 'E')
            {
                ft_initexit(util, i, j);
            }
            else if (util->map.matrix[i][j] == 'P')
            {
                ft_initplayer(util, i, j);
            }
            j++;
        }
        i++;
    }
}

int border_character_check(char **matrix, int rows, int cols)
{
    int i = 0;

    //first row
    while (i < cols)
    {
        if (matrix[0][i] != '1')
        {
            return 0;
        }
        i++;
    }

    //first column
    i = 0;
    while (i < rows)
    {
        if (matrix[i][0] != '1')
        {
            return 0;
        }
        i++;
    }
    i = 0;
    //last row
    while (i < cols)
    {
        if (matrix[rows - 1][i] != '1')
        {
            return 0;
        }
        i++;
    }

    i = 0;
    //last column
    while (i < rows)
    {
        if (matrix[i][cols - 1] != '1')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int inner_character_check(char **matrix, int rows, int cols)
{
    int i;
    int j;
    i = 1;

    while (i < rows - 1)
    {
        j = 1;
        while (j < cols - 1)
        {
            if (matrix[i][j] != 'E' && matrix[i][j] != 'C' && matrix[i][j] != 'P' && matrix[i][j] != '0' && matrix[i][j] != '1')
            {
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}
