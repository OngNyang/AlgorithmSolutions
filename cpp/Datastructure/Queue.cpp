/*
[Data Structure]
queue
FIFO (first in - first out)
*/

#include <iostream>
#include <queue>

void	print_example(void)
{
	std::cout << "FILO" << std::endl;
	std::cout << "	   -- -- -- -- -- " << std::endl;
	std::cout << "	  |3 |1 |4 |  |  |" << " <-- 1" << std::endl;
	std::cout << "	   -- -- -- -- -- " << std::endl;
	
	std::cout << "	   -- -- -- -- -- " << std::endl;
	std::cout << "	  |3 |1 |4 |1 |  |" << std::endl;
	std::cout << "	   -- -- -- -- -- " << std::endl;

	std::cout << "	   -- -- -- -- -- " << std::endl;
	std::cout << "3 <-- " << "|1 |4 |1 |  |  |" << std::endl;
	std::cout << "	   -- -- -- -- -- " << std::endl;
}

template <typename T>

class	Queue
{
	private:
			std::queue<T>	data;
	public:
			bool	empty()
			{
				return (data.empty());
			}
			size_t	size()
			{
				return (data.size());
			}
			void	enqueue(const T& item)
			{
				data.push(item);
			}
			void	dequeue(void)
			{
				if (!empty())
					data.pop();
			}
			T&	front(void)
			{
				return (data.front());
			}


};

int main()
{
	Queue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);

	std::cout << "Size: " << queue.size() << std::endl;
	std::cout << "Front: " << queue.front() << std::endl;

	queue.dequeue();
	std::cout << "Size after dequeue: " << queue.size() << std::endl;
	std::cout << "Front after dequeue: " << queue.front() << std::endl;

	return 0;
}