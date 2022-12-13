#ifndef VECTOR_HPP
# define VECTOR_HPP

/***************************LIBRARIES********************************/
# include <vector>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>
# include <memory>
# include <cstddef>
# include "v_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T													value_type;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef std::size_t											size_type;
		typedef ft::iterator<T>										iterator;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;

		/********************************** Iterators Functions *******************************************************************/

		iterator				begin() { return iterator(_arr); };

		iterator				end() { return iterator(_arr + _size); };

		/********************************** Constructors & Destructors *******************************************************************/

		explicit vector(const allocator_type& alloc = allocator_type()): _arr(NULL), _alloc(alloc), _capacity(0), _size(0) {};

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _arr(NULL), _alloc(alloc), _capacity(0), _size(0)
		{
			(void)val;
			(void)n;
			insert(begin(), n, val);
		};

		vector(const vector& x): _arr(_alloc.allocate(x._capacity)), _alloc(x._alloc), _capacity(x._capacity), _size(x._size) {};

		~vector() { _alloc.deallocate(_arr, _capacity); }


		/********************************** Member Functions *******************************************************************/

		/********************************** Allocators Functions *******************************************************************/

		/********************************** Capacity Functions *******************************************************************/

		size_type capacity() const { return (_capacity); }

		size_type	max_size() { return (_alloc.max_size()); }

		size_type size() const { return (_size); };

		void resize(size_type n, value_type val = value_type());

		void					reserve(size_type n)
		{
			if (n <= _capacity)	return;
			if (n > max_size())
				throw std::length_error("Allocation size is greater than the max size");
			T* new_vec = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(&new_vec[i], _arr[i]);
				_alloc.destroy(&_arr[i]);
			}
			_alloc.deallocate(_arr, _capacity);
			_arr = new_vec;
			_capacity = n;
		}

		bool empty() const { return (_size == 0 ? true : false); }

		void insert(iterator position, size_type n, const value_type& val)
		{
			(void)n;
			(void)val;
			(void)position;
			// std::cout << position.base() << "\n";
		}

		void	insert(const value_type& val)
		{
			_capacity += 2;
			_arr = _alloc.allocate(_capacity);
			_alloc.construct(_arr, val);
		}

		void	print()
		{
			int	i;

			i = 0;
			while (i < (int)_size)
			{
				std::cout << _arr[i] << std::endl;
				i++;
			}
		}

		/********************************** Element access Functions *******************************************************************/

		reference at(size_type n) { return (_arr[n]); }

		reference operator[] (size_type n)
		{
			if (n < _size)
				return (_arr[n]);
			return (_arr[n]);
		}

		reference front() { return (_arr[0]); }

		reference back() { return (_arr[_size - 1]); }

		/********************************** Modifers Functions *******************************************************************/

		void	push_back(const value_type& val)
		{
			if (_size == _capacity)
				reserve(_new_capacity(_size + 1));
			_alloc.construct(_arr + _size, val);
			_size++;
		}

		void pop_back()
		{
			if (_size > 0)
			{
				_alloc.destroy(_arr + _size);
				_size--;
			}
		}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_arr[i]);
			_size = 0;
		}

	private:
		value_type* _arr;
		allocator_type		_alloc;
		size_type			_capacity;
		size_type			_size;
		size_type			_new_capacity(size_type size)
		{
			size_type	n;

			n = 1;
			for (n = 1; n < size; n *= 2);
			return (n);
		}
	};
}

#endif