/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:11:25 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/13 19:58:31 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/***** Canonical (pricate) copilen to avoid the class to be instanciable */
ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& src){
    (void) src;    
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src){
    (void) src;
    return (*this);
}

ScalarConverter::~ScalarConverter(){}

/****** Static Convert function *********/

 void ScalarConverter::convert(const std::string& input)
{
    
    if (isInt(input))
    {
        int i;
        std::istringstream iss(input);
        iss >> i;
        std::cout << "int:" << static_cast<int>(i) << std::endl;
    }
    else
        throw ScalarConverter::ConvError("Impossible");
}

bool ScalarConverter::isInt(const std::string& input)
{
    long value;
    std::istringstream iss(input);
    iss >> value;
    if (iss.fail() || !iss.eof())
        return (false);
    if (value > INT_MAX || value < INT_MIN)
        return (false);
    return (true);
}

ScalarConverter::ConvError::ConvError(const std::string& msg) : std::logic_error(msg) {}

// static bool isFloat(std::string input);
//     static bool isDouble(std::string input);
//     static bool isChar(std::string input);
//     static bool isSpecial(std::string input);

