/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:19:32 by rjobert           #+#    #+#             */
/*   Updated: 2024/02/15 16:17:59 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


/*************** (NON-INSTANCIABLE) Canonicals ******************************/
Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer::Serializer(const Serializer& src)
{
	(void) (src);
	* this = src;
}
Serializer& Serializer::operator=(const Serializer& src)
{
	(void) src;
	return (*this);
}
	
/*************** (NON-INSTANCIABLE) Canonicals ******************************/

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));		
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
