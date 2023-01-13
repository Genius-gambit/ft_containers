#ifndef PAIR_HPP
#define PAIR_HPP

#include <utility>

namespace ft
{
	template <typename T1, typename T2>
	class pair
	{
		typedef T1 first_type;
		typedef T2 sec_type;

		first_type	first;
		sec_type	sec;

	public:
		/*********************************************************Constuctors**************************************************************************/
		pair(): first(), sec() {};
		template <typename U, typename V> pair(const pair<U, V>& p): first(p.first), sec(p.sec) {};
		pair(const first_type& a, const sec_type& b): first(a), sec(b) {};
		pair& operator=(const pair& p)
		{
			this->first = p.first;
			this->sec = p.sec;
			return (*this);
		}
		~pair() {};

		template<typename T1, typename T2>
		pair<T1, T2> make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }
		bool operator == (const pair<T1, T2>& l, const pair<T1, T2>& r) { return (l.first == r.first && l.sec == r.sec); }
		bool operator != (const pair<T1, T2>& l, const pair<T1, T2>& r) { return (!(l.first == r.first && l.sec == r.sec)); }
	};
};

#endif