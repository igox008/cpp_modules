/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
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

class   AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal &an);
		virtual ~AAnimal();
		
		AAnimal	&operator=(const AAnimal &an);
		
		virtual void	makeSound() const = 0;
		virtual std::string getType() const;
};

#endif
