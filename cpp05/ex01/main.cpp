/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:05:14 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/29 22:44:59 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b(1, "hello");
        Form    f("allo", 6, 5);
        b.signForm(f);
        b.signForm(f);
    }
    catch(const Form::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Form::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
}