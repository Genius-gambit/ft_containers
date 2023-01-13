#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
#include <string>
#include <memory>

#include "enable_if.hpp"
#include "pair.hpp"
#include "v_iterator.hpp"
#include "equal.hpp"

template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T>>
class RBTree
{
public:
	/************************************* Variable Types ****************************************/
	typedef T value_type;
	typedef Alloc alloc_type;
	typedef Compare value_compare;
	typedef typename alloc_type::pointer pointer;
	// typedef typename alloc_type::const_pointer const_pointer;
	typedef typename alloc_type::reference reference;
	typedef typename alloc_type::const_reference const_reference;
	typedef std::size_t size_type;
	typedef node<value_type> treeNode;
	typedef typename Alloc::template rebind<treeNode>::other node_allocator;

private:
	treeNode *NIL;
	treeNode *_root;
	size_type _height;
	alloc_type _alloc;
	Compare _comp;
	node_allocator _node_alloc;

	/************************************* Constructors ****************************************/
public:
	explicit RBTree(const value_compare &comp, const alloc_type &alloc) : NIL(nilNode()),
																		  _height(0), _comp(comp), _alloc(alloc);
	{
		NIL->color = BLACK;
		_root = NIL
	};
};

#endif