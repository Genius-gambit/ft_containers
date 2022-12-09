# include <vector>
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
	std::allocator<int>	alloc;
	int	*array = alloc.allocate(3);

	alloc.construct(array, 5);
	std::cout << array[0] << std::endl;
	return 0;
}