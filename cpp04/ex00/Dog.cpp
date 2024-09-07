/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:56:49 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/15 01:04:03 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor is called\n";
	this->type = "Dog";
}

Dog	&Dog::operator=(const Dog &d)
{
	std::cout << "Dog assignement operator is called\n";
	this->type = d.type;
	return (*this);
}

Dog::Dog(const Dog &d)
{
	std::cout << "Dog copy constructor is called\n";
	*this = d;
}

Dog::~Dog()
{
	std::cout << "Dog desstructor is called\n";	
}

void	Dog::makeSound() const
{
	std::cout << "haw haw haw haw haw\n";
}

std::string Dog::getType() const
{
	return (this->type);
}