/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:51:38 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/14 22:56:42 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Default constructor is called\n";
	this->type = "WrongCat";
}

WrongCat	&WrongCat::operator=(const WrongCat &c)
{
	std::cout << "WrongCat assignement operator is called\n";
	this->type = c.type;
	return (*this);	
}

WrongCat::WrongCat(const WrongCat &c)
{
	std::cout << "WrongCat copy constructor is called\n";
	*this = c;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat desstructor is called\n";	
}

void	WrongCat::makeSound() const
{
	std::cout << "Meoow Meoooooow\n";
}

std::string	WrongCat::getType() const
{
	return (this->type);
}