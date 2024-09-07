/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:40:21 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 11:02:02 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public :
        Intern();
        ~Intern();
        Intern(const Intern &cpy);
        Intern &operator=(const Intern &cpy);
        

        AForm   *makeForm(std::string _form, std::string _target);
        class FormNotFoundExeption : public std::exception
        {
            public :
                const char *what() const throw();
        };
};




#endif
