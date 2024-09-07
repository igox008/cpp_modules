/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:44:21 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/20 03:44:21 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0;i < 4;i++)
        this->box[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &M)
{
    for (int i = 0;i < 4;i++)
        this->box[i] = NULL;
    *this = M;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &M)
{
    if (this == &M)
        return *this;
    for (int i = 0;i < 4;i++)
    {
        if (this->box[i] != NULL)
            delete this->box[i];
        if (M.box[i] != NULL)
            this->box[i] = M.box[i]->clone();
    }
    return *this;
}

MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria *m)
{
    static int i;

    if (!m)
        return ;
    if (i > 0)
    {
        for (int j = 0;j < 4;j++)
        {
            if (!this->box[j] && i > 0)
                i--;
        }
    }
    if (i < 4)
    {
        this->box[i] = m;
        i++;
    }
}

AMateria    *MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0;i < 4;i++)
    {
        if (this->box[i] && this->box[i]->getType() == type)
        {
            return this->box[i]->clone();
        }
    }
    std::cout << type << " doesn\'t exist in the box\n";
    return NULL;
}

#endif