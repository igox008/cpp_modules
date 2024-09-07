/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:15:49 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/06 06:27:42 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "ERROR : " << ((ac == 1) ? "Insufficient parameters" : "Too much parameters") << '\n';
        std::cerr << "Usage : " << av[0] << " <input file>\n";
        return (1);
    }
    BitcoinExchange btc;
    try 
    {
        btc.getDataCsv("data.csv");
        btc.handleInputCsv(std::string(av[1]));
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error : " << e.what() << '\n';
        return 1;
    }
}