/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:11:31 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/04 03:08:59 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        try 
        {
            sp.addNumber(11);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        Span sp = Span(5);
        sp.addNumber(6);
        std::vector<int> vec;
        vec.push_back(5);
        vec.push_back(67);
        vec.push_back(9);
        vec.push_back(1);
        vec.push_back(3);
        vec.push_back(1);
        try 
        {
            std::cout << "longestSpan() : " << sp.longestSpan() << std::endl;
            std::cout << "shortestSpan() : "<< sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        sp.addNumbers(vec.begin(), vec.end());
        std::cout << "longestSpan() : " << sp.longestSpan() << std::endl;
        std::cout << "shortestSpan() : "<< sp.shortestSpan() << std::endl;
        try 
        {
            sp.addNumbers(vec.begin(), vec.end());
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}
