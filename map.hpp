#ifndef MAP_HPP
#define MAP_HPP
#include "vector.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "pair.hpp"
#include "utils.hpp"

namespace ft
{
	template <	class Key,
		class T,
		class Compare = std::less< Key >,
		class Alloc = std::allocator< ft::pair< const Key, T > >
	>

	class map
	{
		// [ MEMBER TYPES ]
	public:
		class 												value_compare; // defined on line 71

		typedef Key                                         			key_type;
		typedef	T			 											mapped_type;
		typedef ft::pair< const key_type, mapped_type >					value_type;
		typedef Compare                                     			key_compare;
		typedef Alloc													allocator_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef unsigned long int										size_type;
		typedef BNode<key_type, mapped_type>* node;

	private:
		allocator_type													_alloc;
		key_compare														_comp;
		node															_root;
		size_type														_length;
	public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
	};
}

#endif