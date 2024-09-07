/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:35:11 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/04 17:53:17 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN()
{
    
}

RPN::~RPN()
{
    
}

RPN::RPN(const RPN &cpy)
{
    if (this == &cpy)
        return ;
    *this = cpy;
}

RPN &RPN::operator=(const RPN &cpy)
{
    if (this == &cpy)
        return *this;
    this->stck = cpy.getStack();
    return (*this);
}

std::stack<double> RPN::getStack(void) const 
{
    return (this->stck);
}

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/'); 
}

void RPN::checkRpn(std::string s)
{
    if (s.size() == 0)
        throw Error();
    std::stringstream ss(s);
    std::string tmp;
    ss >> tmp;
    if (ss.fail())
        throw Error();
    while (1)
    {
        if (tmp.size() != 1 || (!isDigit(tmp[0]) && !isOperator(tmp[0])))
            throw Error();
        tmp.clear();
        ss >> tmp;
        if (ss.fail())
            break;
    }
}

double do_oper(double n1, double n2, char oper)
{
    switch (oper)
    {
        case '*':
            return (n1 * n2);
        case '+' :
            return (n1 + n2);
        case '-' :
            return (n1 - n2);
        case '/' :
            return (n1 / n2);
        default:
            break;
    }
    return (0);
}

void RPN::execOperations(std::string s)
{
    std::stringstream ss(s);
    std::string str;
    while ((ss >> str) && !ss.fail())
    {
        char tmp = str[0];
        if (isOperator(tmp) && this->stck.size() < 2)
            throw Error();
        else if (isOperator(tmp))
        {
            double n1 = this->stck.top();
            this->stck.pop();
            double n2 = this->stck.top();
            if (n1 == 0 && tmp == '/')
                throw DivisionByZero();
            this->stck.pop();
            this->stck.push(do_oper(n2, n1, tmp));
        }
        else if (isDigit(tmp))
        {
            double n = (double)(tmp - '0');
            this->stck.push(n);
        }
    }
    if (this->stck.size() != 1)
        throw Error();
    double result = this->stck.top();
    this->stck.pop();
    std::cout << result << '\n';
}