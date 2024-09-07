/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:29:47 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/16 03:24:21 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;
    public:
		Dog();
		Dog(const Dog &d);
		~Dog();

		Dog	&operator=(const Dog &d);

		void makeSound() const;
		std::string getType() const;

};

#endif
