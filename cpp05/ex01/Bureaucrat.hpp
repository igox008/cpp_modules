/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:03:26 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/29 22:33:37 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private :
		const std::string	name;
		int					grade;
	public :
		Bureaucrat();
		Bureaucrat(int _grade, const std::string _name);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		
		Bureaucrat &operator=(const Bureaucrat &src);
		std::string getName(void) const;	
		int			getGrade(void) const;
		void		incrGrade(void);
		void		decrGrade(void);

		void	signForm(Form &f);
		class GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char* what() const throw();	
		};
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);


#endif
