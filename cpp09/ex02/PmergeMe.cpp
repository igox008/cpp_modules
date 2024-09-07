/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:07:46 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/06 06:43:53 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool parseAv(std::string s)
{
    if (s[0] == '\0')
        return (false);
    for (int i = 0;s[i];i++)
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (false);
    }
    return (true);
}

void printVec(std::vector<int> v, size_t size, std::string msg)
{
    std::cout << msg << ":\t";
    for (size_t i = 0;i < size;i++)
    {
        std::cout << v[i];
        if (i + 1 != size)
            std::cout << ' ';
    }
    std::cout << "\n";
}

void    PmergeMe::generateJacob(void)
{
    long	a = 1;
    long	b = 3;
	long 	n;

	this->jocob.push_back(static_cast<int>(b));
	while (1)
	{
		n = b + (2 * a);
		if (n > std::numeric_limits<int>::max())
			break ;
		this->jocob.push_back(static_cast<int>(n));
		a = b;
		b = n;
	}
}

PmergeMe::PmergeMe(int ac, char **av)
{
    this->odd = false;
    if (ac == 1)
    {
        std::cerr << "Insufficient parameters\n" << "Usage : " << av[0] << " <positive integer sequence>\n";
        exit(1);
    }
    if (ac % 2 != 1)
        this->odd = true;
    for (int i = 1;av[i];i++)
    {
        int tmp;
        std::string av_i = std::string(av[i]);
        std::stringstream ss(av_i);
        ss >> tmp;
        if (!parseAv(std::string(av[i])) || ss.fail())
        {
            std::cerr << "\"" << av[i] << "\" : not a valid integer\n";
            exit(1); 
        }
        if (tmp <= 0)
        {
            std::cerr << "\"" << av[i] << "\" : not a positive integer\n";
            exit(1); 
        }
        this->deq.push_back(tmp);
        this->vec.push_back(tmp);
    }
    printVec(this->vec, this->vec.size(), "Before");
    if (this->odd && this->vec.size() > 1)
    {
        this->hold = this->deq.back();
        this->deq.pop_back();
        this->vec.pop_back();
    }
	generateJacob();
}

void mergeVecs(std::vector<std::vector<int> > &pairs, int left, int mid, int right)
{
    int sz1 = mid - left + 1;
    int sz2 = right - mid;

    std::vector<std::vector<int> > leftVec(sz1);
    std::vector<std::vector<int> > rightVec(sz2);
    for (int i = 0; i < sz1;i++)
        leftVec[i] = pairs[i + left];
    for (int i = 0;i < sz2;i++)
        rightVec[i] = pairs[i + mid + 1];
    int i = 0, j = 0, tmp = left;
    while (i < sz1 && j < sz2)
    {
        if (leftVec[i][0] < rightVec[j][0])
            pairs[tmp++] = leftVec[i++];
        else
            pairs[tmp++] = rightVec[j++];
    }
    while (i < sz1)
        pairs[tmp++] = leftVec[i++];
    while (j < sz2)
        pairs[tmp++] = rightVec[j++];
}

void mergeDeqs(std::deque<std::deque<int> > &pairs, int left, int mid, int right)
{
    int sz1 = mid - left + 1;
    int sz2 = right - mid;

    std::deque<std::deque<int> > leftVec(sz1);
    std::deque<std::deque<int> > rightVec(sz2);
    for (int i = 0; i < sz1;i++)
        leftVec[i] = pairs[i + left];
    for (int i = 0;i < sz2;i++)
        rightVec[i] = pairs[i + mid + 1];
    int i = 0, j = 0, tmp = left;
    while (i < sz1 && j < sz2)
    {
        if (leftVec[i][0] < rightVec[j][0])
            pairs[tmp++] = leftVec[i++];
        else
            pairs[tmp++] = rightVec[j++];
    }
    while (i < sz1)
        pairs[tmp++] = leftVec[i++];
    while (j < sz2)
        pairs[tmp++] = rightVec[j++];
}

void    mergeSortVec(std::vector<std::vector<int> > &pairs, int left, int right)
{
    if (left < right)
    {
        int mid = left + ((right - left) / 2);
        mergeSortVec(pairs, left, mid);
        mergeSortVec(pairs, mid + 1, right);
        mergeVecs(pairs, left, mid, right);
    }
}
void    mergeSortDeq(std::deque<std::deque<int> > &pairs, int left, int right)
{
    if (left < right)
    {
        int mid = left + ((right - left) / 2);
        mergeSortDeq(pairs, left, mid);
        mergeSortDeq(pairs, mid + 1, right);
        mergeDeqs(pairs, left, mid, right);
    }
}

