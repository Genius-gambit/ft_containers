# include <vector>
# include <cstdio>
# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>
# include <memory>

/*
*/

int main(void)
{
	std::allocator<int>	allocator;
	int					*arr;

	arr = allocator.allocate(5);
	allocator.construct(arr, 45);
	std::cout << arr[0] << std::endl;
	allocator.destroy(arr);
	allocator.deallocate(arr, 5);
	return 0;
}