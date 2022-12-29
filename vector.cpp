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

	trial.insert(trial.begin() + 5, 5, 5);
	for (std::vector<int>::iterator j = trial.begin(); j < trial.end(); j++)
	{
		std::cout << *j << " ";
	}
	std::cout << std::endl;
	return 0;
}