std::vector<int> generateSequence(std::vector<int> jacob, size_t pendSize)
{
    int idx = 1;
    int i = 0;
    int curr = jacob[i];
    if (static_cast<size_t>(curr) > pendSize)
        curr = static_cast<int>(pendSize);
    std::vector <int> seq;
    while (seq.size() < pendSize - 1)
    {
        if (curr == idx)
        {
            idx = jacob[i++];
            curr = jacob[i];
            if (static_cast<size_t>(curr) > pendSize)
                curr = static_cast<int>(pendSize);
        }
        seq.push_back(curr);
        curr--;
    }
    return (seq);
}

void PmergeMe::printSorted(void) const
{
    printVec(this->sortedVec, this->sortedVec.size(), "After");
}

void PmergeMe::sortVec(void)
{
    if (this->vec.size() <= 1)
    {
        this->sortedVec = this->vec;
        return ;
    }
    std::vector<std::vector<int> > pairs;
    size_t i = this->vec.size() / 2;
    size_t j = 0;
    std::vector<int>::iterator it = this->vec.begin();
    while (j < i && it != vec.end())
    {
        std::vector<int> v;
        v.push_back(*it);
        ++it;
        v.push_back(*it);
        ++it;
        if (v[1] > v[0])
            std::swap(v[1], v[0]);
        j++;
        pairs.push_back(v);
    }
    mergeSortVec(pairs, 0, pairs.size() - 1);
    std::vector<int> &mainChain = this->sortedVec;
    std::vector<int> pend;
    std::vector<std::vector<int> >::iterator itr;
    for (itr = pairs.begin(); itr != pairs.end();++itr)
    {
        mainChain.push_back((*itr)[0]);
        pend.push_back((*itr)[1]);
    }
    std::vector<int> seq = generateSequence(this->jocob, pend.size());
    if (pend.size() > 0)
        mainChain.insert(mainChain.begin(), pend[0]);
    for (size_t q = 0;q < seq.size();++q)
    {
        int nToInsert = pend[seq[q] - 1];
        std::vector<int>::iterator index = std::lower_bound(mainChain.begin(), mainChain.end(), nToInsert);
        mainChain.insert(index, nToInsert);
    }
    if (this->odd)
    {
        std::vector<int>::iterator index = std::lower_bound(mainChain.begin(), mainChain.end(), this->hold);
        mainChain.insert(index, this->hold);
    }
}

void PmergeMe::sortDeq(void)
{
    if (this->deq.size() <= 1)
    {
        this->sortedDeq = this->deq;
        return ;
    }
    std::deque<std::deque<int> > pairs;
    size_t i = this->deq.size() / 2;
    size_t j = 0;
    std::deque<int>::iterator it = this->deq.begin();
    while (j < i && it != this->deq.end())
    {
        std::deque<int> v;
        v.push_back(*it);
        ++it;
        v.push_back(*it);
        ++it;
        if (v[1] > v[0])
            std::swap(v[1], v[0]);
        j++;
        pairs.push_back(v);
    }
    mergeSortDeq(pairs, 0, pairs.size() - 1);
    std::deque<int> &mainChain = this->sortedDeq;
    std::deque<int> pend;
    std::deque<std::deque<int> >::iterator itr;
    for (itr = pairs.begin(); itr != pairs.end();++itr)
    {
        mainChain.push_back((*itr)[0]);
        pend.push_back((*itr)[1]);
    }
    std::vector<int> seq = generateSequence(this->jocob, pend.size());
    if (pend.size() > 0)
        mainChain.insert(mainChain.begin(), pend[0]);
    for (size_t q = 0;q < seq.size();++q)
    {
        int nToInsert = pend[seq[q] - 1];
        std::deque<int>::iterator index = std::lower_bound(mainChain.begin(), mainChain.end(), nToInsert);
        mainChain.insert(index, nToInsert);
    }
    if (this->odd)
    {
        std::deque<int>::iterator index = std::lower_bound(mainChain.begin(), mainChain.end(), this->hold);
        mainChain.insert(index, this->hold);
    }
}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
    if (this == &cpy)
        return ;
    *this = cpy;
}

std::vector<int> PmergeMe::getVec(void) const
{
    return (this->vec);
}

std::deque<int> PmergeMe::getDeq(void) const
{
    return (this->deq);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
    if (this == &cpy)
        return *this;
    this->vec = cpy.getVec();
    this->deq = cpy.getDeq();
    return *this;
}

