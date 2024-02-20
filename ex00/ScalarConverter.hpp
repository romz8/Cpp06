/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:03:14 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/20 14:45:23 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>
# include <sstream>
# include <climits>
# include <cfloat>
# include <iomanip>

enum LiteralType
{
    CastChar,
    CastInt,
    CastFloat,
    CastDouble,
    CastSpecial
};

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

    static LiteralType ParsingType(const std::string& input);

    static bool isInt(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);
    
    static void ConvertChar(const std::string& input);
    static void ConvertInt(const std::string& input);
    static void ConvertFloat(const std::string& input);
    static void ConvertDouble(const std::string& input);
    static void ConvertSpecial(const std::string& input);
};

#endif
