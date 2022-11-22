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

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
				typedef T				value_type;
				typedef Alloc			allocator_type;
				void					init(void);
				void					print(void);
		private:
				value_type	_vtype;
				vector(allocator_type type, )
	};
}

#endif