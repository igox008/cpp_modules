/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:16:59 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 11:34:45 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    
}

Bureaucrat::Bureaucrat(int _grade, const std::string _name) : name(_name)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    this->grade = _grade;
    
}

Bureaucrat::~Bureaucrat()
{
    
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    
    if (this == &src)
        return (*this);
    this->grade = src.getGrade();
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    
    if (this == &copy)
        return ;
    *this = copy;
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

std::string Bureaucrat::getName(void) const
{
    return (this->name);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return out;
}

void    Bureaucrat::incrGrade(void)
{
    if (this->grade - 1 < 1)
        throw GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decrGrade(void)
{
    if (this->grade + 1 > 150)
        throw GradeTooLowException();
    else
        this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");   
}