#include "Span.hpp"

Span::Span() : _sizeMax(0)
{
};

Span::Span(unsigned int N) : _sizeMax(N)
{
}

Span::Span(const Span& original) : _sizeMax(original._sizeMax)
{
	*this = original;
}

Span::~Span()
{
}

Span&		Span::operator=(const Span &original)
{
	if (this == &original)
		return (*this);
	this->_tab = original._tab;
	return (*this);
}

const std::vector<int>	Span::getVector()const
{
	return (this->_tab);
}

const size_t&		Span::getSizeMax()const
{
	return (this->_sizeMax);
}

void		Span::addNumber(const int& number)
{
	if (this->_tab.size() < this->_sizeMax)
	{
		this->_tab.push_back(number);
		std::sort(_tab.begin(), _tab.end());
		return ;
	}
	throw (Span::TooMuchNumber());
}

unsigned int		Span::shortestSpan(void)
{
	long int minSpan = UINT_MAX;
	if (_tab.size() > 1)
	{
		for (std::vector<int>::iterator i = _tab.begin(); i + 1 != _tab.end(); ++i)
		{
			if ((*(i+1) - *i) < minSpan)
				minSpan = (*(_tab.begin() + 1) - *(_tab.begin()));
		}
		return (static_cast<unsigned int>(minSpan));
	}
	else
		throw Span::TooLessNumber();
}
unsigned int		Span::longestSpan(void)
{
	long int maxSpan = -1;
	if (_tab.size() > 1)
	{
		maxSpan = static_cast<unsigned int>(*(_tab.end() - 1) - *(_tab.begin()));
		if (maxSpan > 0)
			return maxSpan;
	}
	else
		throw Span::TooLessNumber();
	return (NAN);
}

const char* Span::TooMuchNumber::what() const throw() {
	return "Too much number in this Span !";
}

const char* Span::TooLessNumber::what() const throw() {
	return "Too less number in this Span !";
}

std::ostream&		operator<<(std::ostream& os, const Span& span)
{
	os << "Span: size(" << span.getSizeMax() << "), vector(";

	std::vector<int>	vec = span.getVector();
	std::vector<int>::iterator i = vec.begin();
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end() - 1; ++it)
	{
		os << *it << ", ";
		i = it;
	}
	os << *i;
	os << ')' << std::endl;
	return os;
}