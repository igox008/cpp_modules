/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:31:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/15 01:01:57 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal Default constructor is called\n";
	this->type = "AAnimal";
}

AAnimal	&AAnimal::operator=(const AAnimal &an)
{
	std::cout << "AAnimal assignement operator is called\n";
	this->type = an.type;
	return (*this);
}

AAnimal::AAnimal(const AAnimal &an)
{
	std::cout << "AAnimal copy constructor is called\n";
	*this = an;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal desstructor is called\n";	
}

void	AAnimal::makeSound() const
{
	std::cout << "anonymous AAnimal\n";
}

std::string	AAnimal::getType() const
{
	return (this->type);
}