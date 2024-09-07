/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 02:04:16 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:14:31 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default"), gradeToSign(150), gradeToExecute(150)
{
    this->isSigned = false;
    
}

AForm::AForm(const std::string _name, int _gradeToSign, int _gradeToExecute) : name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    this->isSigned = false;
    
}

AForm::~AForm()
{
    
}

AForm::AForm(const AForm &cpy) : name(cpy.getName()),  gradeToSign(cpy.getGradeToSign()), gradeToExecute(cpy.getGradeToExecute())
{
    
    if (this == &cpy)
        return ;
    *this = cpy;
}

AForm    &AForm::operator=(const AForm &cpy)
{
    
    if (this == &cpy)
        return *this;
    this->isSigned = cpy.getIsSigned();
    return *this;
}

int AForm::getGradeToExecute(void) const
{
    return (this->gradeToExecute);
}

int AForm::getGradeToSign(void) const
{
    return (this->gradeToSign);
}

bool AForm::getIsSigned(void) const
{
    return (this->isSigned);
}

std::string AForm::getName(void) const
{
    return (this->name);
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    if (this->isSigned)
        throw AForm::FormAlreadySigned();
    this->isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

const char *AForm::FormAlreadySigned::what() const throw()
{
    return ("Form Already Signed");
}

const char *AForm::FormNotSigned::what() const throw()
{
    return ("Form Not Signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << "Form " << f.getName() << ", grade to sign " << f.getGradeToSign() \
        << ", grade to execute " << f.getGradeToExecute() << ", status : ";
    out << ((f.getIsSigned()) ? "signed" : "not signed yet") << '\n';
    return (out);
}

void    AForm::setIsSigned(bool _isSigned)
{
    this->isSigned = _isSigned;
}

void    AForm::execute(Bureaucrat const & executor) const
{
    (void)executor;
}
