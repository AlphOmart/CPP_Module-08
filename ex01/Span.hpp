#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>


class Span
{
 private:
	const size_t		_sizeMax;
	std::vector<int>	_tab;
	Span();

 public:
	Span(unsigned int N);
	Span(const Span& original);
	~Span();

	Span&					operator=(const Span& original);
	const std::vector<int>	getVector()const;
	const size_t&			getSizeMax()const;
	unsigned int			shortestSpan(void);
	unsigned int			longestSpan(void);

	void				addNumber(const int& number);
	template <typename T>
	void				addNumbers(T begin, const T end) {
		while (begin != end) {
			this->addNumber(*begin);
			begin++;
		}
	}
class TooLessNumber : public std::exception
{
public :const char *what() const throw();
};

class TooMuchNumber : public std::exception
{
public :const char *what() const throw();
};
};

std::ostream&	operator<<(std::ostream& os, const Span& span);

#endif