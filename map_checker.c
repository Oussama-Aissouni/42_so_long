/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:26:38 by oaissoun          #+#    #+#             */
/*   Updated: 2022/02/19 19:26:40 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int main(int argc, char const *argv[])
{
    int fd;
    int indice = 0;
    char *line;
    char **map_lines;

    fd = open("map.ber", O_RDWR);
    while (1)
    {
        if (get_next_line(fd) == NULL)
            break;
        else
            indice++;
    }
    printf("%d", indice);
    return 0;
}
