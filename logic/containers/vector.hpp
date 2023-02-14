/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:56:32 by esafar            #+#    #+#             */
/*   Updated: 2023/02/14 13:14:07 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../containers.hpp"

namespace ft 
{
	template<typename Iterator>
	std::ptrdiff_t distance(Iterator first, Iterator last) 
	{
		std::ptrdiff_t dist = 0;
		while (first != last) 
		{
			++dist;
			++first;
		}
		return (dist);
	}


  // VECTOR_CLASS


  template < class T, class Alloc = std::allocator<T> >
  class vector 
  {
	
    public:
		typedef T                                                         value_type;
		typedef Alloc                                                     allocator_type;
		typedef typename allocator_type::reference                        reference;                
		typedef typename allocator_type::const_reference                  const_reference;          
		typedef typename allocator_type::pointer                          pointer;                  
		typedef typename allocator_type::const_pointer                    const_pointer;            
		typedef ft::random_access_iterator<value_type>                    iterator;
		typedef ft::random_access_iterator<const value_type>              const_iterator;
		typedef ft::reverse_iterator<iterator>                            reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>                      const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type   difference_type;          
		typedef typename allocator_type::size_type                        size_type;                

    private:
		allocator_type    _alloc;
		pointer           _ptr;
		size_type         _capacity;
		size_type         _size;

    public:

		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _capacity(0), _size(0) {}

		
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _ptr(NULL), _capacity(n), _size(n) 
		{
			if (_ptr == NULL)
				_ptr = _alloc.allocate(n);
			
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_ptr + i, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _alloc(alloc), _size(0) 
		{
			difference_type n = ft::distance(first, last);
			
			_ptr = _alloc.allocate(n);
			_capacity = n;
			for (; first != last; first++)
				push_back(*first);
		}

		
		vector(const vector& x) : _alloc(allocator_type()), _ptr(NULL), _capacity(0), _size(0) 
		{
			assign(x.begin(), x.end());
		}

		~vector() 
		{
			clear();
			if (_capacity > 0)
				_alloc.deallocate(_ptr, _capacity);
		}

		
		vector& operator=(const vector& x) 
		{
			if (this != &x) 
			{
				clear();
				assign(x.begin(), x.end());
			}
			return (*this);
		}

		
		iterator begin() 
		{
			return (iterator(_ptr));
		}
		const_iterator begin() const 
		{
			return (const_iterator(_ptr));
		}

		iterator end() 
		{
			return (iterator(_ptr + _size));
		}
		const_iterator end() const 
		{
			return (const_iterator(_ptr + _size));
		}

		reverse_iterator rbegin() 
		{
			return (reverse_iterator(end()));
		}
		const_reverse_iterator rbegin() const 
		{
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend() 
		{
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const 
		{
			return (const_reverse_iterator(begin()));
		}

		size_type size() const 
		{
			return (_size);
		}

		size_type max_size() const 
		{
			return (_alloc.max_size());
		}


		// VECTOR_RESIZE


		void resize(size_type n, value_type val = value_type()) 
		{
			if (n > _capacity) reserve(n);
			if (n >= _size) 
			{
				for (size_type i = _size; i < n; i++)
				_alloc.construct(_ptr + i, val);
			} else 
			{
				for (size_type i = n; i < _size; i++)
				_alloc.destroy(_ptr + i);
				_capacity = n;
			}
			_size = n;
		}


		// VECTOR_CAPACITY


		size_type capacity() const 
		{
			return (_capacity);
		}


		// VECTOR_EMPTY


		bool empty() const 
		{
			return (size() == 0 ? true : false);
		}


		// VECTOR_RESERVE


		void reserve(size_type n) 
		{
			if (n > max_size()) 
			{
				throw (std::length_error("ft::vector::reserve"));
			} else if (n > _capacity) 
			{
				pointer new_ptr = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				_alloc.construct(new_ptr + i, *(_ptr + i));
				_alloc.deallocate(_ptr, _capacity);
				_ptr = new_ptr;
				_capacity = n;
			}
		}

		reference operator[](size_type n) 
		{
			return (_ptr[n]);
		}
		const_reference operator[](size_type n) const 
		{
			return (_ptr[n]);
		}

		reference at(size_type n) 
		{
			if (n >= size()) 
			{
				throw (std::out_of_range("ft::vector::at"));
			} 
			else 
			{
				return (_ptr[n]);
			}
		}
		const_reference at(size_type n) const 
		{
			if (n >= size()) 
			{
				throw (std::out_of_range("ft::vector::at"));
			} 
			else 
			{
				return (_ptr[n]);
			}
		}

		reference front() 
		{
			return (*begin());
		}
		const_reference front() const 
		{
			return (*begin());
		}

		reference back() 
		{
			return (*(end() - 1));
		}
		const_reference back() const 
		{
			return (*(end() - 1));
		}


		// VECTOR_ASSIGN


		template <class InputIterator>
		void	assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0) 
		{
			this->clear();
			while (first != last) 
			{
				push_back(*first);
				++first;
			}
		}
		
		void	assign(size_type n, const value_type& val) 
		{
			this->clear();
			while (n) 
			{
				push_back(val);
				--n;
			}
		}


		// VECTOR_PUSH_BACK


		void push_back(const value_type& val) 
		{
			if (_size == _capacity)
				empty() ? reserve(1) : reserve(_size * 2);
			_alloc.construct(_ptr + _size, val);
			_size++;
		}
		

		// VECTOR_POP_BACK


		void pop_back() 
		{
			if (_size > 0) 
			{
				_alloc.destroy(_ptr + (_size - 1));
				_size--;
			}
		}


		// VECTOR_INSERT


		iterator insert (iterator position, const value_type& val) 
		{
			size_type n = ft::distance(begin(), position);
			insert(position, 1, val);
			return (iterator(&this->_ptr[n]));
		}
		void insert (iterator position, size_type n, const value_type& val) 
		{
			vector tmp(position, end());
			this->_size -= ft::distance(position, end());
			while (n) 
			{
				push_back(val);
				--n;
			}
			iterator it = tmp.begin();
			while (it != tmp.end()) 
			{
				push_back(*it);
				++it;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) 
		{
			vector tmp(position, end());
			this->_size -= ft::distance(position, end());
			while (first != last) 
			{
				push_back(*first);
				++first;
			}
			iterator it = tmp.begin();
			while (it != tmp.end()) 
			{
				push_back(*it);
				++it;
			}
		}


		// VECTOR_ERASE


		iterator erase(iterator position) 
		{
			if (empty())
				return (end());
			iterator it = begin();
			while (it != position)
				it++;
			_alloc.destroy(&(*it));
			while (it + 1 != end()) 
			{
				_alloc.construct(&(*it), *(it + 1));
				it++;
			}
			pop_back();
			return (position);
		}
		iterator erase(iterator first, iterator last) 
		{
			if (empty())
				return (end());
			iterator it = begin();
			iterator rtn = first;
			difference_type dist = last - first;
			while (it != first)
				it++;
			for (; first != last; first++)
				_alloc.destroy(&(*first));
			while (it + dist != end()) 
			{
				_alloc.construct(&(*it), *(it + dist));
				it++;
			}
			while (dist-- > 0)
				pop_back();
			return (rtn);
		}


		// VECTOR_SWAP


		void swap(vector& x) 
		{
			allocator_type    tmp_alloc = _alloc;
			pointer           tmp_ptr = _ptr;
			size_type         tmp_capacity = _capacity;
			size_type         tmp_size = _size;

			_alloc = x._alloc;
			_ptr = x._ptr;
			_capacity = x._capacity;
			_size = x._size;

			x._alloc = tmp_alloc;
			x._ptr = tmp_ptr;
			x._capacity = tmp_capacity;
			x._size = tmp_size;
		}


		// VECTOR_CLEAR


		void clear() 
		{
			if (_size > 0) 
			{
				for (iterator it = begin(); it != end(); it++)
				_alloc.destroy(&(*it));
				_size = 0;
			}
		}

		allocator_type get_allocator() const 
		{
			return (Alloc(_alloc));
		}

		private:
			void move_backward(iterator position, size_type n = 1) 
			{
				if (position == end())
					return ;
				move_backward(position + 1, n);
				_alloc.construct(&(*(position + n)), *position);
			}
	};


	// VECTOR_TEMPLATES


	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) 
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) 
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator< (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) 
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) 
	{
		return (!(lhs > rhs));
	}
	template <class T, class Alloc>
	bool operator> (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) 
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) 
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) 
	{
		x.swap(y);
	}
}