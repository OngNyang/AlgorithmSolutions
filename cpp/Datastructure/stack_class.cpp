/*
[data structure]
stack

FIFO (first in, first out)

*/

#include <iostream>
#include <vector>

template <typename T>

class	Stack
{
	private:
			std::vector<T>	data;
	public:
			void	push(const T& item)
			{
				data.push_back(item);
			}
			void	pop(void)
			{
				if (!empty())
					data.pop_back();
			}
			T&	top(void)
			{
				return (data.back());
			}
			size_t	size(void) const
			{
				return (data.size());
			}
			bool	empty(void) const
			{
				return (data.empty());
			}

};


int main() {
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);

	std::cout << "Size: " << stack.size() << std::endl;
	std::cout << "Top: " << stack.top() << std::endl;

	stack.pop();
	std::cout << "Size after pop: " << stack.size() << std::endl;
	std::cout << "Top after pop: " << stack.top() << std::endl;

	return 0;
}