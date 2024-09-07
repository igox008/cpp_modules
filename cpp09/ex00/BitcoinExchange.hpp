/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:09:16 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/04 16:32:23 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>
#include <sstream>

class BitcoinExchange
{
	private :
        std::map<std::string, double> store;
    public :
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange &operator=(const BitcoinExchange &cpy);
        void	getDataCsv(const std::string file);
		void	handleInputCsv(const std::string file);
		void	parseInput(std::string date, double value);
		std::map<std::string, double> getStore(void) const;
		class CantOpenFile : public std::exception
		{
			public :
				const char *what() const throw()
				{
					return ("Can't Open File");
				}
		};
		class CantReadFile : public std::exception
		{
			public :
				const char *what() const throw()
				{
					return ("Can't Read File");
				}
		};
		class HeaderDontExist : public std::exception
		{
			public :
				const char *what() const throw()
				{
					return ("Header don't exist");
				}
		};
		class EmptyFile : public std::exception
		{
			public :
				const char *what() const throw()
				{
					return ("Empty File");
				}
		};
};

#endif
