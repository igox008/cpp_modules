/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:39:08 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/06 06:33:27 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <limits>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    private :
        std::vector<int> vec;
        std::vector<int> sortedVec;
        std::deque<int> deq;
        std::deque<int> sortedDeq;
        int             hold;
        bool            odd;
        std::vector<int> jocob;
        PmergeMe();
    public :
        PmergeMe(int ac, char **av);
        ~PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &cpy);
        std::vector<int> getVec(void) const;
        std::deque<int> getDeq(void) const;
        void    sortVec(void);
        void    sortDeq(void);
        void	generateJacob(void);
        void    printSorted(void) const;
};

#endif
