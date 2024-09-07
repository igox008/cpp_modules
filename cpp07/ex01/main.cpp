/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:35:55 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/07 23:33:15 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    add_one(int &n)
{
    n++;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    std::cout << "before  : \n";
    for (int i = 0; i < 5;i++)
    {
        std::cout << arr[i];
        if (i + 1 != 5)
            std::cout << " ";
    }
    std::cout << '\n';
    iter(arr, 5, add_one); 
    std::cout << "after  : \n";
    for (int i = 0; i < 5;i++)
    {
        std::cout << arr[i];
        if (i + 1 != 5)
            std::cout << " ";
    }
    std::cout << '\n';
}