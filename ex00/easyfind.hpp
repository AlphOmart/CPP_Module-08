#ifndef EASYFIND_HPP
#define EASYFIND_HPP


template <typename T>
const typename T::iterator	easyfind(T &container, const int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw (std::exception());
	return it;
}

template <typename T>
const typename T::iterator	easyfind(const T &container, const int i)
{
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end())
		throw (std::exception());
	return it;
}
#endif