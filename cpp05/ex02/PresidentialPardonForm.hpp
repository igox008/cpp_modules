/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:18:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:19:44 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP


#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        std::string target;
        PresidentialPardonForm();
    public :
        PresidentialPardonForm(std::string _target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &cpy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);

        std::string getTarget(void) const;

        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &s);


#endif
