/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:22:57 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/02 00:28:23 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename S>
void    swap(S &a, S &b)
{
    S tmp = a;
    a = b;
    b = tmp;
}
template <typename N>
N   min(N a, N b)
{
    return ((a < b) ? a : b);
}

template <typename M>
M   max(M a, M b)
{
    return ((a > b) ? a : b);   
}


#endif
