#include <string>
#include <map>
#include <iterator>
#include <bits/stdc++.h>
#include "pair.hpp"
#include "utils.hpp"

int main()
{
	std::map<int, char>	_map;
	std::map<int, char>	trial;
	std::map<int, char>::iterator	begin;
	std::map<int, char>::iterator	end;
	std::pair<int, char>	stdPair(4, 'a');
	ft::pair<int, char>		myPair(4, 'a');
	ft::BNode<int, char>	node;

	node.pair = myPair;
	node.leftNode = NULL;
	node.rightNode = NULL;
	myPair.first = 5;
	myPair.second = 'c';
	ft::BNode<int, char>	tmp;
	tmp.pair = myPair;
	std::cout << "Key: " << stdPair.first << ", " << "Value: " << stdPair.second << std::endl;
	std::cout << "Key: " << myPair.first << ", " << "Value: " << myPair.second << std::endl;
	// trial[0] = 'c';
	// trial[1] = 'a';
	// trial[2] = 'd';
	// trial[3] ='m';
	// trial[4] = 'u';
	// begin = trial.begin();
	// end = trial.end();
	// for (std::map<int, char>::iterator it = _map.begin(); it != _map.end(); it++)
	// {
	// 	std::cout << it->first << ": " << it->second << std::endl;
	// }
	return (0);
}