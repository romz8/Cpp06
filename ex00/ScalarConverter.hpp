/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:03:14 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/13 19:56:21 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <climits>

class ScalarConverter
{
public:
    static void convert(const std::string& input);
    class ConvError : public std::logic_error
    {
        public:
            ConvError(const std::string & msg);
    };
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ScalarConverter& operator=(const ScalarConverter& src);
    ~ScalarConverter();

    static bool isInt(const std::string& input);
    // static bool isFloat(std::string input);
    // static bool isDouble(std::string input);
    // static bool isChar(std::string input);
    // static bool isSpecial(std::string input);
};
