/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:11:25 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/20 14:54:09 by rjobert          ###   ########.fr       */
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
    std::cout << std::fixed << std::setprecision(1);
    LiteralType casting = ParsingType(input);
    switch(casting)
    {
        case CastChar:
            ConvertChar(input);
            break;
        case CastInt:
            ConvertInt(input);
            break;
        case CastFloat:
            ConvertFloat(input);
            break;
        case CastDouble:
            ConvertDouble(input);
            break;
        case CastSpecial:
            ConvertSpecial(input);
            break;
        default:
            throw ScalarConverter::ConvError("Impossible to Convert");
    }
}

/********************** Parsing ********************************/

/*detect Literal at the input level and return its type, to later implement 
the casting according to its type.
if one character lenght and not digit -> char
if special input type -> special
if only digigt, never . nor f -> inte
*/
LiteralType ScalarConverter::ParsingType(const std::string& input)
{
    if (input.length() == 3 && input[0] == '\''&& input[2] == '\'' && !std::isdigit(input[1]))
        return (CastChar);
    else if (input == "-inff" || input == "+inff" || input == "-inf" \
        || input == "+inf" || input == "nan")
            return (CastSpecial);
    else if (isInt(input))
        return (CastInt);
    else if (isFloat(input))
        return (CastFloat);
    else if (isDouble(input))
        return (CastDouble);
    else
        throw ScalarConverter::ConvError("Parsing Error - Unknown Scalar Type");
}


// to refacto for int, float and double in one function with array and position given type compared
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

/*
we check that a number is a flaot : format xxxx.yyyf where x an y are digit. 
parsing reject if neither f nor . is found.
special case of parsing the 42.0f : if non-empty and last char is f -> pop it back to parse
with stringstream.
then we check if the last numebr is not '.' to avoid number like 42.f (invalid) instead of 42.0f
beceause the function is const string & and the ParsingType as well, we pass it 
in a string non-const type
*/
bool ScalarConverter::isFloat(const std::string& inpt)
{
    std::string input = inpt;
    double value;
    if (!input.empty() && (input[input.length() -1] != 'f' || input.find('.') == std::string::npos))
        return (false);
    input.erase(input.length() - 1);
    std::istringstream iss(input);
    iss >> value;
    if (iss.fail() || !iss.eof())
        return (false);
    if (value > FLT_MAX || value < -FLT_MAX)
        throw ScalarConverter::ConvError("Impossible to convert - Float Overflow");
    return (true);
}

bool ScalarConverter::isDouble(const std::string& input)
{
    long double value;
    char *end;
    if (!input.empty() && input.find('.') == std::string::npos)
        return (false);
    std::istringstream iss(input);
    iss >> value;
    if (iss.fail() || !iss.eof())
        return (false);
    if (value > DBL_MAX || value < -DBL_MAX)
        throw ScalarConverter::ConvError("Impossible to convert - Double Overflow");
    const char *cinput = input.c_str();
    std::strtod(cinput, &end);
    if (end == cinput + input.size())
        return (true);
    else
        return (false);
}

/********** Conversion Function : Static_cast for each LiteralType ************/

void ScalarConverter::ConvertChar(const std::string& input)
{
    int i = input[1];
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    
    if (c > 32 && c < 126 )
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Not Displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << 'f' << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::ConvertInt(const std::string& input)
{
    int i;
    std::istringstream iss(input);
    iss >> i; 
    
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    
    if (c > 32 && c < 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Not Displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::ConvertFloat(const std::string& inpt)
{
    float f;
    std::string input = inpt;
    input.erase(input.length() - 1);
    std::istringstream iss(input);
    iss >> f; 
    
    int i = static_cast<int>(f);
    char c = static_cast<char>(i);
    double d = static_cast<double>(f);
    
    if (c > 32 && c < 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Not Displayable" << std::endl;
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "int: " << "Impossible (overflow)" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
void ScalarConverter::ConvertDouble(const std::string& input)
{
    double d;
    std::istringstream iss(input);
    iss >> d;

    int i = static_cast<int>(d);
    char c = static_cast<char>(i);
    float f = static_cast<float>(d);
    
    if (c > 32 && c < 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Not Displayable" << std::endl;
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: " << "Impossible (overflow)" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    if (d > FLT_MAX || d < -FLT_MAX)
        std::cout << "float: " << "Impossible (overflow)" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
void ScalarConverter::ConvertSpecial(const std::string& ipt)
{
    std::string input = ipt;
    if (input == "-inff" ||  input == "+inff" ||  input == "nanf")
        input.erase(input.length() - 1);
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: " << input << 'f' << std::endl;
    std::cout << "double: " << input << std::endl;
}


/************************** Special Handler ************************************/

ScalarConverter::ConvError::ConvError(const std::string& msg) : std::logic_error(msg) {}

