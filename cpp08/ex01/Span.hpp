/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:29:21 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/04 10:56:21 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>


class Span
{
    private :
        unsigned int N;
        std::vector<int> arr;
        Span();
    public :
        Span(unsigned int size);
        ~Span();
        Span(const Span &cpy);
        Span &operator=(const Span &cpy);

        void addNumber(const int num);
        void addNumbers(std::vector<int>::iterator b, std::vector<int>::iterator e);
        void addNumbers(std::vector<int>::const_iterator b, std::vector<int>::const_iterator e);
        unsigned int shortestSpan(void) const;
        int longestSpan(void) const;
        class CantAddNumber : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Can't Add Number");
                }  
        };
        class AtLeastTwo : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("the size must be atleast two");
                }  
        };
};



#endif