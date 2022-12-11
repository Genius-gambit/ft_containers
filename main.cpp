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
	ft::vector<int>		trial;
	ft::vector<int>		filler(4, 100);
	// ft::vector<int>::iterator	it;
	// filler.insert(50);
	// filler.insert(100);
	// std::cout << filler.end() << std::endl;
	// filler.push_back(45);
	// trial.insert(filler.begin() + 2, 5, 45);
	trial.push_back(45);
	trial.push_back(50);
	std::cout << filler.at(0) << std::endl;
	// trial.print();
	return (0);
}