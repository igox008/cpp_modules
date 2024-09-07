/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:05:49 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 20:26:46 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{   
    {
        Base *t = generate();
        identify(t);
        delete t;
    }
    std::cout << "-----------------------------------------------------------\n";
    {
        Base *t = generate();
        identify(*t);
        delete t;
    }
}