#ifndef V_ITERATOR_HPP
# define V_ITERATOR_HPP

/***************************LIBRARIES********************************/
# include <iterator>

namespace ft
{
	template< class T >
	class iterator
	{
		public:
				typedef T	valueType;
				T	&begin(void);
	};
}

#endif