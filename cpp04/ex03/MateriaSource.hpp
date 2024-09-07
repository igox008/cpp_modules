/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:34:01 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/20 03:34:01 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private :
        AMateria *box[4];
    public :
        MateriaSource();
        MateriaSource(const MateriaSource &M);
        MateriaSource &operator=(const MateriaSource &M);

        ~MateriaSource();
        void    learnMateria(AMateria *m);
        AMateria    *createMateria(std::string const & type);

};