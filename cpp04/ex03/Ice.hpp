/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:55:19 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/19 23:55:19 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP


#include "AMateria.hpp"

class Ice : public AMateria
{
    public :
        Ice();
        Ice(const Ice &I);
        Ice &operator=(const Ice &I);

        ~Ice();
        std::string getType() const;
        void use(ICharacter &target);
        Ice *clone() const;
};

#endif