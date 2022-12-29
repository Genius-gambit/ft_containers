#include <vector>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <memory>
#include <type_traits>

template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_odd(T i) { return bool(i % 2); }

template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_even(T i) { return !bool(i % 2); }

int main(void)
{
	int i;

	i = 1;
	std::cout << std::boolalpha;
	std::cout << is_odd(i) << std::endl;
	i = 2;
	std::cout << is_even(i) << std::endl;
}