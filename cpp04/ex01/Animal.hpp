/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:29:30 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/15 01:00:54 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class   Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &an);
		virtual ~Animal();
		
		Animal	&operator=(const Animal &an);
		
		virtual void	makeSound() const;
		virtual std::string getType() const;
};

#endif
