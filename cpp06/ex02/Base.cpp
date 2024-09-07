/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:54:48 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 17:12:06 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base *generate(void)
{
    srand(time(0));
    int n = rand() % 3;
    if (n == 0)
        return new A;
    else if (n == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    A *tmpa = dynamic_cast<A*>(p);
    B *tmpb = dynamic_cast<B*>(p);
    C *tmpc = dynamic_cast<C*>(p);

    if (tmpa != NULL)
        std::cout << "The actual type is A\n";
    else if (tmpb != NULL)
        std::cout << "The actual type is B\n";
    else if (tmpc != NULL)
        std::cout << "The actual type is C\n";
}

void identify(Base& p)
{
    try
    {
        A &tmpa = dynamic_cast<A &>(p);
        (void)tmpa;
        std::cout << "The actual type is A\n";
    }
    catch (...)
    {
        
    }
    try
    {
        B &tmpb = dynamic_cast<B &>(p);
        (void)tmpb;
        std::cout << "The actual type is B\n";
    }
    catch (...)
    {
        
    }
    try
    {
        C &tmpc = dynamic_cast<C &>(p);
        (void)tmpc;
        std::cout << "The actual type is C\n";
    }
    catch (...)
    {
        
    }   
}