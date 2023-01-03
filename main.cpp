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
	ft::vector<int>	cpy;
	std::vector<int>	vtr;


	// ft::vector<int>::iterator	it;
	// std::vector<int>::iterator	it1;
	// ft::vector<int>::iterator	i1;
	// ft::vector<int>::iterator	i2;
	// ft::vector<int>::reverse_iterator	reve;
	// std::vector<int>::reverse_iterator	rev1;
	// std::vector<int>	trial;

	// std::cout << str.empty() << std::endl;
	str.push_back(20);
	str.push_back(10);
	str.push_back(23);
	str.push_back(45);
	// str.push_back(54);
	// str.push_back(120);
	vtr.push_back(20);
	vtr.push_back(10);
	vtr.push_back(23);
	vtr.push_back(45);
	// str.resize(5, 5);
	// for (unsigned long int i = 0; i < str.size(); i++)
	// 	std::cout << str.at(i) << " ";
	// std::cout << std::endl;
	// // trial.push_back(20);
	// // trial.push_back(10);
	// // trial.push_back(54);
	// // trial.push_back(120);

	// std::cout << str.size() << std::endl;
	// std::cout << std::endl;
	// // trial.push_back(20);
	// // trial.push_back(10);
	// // trial.push_back(54);
	// // trial.push_back(120);
	// it = str.begin();
	// std::cout << *it << std::endl;
	// it++;
	// std::cout << *it << std::endl;
	// std::cout << str.size() << std::endl;
	// it = str.begin();
	// for (unsigned long int i = 0; i < str.size(); i++, it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	// it = str.begin();
	// it += 5;
	// std::cout << *it << std::endl;
	// i1 = str.begin();
	// i2 = str.begin() + 5;

	// if (i1 != i2)
	// 	std::cout << "Yes" << std::endl;
	// else
	// 	std::cout << "No" << std::endl;
	// reve = str.rbegin();
	// rev1 = vtr.rbegin();
	// it = str.end();
	// std::cout << *reve;
	// std::cout << std::endl;
	// std::cout << *rev1;
	// std::cout << std::endl;
	// reve++;
	// std::cout << *reve;
	// std::cout << std::endl;
	// for (reve = str.rbegin(); reve != str.rend(); reve++)
	// {
	// 	std::cout << *reve << " ";
	// }
	// std::cout << std::endl;
	// for (rev1 = vtr.rbegin(); rev1 != vtr.rend(); rev1++)
	// {
	// 	std::cout << *rev1 << " ";
	// }
	// std::cout << std::endl;
	// for (it = str.begin(); it != str.end(); it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	// for (rev1 = vtr.rbegin(); rev1 != vtr.rend(); rev1++)
	// {
	// 	std::cout << *rev1 << " ";
	// }
	// std::cout << std::endl;
	// std::cout << str.size() << "\n";
	ft::vector<int>::iterator it = str.end() - 2;
	std::cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << std::endl;
	str.insert(it, 8, 421);
	for (it = str.begin(); it != str.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << std::endl;
	std::vector<int>::iterator it1 = vtr.end() - 2;
	std::cout << "Size: " << vtr.size() << ", Capacity: " << vtr.capacity() << std::endl;
	vtr.insert(it1, 8, 421);
	for (it1 = vtr.begin(); it1 != vtr.end(); it1++)
	{
		std::cout << *it1 << " ";
	}
	std::cout << std::endl;
	std::cout << "Size: " << vtr.size() << ", Capacity: " << vtr.capacity() << std::endl;
	return 0;
}