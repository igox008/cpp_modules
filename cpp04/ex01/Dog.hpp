/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:29:47 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/16 02:40:01 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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
