/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:05:14 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 11:07:17 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main()
{
    try
    {
        Intern srbay;
        Bureaucrat a(4, "IGO");
        RobotomyRequestForm r("ROBO");
        PresidentialPardonForm p("PRES");
        AForm *s = srbay.makeForm("Shrubbery Creation", "FORM");
        a.signForm(*s);
        a.signForm(r);
        a.signForm(p);
        s->execute(a);
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
    catch(const Intern::FormNotFoundExeption &e)
    {
        std::cerr << e.what() << '\n';
    }
}