/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:19:23 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/03 23:35:09 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public :
        MutantStack()
        {
        }
        ~MutantStack()
        {  
        }
        MutantStack(const MutantStack &cpy)
        {
            *this = cpy;
        }
        MutantStack &operator=(const MutantStack &cpy)
        {
            if (this == &cpy)
                return *this;
            std::stack<T>::operator=(cpy);
            return *this;
        }
        typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        iterator begin()
        {
            return (this->c.begin());
        }
        iterator end()
        {
            return (this->c.end());
        }
        const_iterator begin() const
        {
            return (this->c.begin());
        }
        const_iterator end() const
        {
            return (this->c.end());
        }
};






#endif
