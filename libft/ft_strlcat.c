/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:19:49 by yogun             #+#    #+#             */
/*   Updated: 2022/04/06 02:54:49 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	leng_dst;
	size_t	leng_src;
	size_t	i;
	size_t	limit;

	leng_dst = ft_strlen(dst);
	leng_src = ft_strlen((const char *)src);
	if (dst_size <= leng_dst)
		return (dst_size + leng_src);
	i = 0;
	limit = leng_dst;
	while (src[i] && i < (dst_size - leng_dst - 1))
		dst[limit++] = src[i++];
	dst[limit] = '\0';
	return (leng_dst + leng_src);
}
