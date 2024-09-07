/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:29:45 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 16:32:45 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


#include <iostream>

struct Data
{
    int n;
    std::string s;  
};

class Serializer
{
    private :
        Serializer();
    public :
        ~Serializer();
        Serializer(const Serializer &cpy);
        Serializer &operator=(const Serializer &cpy);
    
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif
