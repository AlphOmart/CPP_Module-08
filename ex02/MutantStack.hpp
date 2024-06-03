#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>

template <typename T, typename Deque = std::deque<T> >
class MutantStack : public std::stack<T> {
public:
	typedef typename Deque::iterator				iterator;
	typedef typename Deque::const_iterator			const_iterator;
	typedef typename Deque::reverse_iterator		rev_iterator;
	typedef typename Deque::const_reverse_iterator	const_rev_iterator;


	iterator		begin() throw() {
		return this->c.begin();
	}

	const_iterator	begin() const throw() {
		return this->c.begin();
	}

	iterator		end() throw() {
		return this->c.end();
	}

	const_iterator	end() const throw() {
		return this->c.end();
	}


	rev_iterator		rbegin() throw() {
		return this->c.rbegin();
	}

	const_rev_iterator	rbegin() const throw() {
		return this->c.rbegin();
	}

	rev_iterator		rend() throw() {
		return this->c.rend();
	}

	const_rev_iterator	rend() const throw() {
		return this->c.rend();
	}
};

#endif