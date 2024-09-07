/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 04:02:40 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/16 00:57:26 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private :
        std::string ideas[100];
    public :
        Brain();
        Brain(const Brain &b);
        ~Brain();

        Brain &operator=(const Brain &b);
        std::string getIdea(size_t i) const;
        void    setIdea(size_t i, std::string _idea);
};


#endif
