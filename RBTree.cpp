#include <string>
#include <map>
#include <iterator>
#include <bits/stdc++.h>
#include "pair.hpp"
#include "utils.hpp"

int	length;

typedef struct s_tree
{
	ft::BNode<int, int>	*node;
}							t_tree;

ft::BNode<int, int>	*findUncle(ft::BNode<int, int>	*nephew)
{
	if (nephew->parentNode->parentNode->pair.first < nephew->pair.first)
		return (nephew->parentNode->parentNode->leftNode);
	return (nephew->parentNode->parentNode->rightNode);
}

void	leftRotate(ft::BNode<int, int>	*nodes)
{
	ft::BNode<int, int>	*node = nodes->parentNode;
	node->leftNode = nodes->parentNode->parentNode;
	node->rightNode = nodes;
	node->pair = nodes->parentNode->pair;
	node->parentNode = NULL;
	node->leftNode->_root = false;
	node->leftNode->parentNode = nodes->parentNode;
	node->rightNode->parentNode = nodes->parentNode;
	nodes = node;
	if (nodes->parentNode == NULL)
		nodes->_root = true;
	nodes->leftNode = node->leftNode;
	nodes->rightNode = node->rightNode;
	std::cout << nodes->rightNode->parentNode->_red << std::endl; 
	// std::cout << "Parent: " << node->pair.first << ", Red: " << node->_red << ", Root: " << node->_root << std::endl;
	// std::cout << "Left Sibling: " << node->leftNode->pair.first << ", Red: " << node->leftNode->_red << ", Root: " << node->leftNode->_root << std::endl;
	// std::cout << "Right Sibling: " << node->rightNode->pair.first << ", Red: " << node->rightNode->_red << ", Root: " << node->rightNode->_root << std::endl;
}

void	balancedTree(ft::BNode<int, int>	*nodes, int num)
{
	while (nodes->pair.first != num)
	{
		if (nodes->pair.first > num)
			nodes = nodes->leftNode;
		else
			nodes = nodes->rightNode;
	}
	if (nodes->_red == true && nodes->parentNode->_red == true)
	{
		ft::BNode<int, int>	*uncle = findUncle(nodes);
		if (uncle == NULL)
		{
			if (nodes->parentNode->parentNode->pair.first < nodes->pair.first)
			{
				leftRotate(nodes);
			}
		}
	}
}

void	reColoring(ft::BNode<int, int>	*nodes)
{
	if (length > 1 && nodes->parentNode->_red == true && nodes->parentNode->_root == false)
	{
		if (nodes->leftNode != NULL && nodes->rightNode != NULL)
		{
			if (nodes->_root && (nodes->rightNode->_red || nodes->leftNode->_red))
			{
				nodes->_red = false;
				nodes->leftNode->_red = true;
			}
			// std::cout << "********EntryPoint********\n";
			// std::cout << "Parent: " << nodes->pair.first << ", Red: " << nodes->_red << ", Root: " << nodes->_root << std::endl;
			// std::cout << "Left Sibling: " << nodes->leftNode->pair.first << ", Red: " << nodes->leftNode->_red << ", Root: " << nodes->leftNode->_root << std::endl;
			// std::cout << "Right Sibling: " << nodes->rightNode->pair.first << ", Red: " << nodes->rightNode->_red << ", Root: " << nodes->rightNode->_root << std::endl;
			// std::cout << "********End********\n";
		}
		else if (nodes->parentNode->_red == true && findUncle(nodes) != NULL && findUncle(nodes)->_red == true)
		{
			nodes->parentNode->_red = false;
			findUncle(nodes)->_red = false;
		}
	}
}

