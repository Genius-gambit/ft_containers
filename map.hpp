#ifndef MAP_HPP
#define MAP_HPP
#include "vector.hpp"
#include "pair.hpp"
#include "utils.hpp"
#include "map_iterator.hpp"
#include <functional>

namespace ft
{
	template <class Key,
			  class T,
			  class Compare = std::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T> > >

	class map
	{
			// [ MEMBER TYPES ]
		public:
			class value_compare; // defined on line 71

			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef T &reference;
			typedef const T &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;
			typedef unsigned long int size_type;
			typedef BNode<key_type, mapped_type> *node;
			typedef MapIterator<key_type, value_type>	iterator;
			typedef ReverseMapIterator<key_type, value_type>	reverse_iterator;
			typedef ConstMapIterator<key_type, value_type>	const_iterator;
			typedef ConstReverseMapIterator<key_type, value_type>	const_reverse_iterator;

		private:
			allocator_type _alloc;
			key_compare _comp;
			node _root;
			size_type _length;
			node new_node(key_type key, mapped_type value, node parent, bool end = false)
			{
				node elem = new BNode<key_type, mapped_type>();
				elem->pair = ft::make_pair(key, value);
				elem->rightNode = 0;
				elem->leftNode = 0;
				elem->parentNode = parent;
				elem->end = end;
				return (elem);
			};
			void init_tree()
			{
				_root = new_node(key_type(), mapped_type(), 0);
				_root->rightNode = new_node(key_type(), mapped_type(), _root, true);
				_length = 0;
			};
			void free_tree(node n)
			{
				if (n->rightNode)
					free_tree(n->rightNode);
				if (n->leftNode)
					free_tree(n->leftNode);
				delete n;
			};
			node insert_node(node n, key_type key, mapped_type value, bool end = false){

			};

		public:
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp)
			{
				init_tree();
			};
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) : _alloc(alloc), _comp(comp)
			{
				init_tree();
				insert(first, last);
			};
			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			};
			~map()
			{
				free_tree(this->_root);
			};
			iterator	begin(void)
			{
				node	n = _root;
				if (!n->leftNode && !n->rightNode)
					return (end());
				if (!n->leftNode && n->rightNode)
					n = n->rightNode;
				while (n->leftNode)
					n = n->leftNode;
				return (const_iterator(n));
			}
			void	erase(iterator first, iterator last)
			{

			};
			void	clear(void)
			{
				erase(begin(), end());
			};
	};
}

#endif