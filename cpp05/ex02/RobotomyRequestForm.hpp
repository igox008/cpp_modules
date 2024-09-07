/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 00:09:24 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 10:35:22 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private :
        std::string target;
        RobotomyRequestForm();
    public :
        RobotomyRequestForm(std::string _target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &cpy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);

        std::string getTarget(void) const;

        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &s);

#endif
