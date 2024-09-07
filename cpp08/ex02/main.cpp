/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:41:05 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/03 23:34:49 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> tmp_stack;
    tmp_stack.push(5);
    tmp_stack.push(17);
    std::cout << tmp_stack.top() << std::endl;
    tmp_stack.pop();
    std::cout << tmp_stack.size() << std::endl;
    tmp_stack.push(3);
    tmp_stack.push(5);
    tmp_stack.push(737);
    tmp_stack.push(0);
    MutantStack<int> mstack = tmp_stack;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}