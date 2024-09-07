/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 00:33:27 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/06 06:38:38 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    PmergeMe pmergeMe(ac, av);
    clock_t start1 = clock();
    pmergeMe.sortVec();
    clock_t end1 = clock();
    clock_t start2 = clock();
    pmergeMe.sortDeq();
    clock_t end2 = clock();
    pmergeMe.printSorted();
    double final1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
    double final2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;
    std::cout << "Time to process a range of " << ac << " elements with std::vector: " << std::fixed << std::setprecision(6) << final1 << " us\n";
    std::cout << "Time to process a range of " << ac << " elements with std::deque : " << std::setprecision(6) << final2 << " us\n";
}