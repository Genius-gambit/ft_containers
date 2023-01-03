#ifndef V_ITERATOR_HPP
# define V_ITERATOR_HPP

/***************************LIBRARIES********************************/
# include <iterator>
# include <vector>
# include <cstddef>

namespace ft
{
	template < class iterator >
	struct iterator_traits
	{
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
		typedef typename iterator::iterator_category	iterator_category;
	};

	template < class T >
	struct iterator_traits< T* >
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template < class T >
	struct iterator_traits< const T* >
	{
		typedef ptrdiff_t							difference_type;
		typedef T									value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	template < class U >
	class iterator
	{
	public:
		typedef ptrdiff_t						difference_type;
		typedef U								value_type;
		typedef U* pointer;
		typedef const U* const_pointer;
		typedef U& reference;
		typedef std::random_access_iterator_tag	iterator_category;
		typedef iterator<const U>				const_iterator;

		iterator(): _it() {};
		iterator(pointer it): _it(it)
		{
		};
		iterator(const iterator& it): _it(it._it) {}
		~iterator() {}
		iterator	operator=(const iterator& r)
		{
			_it = r.base();
			return *this;
		};
		iterator	operator-(difference_type n) const { return iterator(_it - n); };
		iterator	operator-=(difference_type n) const { return iterator(_it - n); };
		iterator	operator+(difference_type n) const { return iterator(_it + n); };
		iterator	operator+=(difference_type n) const { return iterator(_it + n); };
		reference	operator*() { return (*_it); }
		iterator	operator++() { return ((_it++)); };
		pointer  	operator->() const { return _it; }
		iterator	operator++(int)
		{
			iterator	old;

			old = *this;
			++(_it);
			return(old);
		};
		iterator	operator--() { return ((_it--)); };
		iterator	operator--(int)
		{
			iterator	old;

			old = *this;
			--(_it);
			return(old);
		};
		operator	const_iterator() const { return const_iterator(_it); }
		pointer	base() const { return (_it); }

	private:
		pointer	_it;
	};

	template < class Iter1, class Iter2 >
	typename iterator<Iter1>::difference_type operator - (iterator<Iter1>& first, iterator<Iter2>& second) { return (first.base() - second.base()); }

	template < class Iter1, class Iter2 >
	typename iterator<Iter1>::difference_type operator + (iterator<Iter1>& first, iterator<Iter2>& second) { return (first.base() - second.base()); }

	template <class Iter1, class Iter2>
	bool operator == (const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() == second.base()); }

	template <class Iter1, class Iter2>
	bool operator < (const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() < second.base()); }

	template <class Iter1, class Iter2>
	bool operator != (const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() != second.base()); }

	template <class Iter1, class Iter2>
	bool operator > (const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() > second.base()); }

	template <class Iter1, class Iter2>
	bool operator >= (const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() >= second.base()); }

	template <class Iter1, class Iter2>
	bool operator <= (const iterator<Iter1>& first, const iterator<Iter2>& second) { return (first.base() <= second.base()); }

	template < class U >
	class reverse_iterator
	{
	public:
		typedef ptrdiff_t						difference_type;
		typedef U								value_type;
		typedef U* pointer;
		typedef const U* const_pointer;
		typedef U& reference;
		typedef std::random_access_iterator_tag	iterator_category;

		reverse_iterator(): _it() {};
		reverse_iterator(pointer it): _it(it) {};
		~reverse_iterator() {}
		reference	operator*() { return (*_it); }
		pointer	base() const { return (_it); }
		reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_it + n); };
		reverse_iterator	operator-=(difference_type n) const { return reverse_iterator(_it + n); };
		reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_it - n); };
		reverse_iterator	operator+=(difference_type n) const { return reverse_iterator(_it - n); };
		reverse_iterator	operator++() { return ((_it--)); };
		pointer  	operator->() const { return _it; }
		reverse_iterator	operator++(int)
		{
			reverse_iterator	old;

			old = *this;
			--_it;
			return(old);
		};
		reverse_iterator	operator--() { return ((_it++)); };
		reverse_iterator	operator--(int)
		{
			reverse_iterator	old;

			old = *this;
			++(_it);
			return(old);
		};
	private:
		pointer	_it;
	};

	template < class Iter1, class Iter2 >
	typename reverse_iterator<Iter1>::difference_type operator - (const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() - second.base()); }

	template < class Iter1, class Iter2 >
	typename reverse_iterator<Iter1>::difference_type operator + (const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() - second.base()); }

	template <class Iter1, class Iter2>
	bool operator == (const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() == second.base()); }

	template <class Iter1, class Iter2>
	bool operator < (const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() < second.base()); }

	template <class Iter1, class Iter2>
	bool operator != (const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() != second.base()); }

	template <class Iter1, class Iter2>
	bool operator > (const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() > second.base()); }

	template <class Iter1, class Iter2>
	bool operator >= (const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() >= second.base()); }

	template <class Iter1, class Iter2>
	bool operator <= (const reverse_iterator<Iter1>& first, const reverse_iterator<Iter2>& second) { return (first.base() <= second.base()); }
}

#endif