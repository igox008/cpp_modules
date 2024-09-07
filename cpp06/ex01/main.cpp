/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:39:14 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 16:43:27 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *ptr = new Data();
    ptr->n = 1337;
    ptr->s = "LEET";
    uintptr_t tmp = Serializer::serialize(ptr);
    Data *test = Serializer::deserialize(tmp);
    std::cout << test->n << " " << test->s << '\n';
}