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
	std::vector<int>	trial(5, 100);

	trial.resize(45);
	std::cout << trial.capacity() << std::endl;
	return 0;
}