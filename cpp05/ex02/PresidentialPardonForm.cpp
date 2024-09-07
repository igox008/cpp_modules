/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:19:08 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:20:46 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("PresidentialPardonForm")
{
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm(_target, 25, 5), target(_target)
{
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExecute())
{
    if (this == &cpy)
        return ;
    *this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
    if (this != &cpy)
    {
        this->target = cpy.getTarget();
        this->setIsSigned(cpy.getIsSigned());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return (this->target);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getGradeToExecute() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else if (!this->getIsSigned())
        throw AForm::FormNotSigned();
    std::cout << this->target << "  has been pardoned by Zaphod Beeblebrox.\n";   
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &s)
{
    out << "Target : " << s.getTarget() << '\n';
    out << ", grade To Execute : " << s.getGradeToExecute() << '\n';
    out << ", grade To Sign : " << s.getGradeToSign() << '\n';
    out << ", status : " << ((s.getIsSigned()) ? "Signed" : "Not Signed Yet") << '\n';
    return (out);
}
