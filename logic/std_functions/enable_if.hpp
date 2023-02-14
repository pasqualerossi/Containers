/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:03:00 by esafar            #+#    #+#             */
/*   Updated: 2023/02/13 14:38:17 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

# include "../../containers.hpp"

namespace ft
{
    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> { typedef T type; };
}

#endif