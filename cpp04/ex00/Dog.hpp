/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:29:47 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/15 01:02:18 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
		Dog();
		Dog(const Dog &d);
		~Dog();

		Dog	&operator=(const Dog &d);

		void makeSound() const;
		std::string getType() const;

};

#endif
