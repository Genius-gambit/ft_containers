#ifndef MAP_HPP
#define MAP_HPP
#include "vector.hpp"
#include "pair.hpp"
#include "utils.hpp"
#include "map_iterator.hpp"
#include <functional>
#include <limits>

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
			node	insert_node(node n, key_type key, mapped_type value, bool end = false)
			{
				if (n->end)
				{
					if (!n->leftNode)
					{
						n->leftNode = new_node(key, value, n, end);
						return (n->leftNode);
					}
					return (insert_node(n->leftNode, key, value));
				}
				if (key < n->pair.first && !end)
				{
					if (!n->leftNode)
					{
						n->leftNode = new_node(key, value, n, end);
						return(n->leftNode);
					}
					else
						return (insert_node(n->leftNode, key, value));
				}
				else
				{
					if (!n->rightNode)
					{
						n->rightNode = new_node(key, value, n, end);
						return (n->rightNode);
					}
					else
						return (insert_node(n->rightNode, key, value));
				}
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
			node	_find(node n, key_type key) const
			{
				node	tmp;
				if (!n->end && n->pair.first == key && n->parentNode)
					return (n);
				if (n->rightNode)
				{
					if (tmp = _find(n->rightNode, key))
						return (tmp);
				}
				if (n->leftNode)
				{
					if (tmp = _find(n->leftNode, key))
						return (tmp);
				}
				return (0);
			};
			node	_end(void) const { return (_root->rightNode); };

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
			std::pair<iterator, bool> insert(const value_type &value)
			{
				iterator	tmp;

				if ((tmp = find(value.first)) != end())
					return (ft::make_pair(tmp, false));
				++_length;
				return (ft::make_pair(iterator(insert_node(_root, value.first, value.sec)), true));
			}
			iterator	insert(iterator position, const value_type &value)
			{
				iterator	tmp;

				if (tmp = find(value.first) != end())
					return (tmp);
				++_length;
				return (iterator(insert_node(position.node(), value.first, value.sec)));
			}
			~map()
			{
				free_tree(this->_root);
			};
			// [ ITERATORS ]
			iterator	begin(void)
			{
				node	n = _root;
				if (!n->leftNode && !n->rightNode)
					return (end());
				if (!n->leftNode && n->rightNode)
					n = n->rightNode;
				while (n->leftNode)
					n = n->leftNode;
				return (iterator(n));
			};
			const_iterator	begin(void) const
			{
				node	n = _root;
				if (!n->leftNode && !n->rightNode)
					return (end());
				if (!n->leftNode && n->rightNode)
					n = n->rightNode;
				while (n->leftNode)
					n = n->leftNode;
				return (const_iterator(n));
			};
			iterator	end(void) { return (iterator(_end())); };
			const_iterator	end(void) const { return (const_iterator(_end())); };
			reverse_iterator	rbegin(void)
			{
				iterator	i = end();
				i--;
				return (reverse_iterator(i.node()));
			};
			const_reverse_iterator	rbegin(void) const
			{
				iterator	i = end();
				i--;
				return (const_reverse_iterator(i.node()));
			};
			reverse_iterator	rend(void)
			{
				return (reverse_iterator(_root));
			};
			const_reverse_iterator	rend(void) const
			{
				return (const_reverse_iterator(_root));
			};
			// [ CAPACITY ]
			bool	empty(void) const { return (_length == 0); };
			size_type size() const { return (_length); };
			size_type max_size() const { return (std::numeric_limits<size_type>::max() / sizeof(ft::BNode<key_type, mapped_type>)); };

			// [ OBSERVERS ]
			key_compare key_comp() const { return (_comp); };
			value_compare value_comp() const { return (this->value_comp); };
			
			// [ OPERATIONS ]
			iterator find (const key_type& k)
			{
				if (empty())
					return (end());
				node	tmp = _find(_root, k);
				if (tmp)
					return (iterator(tmp));
				return (end());
			};
			const_iterator find (const key_type& k) const
			{
				if (empty())
					return (end());
				node	tmp = _find(_root, k);
				if (tmp)
					return (const_iterator(tmp));
				return (end());
			};
			size_type count (const key_type& k) const
			{
				size_t	c = 0;
				const_iterator	it = begin();

				while (it != end())
				{
					if (it->first == k)
						++c;
					++it;
				}
				return (c);
			};
			iterator lower_bound (const key_type& k)
			{
				iterator	it = begin();
				while (it != end())
				{
					if (this->_comp(it->first, k) <= 0)
						return (it);
					++it;
				}
				return (end());
			};
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator	it = begin();
				while (it != end())
				{
					if (this->_comp(it->first, k) <= 0)
						return (it);
					++it;
				}
				return (end());
			};
			iterator upper_bound (const key_type& k)
			{
				iterator	it = begin();
				while (it != end())
				{
					if (it->first != k && this->_comp(it->first, k) <= 0)
						return (it);
					++it;
				}
				return (end());
			};
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator	it = begin();
				while (it != end())
				{
					if (it->first != k && this->_comp(it->first, k) <= 0)
						return (it);
					++it;
				}
				return (end());
			};
			// void	erase(iterator position)
			// {
			// 	delete
			// }
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