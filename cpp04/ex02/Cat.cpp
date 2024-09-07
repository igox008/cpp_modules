/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:51:38 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/16 02:45:00 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor is called\n";
	this->type = "Cat";
	this->_brain = new Brain();
	for (size_t i = 0; i < 100;i++)
		this->_brain->setIdea(i, "Cats loves Fish");
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat assignement operator is called\n";
	if (this == &c)
		return (*this);
	this->type = c.type;
	delete this->_brain;
	this->_brain = new Brain(*c._brain);
	return (*this);
}

Cat::Cat(const Cat &c)
{
	std::cout << "Cat copy constructor is called\n";
	*this = c;
}

Cat::~Cat()
{
	std::cout << "Cat desstructor is called\n";
	delete this->_brain;
}

void	Cat::makeSound() const
{
	std::cout << "Meoow Meoooooow\n";
}

std::string	Cat::getType() const
{
	return (this->type);
}