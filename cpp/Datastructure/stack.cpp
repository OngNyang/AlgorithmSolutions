/*
[data structure]
stack

FIFO (first in, first out)

*/

#include <iostream>

typedef struct	s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}				stack;

typedef struct	s_node
{
	int	data;
	struct s_node	*prev;
	struct s_node	*next;
}				node;

stack	*new_stack(void)
{
	stack	*st = new stack;

	st->head = nullptr;
	st->tail = nullptr;
	return (st);
}

node	*new_node(int num)
{
	node	*nn = new node;
	nn->data = num;
	nn->prev = nullptr;
	nn->next = nullptr;
	return (nn);
}

void	push(stack *st, node *nd)
{
	if (st->tail == nullptr)
	{
		st->head = nd;
		st->tail = nd;
	}
	else
	{
		node	*temp = st->tail;
		temp->next = nd;
		nd->prev = temp;
		st->tail = nd;
	}
}

node	*pop(stack *st)
{
	if (st->tail == nullptr)
	{
		return (nullptr);
	}
	node	*temp = st->tail;
	node	*new_tail = temp->prev;

	new_tail->next = nullptr;
	st->tail = new_tail;
	temp->prev = nullptr;
	return (temp);
}

void	print_example(void)
{
	std::cout << "FILO" << std::endl;
	std::cout << " -- -- -- -- -- " << std::endl;
	std::cout << "|3 |1 |4 |  |  |" << " <-- 1" << std::endl;
	std::cout << " -- -- -- -- -- " << std::endl;
	
	std::cout << " -- -- -- -- -- " << std::endl;
	std::cout << "|3 |1 |4 |1 |  |" << std::endl;
	std::cout << " -- -- -- -- -- " << std::endl;

	std::cout << " -- -- -- -- -- " << std::endl;
	std::cout << "|3 |1 |4 |  |  |" << " --> 1" << std::endl;
	std::cout << " -- -- -- -- -- " << std::endl;
}

int	main(void)
{
	print_example();

	stack	*st = new_stack();
	node	*nd3 = new_node(3);
	push(st, nd3);
	push(st, new_node(1));
	push(st, new_node(4));
	push(st, new_node(1));
	
	
	node *nd = pop(st);
	std:: cout << nd->data << std::endl;


	node *temp = st->head;
	while (temp != nullptr)
	{
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}