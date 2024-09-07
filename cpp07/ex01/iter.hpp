/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:33:46 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/07 23:32:06 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>


template <typename T>
void    iter(T *arr, size_t len, void (*func)(T &))
{
    if (arr == NULL || func == NULL)
        return ;
    for (size_t i = 0; i < len;i++)
        func(arr[i]);
}

template <typename T>
void    iter(T *arr, size_t len, void (*func)(const T &))
{
    if (arr == NULL || func == NULL)
        return ;
    for (size_t i = 0; i < len;i++)
        func(arr[i]);
}


#endif
