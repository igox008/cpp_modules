/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:28:42 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/05 02:25:35 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>


class NumberNotFound : public std::exception
{
    public :
        const char *what() const throw()
        {
            return ("Number Not Found");
        }
};

template <typename T>

int easyfind(T arr, int srch)
{
    typename T::iterator it;

    it = find(arr.begin(), arr.end(), srch);
    if (it == arr.end())
        throw NumberNotFound();
    return (*it);
}

#endif
