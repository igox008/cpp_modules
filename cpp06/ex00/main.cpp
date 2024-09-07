/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:40:26 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 22:54:56 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    try 
    {
        ScalarConverter::convert(std::string(av[1]));
    }
    catch (char const *s)
    {
        std::cerr << s << '\n';
    }
}