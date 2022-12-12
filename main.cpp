# include "vector.hpp"
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
	ft::vector<int>	str;

	str.push_back(20);
	str.push_back(10);
	str.push_back(54);
	str.push_back(120);

	std::cout << str[0] << " " << str[1] << " " << str[2] << " " << str[3] << std::endl;
	str.clear();
	std::cout << str[0] << " " << str[1] << " " << str[2] << std::endl;
	std::cout << str.size() << std::endl;
	str.push_back(114);
	std::cout << str.size() << std::endl;
	return 0;
}