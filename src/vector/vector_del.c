/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:44:54 by pjarnac           #+#    #+#             */
/*   Updated: 2025/03/24 10:44:54 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

void	vct_erase(t_vct	vct, int32_t pos, int32_t n, void (*del)(void *))
{
	int32_t		i;
	t_vcthead	*head;

	head = get_vcthead(vct);
	i = -1;
	if (del)
		while (++i < n)
			del(head->data + (i + pos) * head->e_size);
	ft_memmove(&head->data[pos * head->e_size],
		&head->data[(pos + n) * head->e_size],
		head->size - pos - n);
	head->size -= n;
}

void	vct_delete(t_vct vct, int32_t pos, void (*del)(void *))
{
	vct_erase(vct, pos, 1, del);
}
