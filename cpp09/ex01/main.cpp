/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:40:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/04 17:28:43 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "ERROR : " << ((ac == 1) ? "Insufficient parameters" : "Too much parameters") << '\n';
        std::cerr << "Usage : " << av[0] << " \"<RPN notatio>\"\n";
        return (1);
    }
    std::string line = std::string(av[1]);
    try 
    {
        RPN rpn;
        rpn.checkRpn(line);
        rpn.execOperations(line);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}