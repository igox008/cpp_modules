/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:04:36 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/05 02:28:13 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> arr;
    arr.push_back(56);
    arr.push_back(6);
    arr.push_back(-11);
    arr.push_back(4);
    try
    {
        int fnd = easyfind(arr, 1);
        std::cout << fnd << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    arr.push_back(1);
    try
    {
        int fnd = easyfind(arr, 1);
        std::cout << fnd << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}