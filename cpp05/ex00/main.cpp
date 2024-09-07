/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:05:14 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/29 01:49:49 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b(-1, "hello");
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
       
}