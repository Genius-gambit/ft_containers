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
				typedef T				value_type;
				typedef Alloc			allocator_type;
				typedef std::size_t		size_type;
				void					print(void) { std::cout << "Size is " << this->_size << ", Capacity: " << this->_capacity << std::endl; }

				/************Iterators************************/
				iterator				begin() 						{		return iterator(_elem); 						};
				
				/************Constructors************************/
				explicit vector (const allocator_type& alloc = allocator_type()) : _arr(NULL), _alloc(alloc), _capacity(0), _size(0) {};
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _arr(NULL), _alloc(alloc), _capacity(0), _size(0) { insert(begin(), n, val); };
				vector(const vector &x) : _arr(_alloc.allocate(x._capacity)), _alloc(x._alloc), _capacity(x._capacity), _size(x._size){};
				~vector() { _alloc.deallocate(_arr, _capacity); }
				

				/************Member Functions************************/
				void					reserve(size_type n)
				{
					if (n <= _capacity)	return ;
					if (n > max_size())
						throw std::length_error("requested allocation size is greater than max size");
					T	*new_vec = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(&new_vec[i], _elem[i]);
						_alloc.destroy(&_elem[i]);
					}
					_alloc.deallocate(_elem, _capacity);
					_elem = new_vec;
					_capacity = n;
				}
				iterator insert (iterator position, const value_type& val);
				void insert (iterator position, size_type n, const value_type& val);
				{
					size_type			i = position - begin();

					if ((_size + n) > _capacity)
						reserve(_new_capacity(_size + n));
					for (size_type j = n + _size - 1; j > i + n - 1; j -= 1)
					{
						_alloc.construct(&_elem[j], _elem[j - n]);
						_alloc.destroy(&_elem[j - n]);
					}
					for (size_type k = i; k < i + n; k++)
					{
						_alloc.construct(&_elem[k], val);
						_size++;
					}
				}


		private:
				value_type			*_arr;
				allocator_type		_alloc;
				size_type			_capacity;
				size_type			_size;
	};
}

#endif