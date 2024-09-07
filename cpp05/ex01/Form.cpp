/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:04:16 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/29 22:40:35 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), gradeToSign(150), gradeToExecute(150)
{
    this->isSigned = false;
    
}

Form::Form(const std::string _name, int _gradeToSign, int _gradeToExecute) : name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    else if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    this->isSigned = false;
    
}

Form::~Form()
{
    
}

Form::Form(const Form &cpy) : name(cpy.getName()),  gradeToSign(cpy.getGradeToSign()), gradeToExecute(cpy.getGradeToExecute())
{
    
    if (this == &cpy)
        return ;
    *this = cpy;
}

Form    &Form::operator=(const Form &cpy)
{
    
    if (this == &cpy)
        return *this;
    this->isSigned = cpy.getIsSigned();
    return *this;
}

int Form::getGradeToExecute(void) const
{
    return (this->gradeToExecute);
}

int Form::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

bool Form::getIsSigned(void) const
{
    return (this->isSigned);
}

std::string Form::getName(void) const
{
    return (this->name);
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    if (this->isSigned)
        throw Form::FormAlreadySigned();
    this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

const char *Form::FormAlreadySigned::what() const throw()
{
    return ("Form Already Signed");
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << "Form " << f.getName() << ", grade to sign " << f.getGradeToSign() \
        << ", grade to execute " << f.getGradeToExecute() << ", status : ";
    out << ((f.getIsSigned()) ? "signed" : "not signed yet") << '\n';
    return (out);
}