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
	std::vector<int>	trial(6, 100);
	std::vector<int>::iterator	it;

	trial.push_back(64);
	trial.push_back(54);
	trial.push_back(32);
	trial.push_back(23);
	trial.push_back(12);
	it = trial.begin();
	it += 7;
	std::cout << *it << std::endl;
	// for (it = trial.begin(); it != trial.end(); it++)
	// 	std::cout << *it << std::endl;
	return 0;
}