/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:16:53 by alaassir          #+#    #+#             */
/*   Updated: 2024/08/30 23:13:47 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
    (void)cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
    (void)cpy;
    return *this;
}

bool    isInt(const std::string str)
{
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return false;
    for (;str[i];i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}

bool isChar(const std::string str)
{
    if (str.length() > 1)
        return false;
    return true;
}

bool isFloat(const std::string str, bool &isInf)
{
    if (str == "-inff" || str == "+inff" || str == "inff" || (str == "nanf" && (isInf = true)) )
        return (true);
    int i = 0;
    int f_count = 0;
    int p_count = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == '.')
        (1) && (i++, p_count++);
    for (;str[i];i++)
    {
        if ((f_count > 0 && (str[i] || !p_count)) || p_count > 1)
            return false;
        else if (str[i] == 'f')
            f_count++;
        else if (str[i] == '.')
            p_count++;
        else if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    if (f_count != 1 || p_count != 1)
        return false;
    return true;
}

bool isDouble(const std::string str, bool &isInf)
{
    if (str == "-inf" || str == "+inf" || str == "inf" || (str == "nan" && (isInf = true)))
        return (true);
    int i = 0;
    int p_count = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == '.')
        (1) && (i++, p_count++);
    for (;str[i];i++)
    {
        if (p_count > 1)
            return false;
        else if (str[i] == '.')
            p_count++;
        else if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    if (p_count != 1)
        return false;
    return true;
}

bool isDisplayable(char c)
{
    return (c >= 32 && c <= 126);
}

void print_out(char c, int n, double d, float f, std::string type, bool isInf, bool isOverf)
{
    if (type == "Impossible")
    {
        std::cout << "char\t: " << type << '\n';
        std::cout << "int\t: " << type << '\n';
        std::cout << "float\t: " << type << '\n';
        std::cout << "double\t: " << type << '\n';
        return ;
    }
    std::cout << "char\t: ";
    if (isInf)
        std::cout << "Impossible\n";
    else if (isDisplayable(c))
        std::cout << "\'" << c << "\'" << '\n';
    else
        std::cout << "Non Printable\n";
    if (!isInf && !isOverf)
        std::cout << "int\t: " << n << '\n';
    else if (isOverf)
        std::cout << "int\t: " << "Out of Range" << '\n';
    else
        std::cout << "int\t: " << "Impossible" << '\n';
    std::cout << "float\t: ";
    std::cout << std::fixed << std::setprecision(2) << f << "f\n";
    std::cout << "Double\t : ";
    std::cout << std::setprecision(6) << d << "\n";
}

void ScalarConverter::convert(std::string str)
{
    char c = 0;
    int n = 0;
    double d = 0.0;
    float f = 0.0f;
    bool isOverf = false;
    bool isInf = false;
    std::string type = "Impossible";
    std::stringstream hold(str);

    if (isInt(str))
    {
        type = "Int";
        int tmp;
        hold >> tmp;
        if (hold.fail())
            throw "int limit exceded or smtg else";
        n = static_cast<int>(tmp);
        d = static_cast<double>(n);
        f = static_cast<float>(n);
        c = static_cast<char>(n);
    }
    else if (isChar(str))
    {
        type = "Char";
        char tmp;
        hold >> tmp;
        if (hold.fail())
            throw "something went wrong";
        c = tmp;
        n = static_cast<int>(tmp);
        d = static_cast<double>(tmp);
        f = static_cast<float>(tmp);
    }
    else if (isDouble(str, isInf))
    {
        type = "Double";
        double tmp;
        hold >> tmp;
        if (hold.fail())
            throw "double limit exceded or smtg else";
        d = tmp;
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            isOverf = true;
        n = static_cast<int>(d);
        f = static_cast<float>(d);
        c = static_cast<char>(d);
    }
    else if (isFloat(str, isInf))
    {
        type = "Float";
        str.pop_back();
        std::stringstream fl(str);
        float tmp;
        fl >> tmp;
        if (fl.fail())
            throw "float limit exceded or smtg else";
        f = tmp;
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            isOverf = true;
        n = static_cast<int>(f);
        d = static_cast<double>(f);
        c = static_cast<char>(f);
    }
    print_out(c, n, d, f, type, isInf, isOverf);
}