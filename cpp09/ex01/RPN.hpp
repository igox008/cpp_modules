/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:29:53 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/04 17:52:11 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <exception>

class RPN
{
    private :
        std::stack<double> stck;
    public :
        RPN();
        ~RPN();
        RPN(const RPN &cpy);
        RPN &operator=(const RPN &cpy);
        std::stack <double> getStack(void) const;
        void checkRpn(std::string s);
        void execOperations(std::string s);
        class Error : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("ERROR");
                }
        };
        class DivisionByZero : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Division By Zero");
                }
        };
};


#endif
