/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:54:04 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 11:03:40 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &cpy)
{
    (void)cpy;
}

Intern  &Intern::operator=(const Intern &cpy)
{
    (void)cpy;
    return *this;
}

const char *Intern::FormNotFoundExeption::what() const throw()
{
    return ("Form Not Found");   
}

AForm   *Intern::makeForm(std::string _form, std::string _target)
{
    AForm   *ret = NULL;
    if (_form == "Presidential Pardon")
        ret =  new PresidentialPardonForm(_target);
    else if (_form == "Robotomy Request")
        ret =  new RobotomyRequestForm(_target);
    else if (_form == "Shrubbery Creation")
        ret =  new ShrubberyCreationForm(_target);
    else
        throw Intern::FormNotFoundExeption();
    return (ret);
}
