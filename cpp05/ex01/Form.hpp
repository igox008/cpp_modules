/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:52:11 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/29 22:33:41 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private :
        const std::string name;
        bool              isSigned;
        const int         gradeToSign;
        const int         gradeToExecute;
    public :
        Form();
        Form(const std::string _name, int _gradeToSign, int _gradeToExecute);
        ~Form();
        Form(const Form &cpy);
        Form &operator=(const Form &cpy);
        

        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        bool getIsSigned(void) const;
        std::string getName(void) const;
        
        void beSigned(Bureaucrat &b);
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

};


std::ostream &operator<<(std::ostream &out, const Form &f);


#endif
