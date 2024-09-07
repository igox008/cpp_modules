/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:11:50 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 22:35:29 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>

class ScalarConverter
{
    private :
        ScalarConverter();
    public :
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter &operator=(const ScalarConverter &cpy);

        static void convert(const std::string str);
};



#endif
