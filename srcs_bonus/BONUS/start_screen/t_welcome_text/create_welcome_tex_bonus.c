/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_welcome_tex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 01:37:37 by mravily           #+#    #+#             */
/*   Updated: 2020/10/17 18:33:57 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Initialisation des variables de la struct t_welcome
** - Pointeur vers l'image
** - Les bitmap de l'image stocker en int*
*/

t_welcome_tex		create_welcome_tex(char *path)
{
	t_welcome_tex	welcome;

	welcome.path = ft_strdup(path);
	welcome.img = NULL;
	welcome.addr = NULL;
	if (!(welcome.img = mlx_xpm_file_to_image(g_engine->vars->mlx_ptr
		, path, &(welcome.width), &(welcome.height))))
	{
		error_exit_cub(path
		, "During creation of the image xpm pointer for \
		the welcome, path invalid"
		, "Check if the image is present at this path.");
	}
	welcome.addr = mlx_get_data_addr(welcome.img
		, &(welcome.bits_per_pixel)
		, &(welcome.line_length), &(welcome.endian));
	return (welcome);
}

/*
** Mallocage de la structure t_welcome_tex pour le start_screen
*/

t_welcome_tex		*malloc_welcome_tex(char *path)
{
	t_welcome_tex	*welcome;

	welcome = (t_welcome_tex *)malloc(sizeof(t_welcome_tex));
	if (welcome == NULL)
		return (NULL);
	*welcome = create_welcome_tex(path);
	return (welcome);
}
