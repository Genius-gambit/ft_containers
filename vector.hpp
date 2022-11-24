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

				/************MEMBER FUNCTIONS************************/
				explicit vector (const allocator_type& alloc = allocator_type()) : _arr(NULL), _alloc(alloc), _capacity(0), _size(0) {};
				explicit vector (size_type n, const value_type& val = value_type(),                 const allocator_type& alloc = allocator_type()) : _arr(NULL), _alloc(alloc), _capacity(n), _size(n) {(void)val;};
				vector(const vector &x) : _arr(_alloc.allocate(x._capacity)), _alloc(x._alloc), _capacity(x._capacity), _size(x._size) {};
				~vector() { _alloc.deallocate(_arr, _capacity); }
		private:
				value_type			*_arr;
				allocator_type		_alloc;
				size_type			_capacity;
				size_type			_size;
	};
}

#endif