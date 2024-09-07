/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:53:59 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:16:59 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        std::string target;
        ShrubberyCreationForm();
    public :
        ShrubberyCreationForm(std::string _target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);

        std::string getTarget(void) const;

        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s);


#endif
