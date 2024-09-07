/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:31:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/15 01:01:57 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Default constructor is called\n";
	this->type = "Animal";
}

Animal	&Animal::operator=(const Animal &an)
{
	std::cout << "Animal assignement operator is called\n";
	this->type = an.type;
	return (*this);
}

Animal::Animal(const Animal &an)
{
	std::cout << "Animal copy constructor is called\n";
	*this = an;
}

Animal::~Animal()
{
	std::cout << "Animal desstructor is called\n";	
}

void	Animal::makeSound() const
{
	std::cout << "anonymous animal\n";
}

std::string	Animal::getType() const
{
	return (this->type);
}