/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:25:38 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/16 12:37:13 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# define GREEN  "\033[32m"     
# define YELLOW "\033[33m"     
# define BLUE   "\033[34m"
# define RESET  "\033[0m"

class Base
{
public:
    virtual ~Base();
};

#endif
