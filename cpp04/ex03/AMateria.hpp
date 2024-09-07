/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:00:09 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/19 23:00:09 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected :
        std::string type;
    public :
            AMateria();
            AMateria(std::string const & _type);
            AMateria(const AMateria &A);
            AMateria &operator=(const AMateria &A);

            virtual ~AMateria();
            std::string const &getType() const;
            virtual AMateria *clone() const = 0;
            virtual void use(ICharacter& target);
};


#endif