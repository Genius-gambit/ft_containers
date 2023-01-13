#include "pair.hpp"
#include <string>
#include <iostream>

int main(void)
{
	ft::pair<int, std::string> p1(1, "Muazzam");
	// ft::pair<int, std::string> p2(1, "Muazzam");
	bool res;
	ft::pair<int, std::string> p2(2, "Akhtar");

	p1.getFirst();
	std::cout << ", ";
	p1.getSec();
	std::cout << std::endl;
	p2.getFirst();
	std::cout << ", ";
	p2.getSec();
	std::cout << std::endl;
	res = p1 == p2;
	std::cout << res << std::endl;
	return 0;
}