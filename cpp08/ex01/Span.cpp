/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:49:12 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/04 10:56:02 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int size)
{
    this->N = size;
}

Span::~Span()
{
    
}

Span &Span::operator=(const Span &cpy)
{
    if (this == &cpy)
        return (*this);
    if (this->arr.size() != 0)
        this->arr.clear();
    this->N = cpy.N;
    for (unsigned int i = 0; i < this->N;i++)
        this->arr.push_back(cpy.arr[i]);
    return (*this);
}

Span::Span(const Span &cpy)
{
    if (this == &cpy)
        return ;
    *this = cpy;
}

void Span::addNumber(const int num)
{
    if (this->arr.size() == this->N)
        throw Span::CantAddNumber();
    this->arr.push_back(num);
}
void Span::addNumbers(std::vector<int>::iterator b, std::vector<int>::iterator e)
{
    if (this->arr.size() == this->N)
        throw Span::CantAddNumber();
    for (;this->arr.size() != this->N && b != e;++b)
        this->arr.push_back(*b);
}

void Span::addNumbers(std::vector<int>::const_iterator b, std::vector<int>::const_iterator e)
{
    if (this->arr.size() == this->N)
        throw Span::CantAddNumber();
    for (;this->arr.size() != this->N && b != e;++b)
        this->arr.push_back(*b);
}

unsigned int Span::shortestSpan(void) const
{
    if (this->arr.size() < 2)
        throw Span::AtLeastTwo();
    Span cpy = *this;
    std::sort(cpy.arr.begin(), cpy.arr.end());
    std::vector<int> &vec = cpy.arr;
    unsigned int min = vec[1] - vec[0];
    for (size_t i = 1; i < vec.size();i++)
    {
        if (i + 1 != vec.size())
        {
            unsigned int tmp = vec[i + 1] - vec[i];
            (tmp < min) && (min = tmp);
        }
        else
            break; 
    }
    return (min);
}

int Span::longestSpan(void) const
{
    if (this->arr.size() < 2)
        throw Span::AtLeastTwo();
    Span cpy = *this;
    std::sort(cpy.arr.begin(), cpy.arr.end());
    return (cpy.arr.back() - cpy.arr[0]);
}
