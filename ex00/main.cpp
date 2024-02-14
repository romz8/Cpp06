/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:48:30 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/14 13:42:30 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "wrong program input : 1 argument " << std::endl;
        return (-1);
    }
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
