#include "../include/so_long.h"

int     exit_count(t_utilities util)
{
    int count;
    int i;
    int j;

    i = 0;
    count = 0;

    while (i < util.map.width)
    {
        j = 0;
        while (j < util.map.height)
        {
            if (util.map.matrix[i][j] == 'E')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int     player_count(t_utilities util)
{
    int count;
    int i;
    int j;

    i = 0;
    count = 0;

    while (i < util.map.width)
    {
        j = 0;
        while (j < util.map.height)
        {
            if (util.map.matrix[i][j] == 'P')
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int     check_norms(t_utilities util)
{
    if (util.map.height == util.map.width)
    {
        exit(0);
        printf("The map must be rectangular");
    }
    else if (border_character_check(util.map.matrix, util.map.height, util.map.width) == 0)
    {
        exit(0);
        printf("The map must be closed/surrounded by walls");
    }
    else if (inner_character_check(util.map.matrix, util.map.height, util.map.width) == 0)
    {
        exit(0);
        printf("The map must have only '1' '0' 'P' 'C' 'E' 'F' characters");
    }
    else if (util.player.goal == 0)
    {
        exit(0);
        printf("There is no food in this map");
    }
    else if (exit_count(util) == 0)
    {
        exit(0);
        printf("The map must have exit");
    }
    else if (exit_count(util) > 1)
    {
        exit(0);
        printf("The map must have only one exit");
    }
    else if (player_count(util) == 0)
    {
        exit(0);
        printf("The map must have start position");
    }
    else if (player_count(util) > 1)
    {
        exit(0);
        printf("The map must have only one start position");
    }
    return (0);
}