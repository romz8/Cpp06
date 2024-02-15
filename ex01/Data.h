/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:03:08 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/15 16:33:14 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define GREEN "\033[32m"
#   define RED "\033[31m"
# define RESET "\033[0m"
# include <string>

typedef struct 
{
    int value;
    std::string name;
} Data;

#endif
