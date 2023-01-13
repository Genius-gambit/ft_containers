#ifndef MAP_HPP
#define MAP_HPP
#include "vector.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "pair.hpp"

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
		typedef ft::pair< const Key, T >     							value_type;
		typedef Compare                                     			key_compare;
		typedef Alloc													allocator_type;

	private:
		typedef RBTree<value_type, value_compare, allocator_type>		rbtree;

	public:
		typedef typename allocator_type::reference          reference;
		typedef typename allocator_type::const_reference   	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef typename rbtree::iterator					iterator;
		typedef typename rbtree::const_iterator				const_iterator;
		typedef ft::reverse_iterator< iterator >			reverse_iterator;
		typedef ft::reverse_iterator< const_iterator >		const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type		difference_type;
		typedef size_t													size_type;
		typedef node< value_type >                          treeNode;


	private:
		rbtree												_tree;
		key_compare											_compare;
		allocator_type										_alloc;
	};
}

#endif