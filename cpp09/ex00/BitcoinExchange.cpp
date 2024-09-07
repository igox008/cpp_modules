/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:04:13 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/07 23:36:16 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::~BitcoinExchange()
{
    this->store.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
    if (this == &cpy)
        return ;
    *this = cpy;
}

std::map<std::string, double> BitcoinExchange::getStore(void) const
{
    return (this->store);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    if (this == &cpy)
        return *this;
    this->store = cpy.getStore();
    return (*this);
}

void BitcoinExchange::getDataCsv(const std::string file)
{
    std::ifstream input(file);
    if (!input)
        throw CantOpenFile();
    std::string line;
    if (std::getline(input, line).fail())
    {
        input.close();
        throw CantReadFile();
    }
    if (line != "date,exchange_rate")
    {
        input.close();
        throw HeaderDontExist();
    }
    line.clear();
    while (std::getline(input, line))
    {
        std::stringstream ss(line);
        std::string date; std::getline(ss, date, ',');
        double ex_rate; ss >> ex_rate;
        this->store[date] = ex_rate;
        line.clear();
    }
    input.close();
}

std::string trimStr(std::string &s, char c)
{
    size_t start = 0;
    size_t end = s.size() - 1;

    while (start < s.size() && s[start] == c)
        start++;
    if (start == s.size())
        return ("");
    while (end > start && s[end] == c)
        end--;
    return (s.substr(start, end - start + 1));
}

int cnt_w(std::string s)
{
    int i = 0;
    int cnt = 0;
    int cnt_p = 0;

    while (s[i])
    {
        while (s[i] && (s[i] == '|' || s[i] == ' '))
        {
            (s[i] == '|') && (cnt_p++);
            i++;
        }
        if (s[i] != '\0')
            cnt++;
        while (s[i] && s[i] != '|' && s[i] != ' ')
            i++;
    }
    if (cnt_p != 1)
        return (-1);
    return (cnt);
}

void BitcoinExchange::handleInputCsv(const std::string file)
{
    std::ifstream input(file);
    if (!input)
        throw CantOpenFile();
    std::string line;
    if (std::getline(input, line).fail())
    {
        input.close();
        throw CantReadFile();
    }
    if (line != "date | value")
    {
        input.close();
        throw HeaderDontExist();
    }
    line.clear();
    if (input.eof())
        throw EmptyFile();
    while (std::getline(input, line))
    {
        if (cnt_w(line) != 2)
            std::cerr << "Error: bad input => " << line << '\n';
        else
        {
            std::stringstream ss(line);
            std::string date; std::getline(ss, date, '|');
            date = trimStr(date, ' ');
            double value; ss >> value;
            bool ssFail = ss.fail();
            std::string tmp;
            if (std::getline(ss, tmp) || ssFail)
                std::cerr << "Error: bad input => \"" << line << "\"\n";
            else
                parseInput(date, value);
            line.clear();
        }
    }
    input.close();
}

bool check_validity(std::string s)
{
    int i = 0;
    int cnt = 0;
    int cnt_del = 0;
    char del = '-';

    while (s[i])
    {
        while (s[i] && s[i] == del)
        {
            i++;
            cnt_del++;
        }
        if (s[i] != '\0')
            cnt++;
        while (s[i] && s[i] != del)
        {
            if (!(s[i] >= '0' && s[i] <= '9'))
                return (false);
            i++;
        }
    }
    if (cnt_del == 2 && cnt == 3)
        return (true);
    return (false);
}

bool isLeapYear(long year)
{
    if (year % 4 == 0)
    {
        if (year % 100 != 0)
            return (true);
        else
        {
            if (year % 400 == 0)
                return (true);
        }
    }
    return (false);
}

bool check_syntax(std::string tmp)
{
    std::string y;
    std::string m;
    std::string d;

    std::stringstream t(tmp);
    t >> y >> m >> d;
    if (y.size() != 4 || m.size() != 2 || d.size() != 2)
        return (false);
    return (true);
}

void BitcoinExchange::parseInput(std::string date, double value)
{
    if (value < 0)
    {
        std::cerr <<"Error: not a positive number.\n";
        return ;
    }
    if (value > 1000)
    {
        std::cerr <<"Error: too large a number.\n";
        return ;
    }
    
    if (!check_validity(date))
    {
        std::cerr << date << ": date not valid\n";
        return ;
    }
    long d, m, y;
    std::string tmp = date;
    for (int i = 0;tmp[i];i++)
        (tmp[i] == '-') && (tmp[i] = ' ');
    if (!check_syntax(tmp))
    {
        std::cerr << date << ": date not valid, must be YYYY-MM-DD, example : 2024-09-04\n";
        return ;
    }
    std::stringstream ss(tmp);
    ss >> y >> m >> d;
    if (y < 2009 || (y == 2009 && m == 1 && d < 2) || m < 1 || m > 12 || d < 1 || d > 31)
    {
        std::cerr << date << ": date not valid\n";
        return ;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
    {
        std::cerr << date << ": date not valid, month " << m << " have only 30 days\n";
        return ;
    }
    else if (!isLeapYear(y) && m == 2 && d > 28)
    {
        std::cerr << date << ": date not valid," << y << "is not a leap year\n";
        return ;
    }
    else if (isLeapYear(y) && m == 2 && d > 29)
    {
        std::cerr << date << ": date not valid, February don't have more than 29 days\n";
        return ;
    }
    std::map<std::string, double>::iterator it = this->store.lower_bound(date);
    if (it != this->store.end())
    {
        if (date.compare(it->first))
            --it;
        double final = value * it->second;
        std::cout << date << " => " << value << " = " << final << '\n';
    }
    else
    {
        std::cerr << date << " : is out of range of dates in the database\n";
    }
}