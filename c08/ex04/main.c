/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:38:45 by gborne            #+#    #+#             */
/*   Updated: 2021/07/19 04:20:09 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_stock_str    *ft_strs_to_tab(int ac, char **av);
void                ft_show_tab(struct s_stock_str *par);


int                    main(void)
{

    char* strs[3] = {"lol", "coucou", "ca va?"};
    int size = 3;


    ft_show_tab(ft_strs_to_tab(size, strs));
}
