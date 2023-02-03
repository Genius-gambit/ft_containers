# include "vector.hpp"
#include "pair.hpp"
// # include <vector>
// # include <cstdio>
// # include <cstdlib>
// # include <algorithm>
// # include <iostream>
// # include <sstream>
// # include <string>
// # include <iomanip>
// # include <memory>

// template < typename T > class Array
// {
// 	private:
// 		T	*ptr;
// 		int	size;
// 	public:
// 		Array(T arr[], int size);
// 		void	print(void);
// };

// template <typename T>Array<T>::Array(T arr[], int size)
// {
// 	std::allocator<T>	myAlloc;
// 	this->ptr = myAlloc.allocate(size);
// 	this->size = size;
// 	for (int i = 0; i < size; i++)
// 		this->ptr[i] = arr[i];
// }

// template <typename T>void Array<T>::print(void)
// {
// 	for (int i = 0; i < size; i++)
// 	{
// 		if (i == size - 1)
// 			std::cout << this->ptr[i] << ".";
// 		else
// 			std::cout << this->ptr[i] << ", ";
// 	}
// 	std::cout << std::endl;
// }

int main(void)
{
	ft::pair<int, char> _pair1;
	_pair1.first = 100;
	_pair1.sec = 'c';
	std::cout << "Key: " << _pair1.first << ", Value: " << _pair1.sec << std::endl;
	ft::pair<int, char> _pair2(200, 'h');
	std::cout << "Key: " << _pair2.first << ", Value: " << _pair2.sec << std::endl;
	ft::pair<int, char> _pair3;
	_pair3 = ft::make_pair(300, 'a');
	std::cout << "Key: " << _pair3.first << ", Value: " << _pair3.sec << std::endl;
	return 0;
}