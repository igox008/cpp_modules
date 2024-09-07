/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:10:10 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:36:34 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("RobotomyRequestForm")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm(_target, 72, 45), target(_target)
{
    
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExecute())
{
    if (this == &cpy)
        return ;
    *this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
    if (this != &cpy)
    {
        this->target = cpy.getTarget();
        this->setIsSigned(cpy.getIsSigned());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return (this->target);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getGradeToExecute() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else if (!this->getIsSigned())
        throw AForm::FormNotSigned();
    srand((unsigned int)time(0));
    int ran = rand() % 11;
    if (ran % 2 == 0)
        std::cout << "Zzzzzzzzzz, " << this->target << " has been robotomized\n";
    else
        std::cout << "Robotomy failed\n"; 
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &s)
{
    out << "Target : " << s.getTarget() << '\n';
    out << ", grade To Execute : " << s.getGradeToExecute() << '\n';
    out << ", grade To Sign : " << s.getGradeToSign() << '\n';
    out << ", status : " << ((s.getIsSigned()) ? "Signed" : "Not Signed Yet") << '\n';
    return (out);
}