void	insertion(ft::BNode<int, int>	*nodes, int num)
{
	while (nodes->_root != true)
	{
		nodes = nodes->parentNode;
	}
	for (int status = 0; status != 1;)
	{
		if (num > nodes->pair.first)
		{
			if (nodes->rightNode == 0)
			{
				ft::BNode<int, int>	*tmp = new ft::BNode<int, int>;
				tmp->pair = ft::pair<int, int>(num, num);
				tmp->_red = true;
				tmp->parentNode = nodes;
				tmp->rightNode = 0;
				tmp->leftNode = 0;
				nodes->rightNode = tmp;
				nodes = nodes->rightNode;
				length++;
				status = 1;
			}
			else
				nodes = nodes->rightNode;
		}
		else if (num < nodes->pair.first)
		{
			if (nodes->leftNode == 0)
			{
				ft::BNode<int, int>	*tmp = new ft::BNode<int, int>;
				tmp->pair = ft::pair<int, int>(num, num);
				tmp->_red = true;
				tmp->parentNode = nodes;
				tmp->rightNode = 0;
				tmp->leftNode = 0;
				nodes->leftNode = tmp;
				nodes = nodes->leftNode;
				length++;
				status = 1;
			}
			else
				nodes = nodes->leftNode;
		}
	}
	balancedTree(nodes, num);
	reColoring(nodes);
	// RBtree->node = nodes;
	// RBtree->node->end = 
	// std::cout << "********EntryPoint********\n";
	// std::cout << "Parent: " << nodes->pair.first << ", Red: " << nodes->_red << ", Root: " << nodes->_root << std::endl;
	// if (nodes->leftNode != NULL)
	// 	std::cout << "Left Sibling: " << nodes->leftNode->pair.first << ", Red: " << nodes->leftNode->_red << ", Root: " << nodes->leftNode->_root << std::endl;
	// if (nodes->leftNode != NULL)
	// 	std::cout << "Right Sibling: " << nodes->rightNode->pair.first << ", Red: " << nodes->rightNode->_red << ", Root: " << nodes->rightNode->_root << std::endl;
	// std::cout << "********End********\n\n";
}

int main()
{
	int	num;
	t_tree	RBTree;
	ft::BNode<int, int>	nodes;
	length = 0;
	nodes.pair = ft::pair<int, int>(371, 371);
	nodes.parentNode = 0;
	nodes.rightNode = 0;
	nodes.leftNode = 0;
	num = 496;
	nodes._root = true;
	nodes._red = false;
	insertion(&nodes, num);
	num = 321;
	insertion(&nodes, num);
	num = 825;
	// exit(0);
	insertion(&nodes, num);
	num = 841;
	insertion(&nodes, num);
	std::cout << "Length: " << length << std::endl;
	// num = 854;
	// insertion(&nodes, num);
	// num = -105;
	// insertion(&nodes, num);
	// std::cout << nodes.pair.first << std::endl;
	// insertion(&nodes, num, &RBTree);
	// for (int status = 0; status != 1;)
	// {
	// 	if (nodes._root == true)
	// 		status = 1;
	// 	nodes = *nodes.parentNode;
	// }
	std::cout << nodes.pair.first << std::endl;
	std::cout << "********Entry Point********\n";
	std::cout << "Parent: " << nodes.pair.first << ", Red: " << nodes._red
	<< ", Root: " << nodes._root << std::endl;
	if (nodes.leftNode != NULL)
		std::cout << "Left Sibling: " << nodes.leftNode->pair.first << ", Red: "
		<< nodes.leftNode->_red << ", Root: " << nodes.leftNode->_root << std::endl;
	if (nodes.rightNode != NULL)
		std::cout << "Right Sibling: " << nodes.rightNode->pair.first << ", Red: "
		<< nodes.rightNode->_red << ", Root: " << nodes.rightNode->_root << std::endl;
	if (nodes.rightNode->rightNode != NULL)
		std::cout << "Right Sibling: " << nodes.rightNode->rightNode->pair.first
		<< ", Red: " << nodes.rightNode->rightNode->_red << ", Root: " << nodes.rightNode->rightNode->_root << std::endl;
	if (nodes.rightNode->rightNode->rightNode != NULL)
		std::cout << "Right Sibling: " << nodes.rightNode->rightNode->rightNode->pair.first
		<< ", Red: " << nodes.rightNode->rightNode->rightNode->_red << ", Root: " << nodes.rightNode->rightNode->rightNode->_root << std::endl;
	std::cout << "********End********\n\n";

	// insertion(&nodes, num);
	// std::cout << nodes.pair.first;
	return (0);
}