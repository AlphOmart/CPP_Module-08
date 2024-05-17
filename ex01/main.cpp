#include "Span.hpp"

int main()
{
	{
		Span smallSpan(5);
		try {
			smallSpan.addNumber(5);
			smallSpan.addNumber(10);
			smallSpan.addNumber(15);
			smallSpan.addNumber(20);
			smallSpan.addNumber(22);
			//smallSpan.addNumber(23); //will throw an exception
			std::cout << "Shortest Span in given data: " << smallSpan.shortestSpan() << std::endl;
			std::cout << "Longest Span in given data: " << smallSpan.longestSpan() << std::endl;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Span smallSpan(5);
		try {
			smallSpan.addNumber(22);
			std::cout << "Shortest Span in given data: " << smallSpan.shortestSpan() << std::endl;
			std::cout << "Longest Span in given data: " << smallSpan.longestSpan() << std::endl;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		Span	span(5);
		int					arr2[] = {5413, 4453, 23, 45, 135};
		std::vector<int>	vector(arr2, arr2 + sizeof(arr2) / sizeof(*arr2));
		span.addNumbers(vector.begin(), vector.end());
		std::cout << span << std::endl;
	}
		return (0);
}