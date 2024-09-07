/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:51:38 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/15 01:03:30 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor is called\n";
	this->type = "Cat";
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << "Cat assignement operator is called\n";
	this->type = c.type;
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
}

void	Cat::makeSound() const
{
	std::cout << "Meoow Meoooooow\n";
}

std::string	Cat::getType() const
{
	return (this->type);
}