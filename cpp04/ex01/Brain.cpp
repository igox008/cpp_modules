/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 04:09:14 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/16 02:50:17 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor is called\n";
}

Brain   &Brain::operator=(const Brain &B)
{
    if (this == &B)
        return *this;
    for (int i = 0; i < 100;i++)
        this->ideas[i] = B.ideas[i];
    std::cout << "Brain assignement operator is called\n";
    return *this;
}

Brain::Brain(const Brain &B)
{
    std::cout << "Brain copy constructor is called\n";
    *this = B;
}

Brain::~Brain()
{
    std::cout << "Brain desstructor is called\n";
}

std::string Brain::getIdea(size_t i) const
{
    if (i >= 100)
        return ("wrong Index!");
    return (this->ideas[i]);
}

void    Brain::setIdea(size_t i, std::string _idea)
{
    if (i >= 100)
        return ;
    this->ideas[i] = _idea;
}
