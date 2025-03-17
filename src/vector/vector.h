/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:56:26 by pjarnac           #+#    #+#             */
/*   Updated: 2025/03/13 15:56:26 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

typedef void	*t_vct;
typedef void	*t_vctptr;
typedef struct s_vcthead
{
	size_t	e_size;
	size_t	size;
	size_t	capacity;
	uint8_t	data[];
}	t_vcthead;

t_vct		vct_add_dest(t_vctptr vctptr);
t_vct		create_vector(size_t e_size);
t_vcthead	*get_vcthead(t_vct vct);
t_vcthead	*realloc_vct(t_vcthead *head);
void		free_vct(t_vct vct);
void		vct_add(t_vctptr vctptr, void *val);
bool		is_vct_full(t_vcthead *head);
size_t		vct_size(t_vct vct);
size_t		vct_capacity(t_vct vct);
void		vct_allocate(t_vctptr vctptr, size_t size);
void		vct_insert(t_vctptr vctptr, void *val, int32_t i);
t_vct		vct_insert_dest(t_vctptr vctptr, int32_t i);
void		add_vct_size(t_vct vct, size_t size);
void		set_vct_size(t_vct vct, size_t size);

#endif
