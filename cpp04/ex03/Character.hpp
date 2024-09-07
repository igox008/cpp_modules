/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:09:23 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/20 00:09:23 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private :
        AMateria *invetory[4];
    public :
        Character(std::string name);
        Character(const Character &C);
        Character &operator=(const Character &C);

        ~Character();
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};