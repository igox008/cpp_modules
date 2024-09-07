/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:54:51 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/19 23:54:51 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    std::cout << "ice default constructor is called\n";
    this->type = "ice";
}

Ice::Ice(const Ice &I) : AMateria()
{
    *this = I;
}

Ice &Ice::operator=(const Ice &I)
{
    if (this == &I)
        return (*this);
    this->type = I.type;
    return (*this);
}

Ice::~Ice()
{

}

std::string Ice::getType() const
{
    return this->type;
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "\'s wounds *\n";
}

Ice *Ice::clone() const
{
    return (new Ice());
}