/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:05:14 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:24:38 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
    try
    {
        Bureaucrat a(4, "IGO");
        ShrubberyCreationForm s("FORM");
        RobotomyRequestForm r("ROBO");
        PresidentialPardonForm p("PRES");
        a.signForm(s);
        a.signForm(r);
        a.signForm(p);
        s.execute(a);
        r.execute(a);
        p.execute(a);
    }
    catch(const AForm::GradeTooLowException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const AForm::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const AForm::FormNotSigned &e)
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