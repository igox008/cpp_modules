/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:05:33 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:16:49 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()  : AForm("ShrubberyCreationForm", 145, 137), target("ShrubberyCreationForm")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm(_target, 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExecute())
{
    if (this == &cpy)
        return ;
    *this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
    if (this != &cpy)
    {
        this->target = cpy.getTarget();
        this->setIsSigned(cpy.getIsSigned());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

std::string ShrubberyCreationForm::getTarget(void) const
{
    return (this->target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getGradeToExecute() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else if (!this->getIsSigned())
        throw AForm::FormNotSigned();
    std::string filename = this->target + "_shrubbery";
    std::ofstream out(filename);
    if (!out)
    {
        std::cerr << "Error: Could not open file\n";
        return ;
    }
    out << "       _-_\n"
        << "    /~~   ~~\\\n"
        << " /~~         ~~\\\n"
        << "{               }\n"
        << " \\  _-     -_  /\n"
        << "   ~  \\\\ //  ~\n"
        << "_- -   | | _- _\n"
        << "  _ -  | |   -_\n"
        << "      // \\\\\\\n";
    out.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s)
{
    out << "Target : " << s.getTarget() << '\n';
    out << ", grade To Execute : " << s.getGradeToExecute() << '\n';
    out << ", grade To Sign : " << s.getGradeToSign() << '\n';
    out << ", status : " << ((s.getIsSigned()) ? "Signed" : "Not Signed Yet") << '\n';
    return (out);
}

