#ifndef VECTOR_HPP
# define VECTOR_HPP

/***************************LIBRARIES********************************/
# include <memory>
# include <algorithm>
# include <cstddef>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
				typedef T	value_type;

		typedef Alloc		allocator_type;

		typedef typename	allocator_type::reference	ref;

		typedef typename	allocator_type::const_reference	const_ref;

	};
}

#endif