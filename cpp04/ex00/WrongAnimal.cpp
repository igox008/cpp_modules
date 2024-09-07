/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:31:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/14 22:47:26 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default constructor is called\n";
	this->type = "WrongAnimal";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &an)
{
	std::cout << "WrongAnimal assignement operator is called\n";
	this->type = an.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &an)
{
	std::cout << "WrongAnimal copy constructor is called\n";
	*this = an;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal desstructor is called\n";	
}

void	WrongAnimal::makeSound() const
{
	std::cout << "anonymous WrongAnimal\n";
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}