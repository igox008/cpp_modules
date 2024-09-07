/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:52:11 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:14:00 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private :
        const std::string name;
        bool              isSigned;
        const int         gradeToSign;
        const int         gradeToExecute;
    public :
        AForm();
        AForm(const std::string _name, int _gradeToSign, int _gradeToExecute);
        virtual ~AForm();
        AForm(const AForm &cpy);
        AForm &operator=(const AForm &cpy);
        

        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        bool getIsSigned(void) const;
        void setIsSigned(bool _isSigned);
        std::string getName(void) const;
        
        void beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException : std::exception
        {
            public :
                const char *what() const throw();  
        };
        class GradeTooLowException : std::exception
        {
            public :
                const char *what() const throw();  
        };
        class FormAlreadySigned : std::exception
        {
            public :
                const char *what() const throw();  
        };
        class FormNotSigned : std::exception
        {
            public :
                const char *what() const throw();  
        };

};


std::ostream &operator<<(std::ostream &out, const AForm &f);


#endif
