#include "pair.hpp"
#include <string>
#include <iostream>

int main(void)
{
	ft::pair<int, char>	p1(1, 'a');
	ft::pair<int, char>	p2(2, '4');

	p1.getFirst();
	std::cout << ", ";
	p1.getSec();
	std::cout << std::endl;
	p2.getFirst();
	std::cout << ", ";
	p2.getSec();
	std::cout << std::endl;
	return 0;
}