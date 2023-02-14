/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:17:23 by esafar            #+#    #+#             */
/*   Updated: 2023/02/14 13:15:40 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../../containers.hpp"

namespace ft
{
    template <class T, class Container = std::vector<T> >
    class stack
    {
        public:
            typedef T value_type;
            typedef Container container_type;

        protected:
            container_type _container;

        public:

            explicit stack(const container_type& ctnr = container_type()) : _container(ctnr) {}
            ~stack() {}
            stack& operator=(const stack& x) 
			{
                _container = x._container;
                return (*this);
            }

            value_type& top() 
			{
                return (_container.back());
            }
            const value_type& top() const 
			{
                return (_container.back());
            }
            

			// STACK_EMPTY


            bool empty() const 
			{
                return (_container.empty());
            }


			// STACK_SIZE


            size_t size() const 
			{
                return (_container.size());
            }
            

			// STACK_PUSH


            void push(const value_type& val) 
			{
                _container.push_back(val);
            }


			// STACK_POP


            void pop() 
			{
                _container.pop_back();
            }
           
            friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) 
			{
                return (lhs._container == rhs._container);
            }
            friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) 
			{
                return (lhs._container != rhs._container);
            }
            friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) 
			{
                return (lhs._container < rhs._container);
            }
            friend bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) 
			{
                return (lhs._container <= rhs._container);
            }
            friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) 
			{
                return (lhs._container > rhs._container);
            }
            friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) 
			{
                return (lhs._container >= rhs._container);
            }
    };
}

#endif