#include <vector>
#include <iterator>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>
# include <memory>

int main(void)
{
	int	arr[] = { 7608, 2330, -3181, 5877, -9721, -2199, -382, 6752, -1782, -5452, 7971, 4918, 5906, -5280, -4210 };
	std::vector<int>			vec;
	std::vector<int>::iterator	itr;

	for (int i = 0; i < 15; i++)
		vec.push_back(arr[i]);
	for (itr = vec.begin(); itr < vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}