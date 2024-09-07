/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:20:21 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/19 23:20:21 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public :
        Cure();
        Cure(const Cure &C);
        Cure    &operator=(const Cure &C);

        ~Cure();
        std::string getType() const;
        void    use(ICharacter &target);
        Cure    *clone() const;
};

#endif