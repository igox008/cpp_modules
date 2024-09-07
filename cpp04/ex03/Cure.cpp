/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:47:25 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/19 23:47:25 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    std::cout << "Cure default constructor is caled\n";
    this->type = "cure";
}

Cure::Cure(const Cure &c) : AMateria()
{
    std::cout << "Cure copy constructor is caled\n";
    *this = c;
}

Cure    &Cure::operator=(const Cure &c)
{
    std::cout << "Cure copy assignment operator is caled\n";
    if (this == &c)
        return *this;
    this->type = c.type;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure detructor is called\n";
}

std::string Cure::getType() const
{
    return this->type;
}

void    Cure::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at "<< target.getName() << " *\n";
}

Cure    *Cure::clone() const
{
    Cure *ret = new Cure();
    return ret;
}