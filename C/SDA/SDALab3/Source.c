#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *next;
} NodeT;

void push(NodeT** stack, int key)
{
	//TODO add code here
	NodeT * elem = (NodeT*)malloc(sizeof(NodeT));
	if (elem == NULL)
		return;
	elem->key = key;
	elem->next = *stack;
	*stack = elem;

}


int pop(NodeT** stack)
{
	//TODO add code here
	if (*stack != NULL) {
		int x = (*stack)->key;
		NodeT * first = *stack;
		(*stack) = (*stack)->next;
		free(first);

		return x;
	}
	//return the key of the first node and deallocate
	return -1;
}

void print_stack_contents(NodeT* stack)
{
	if(stack == NULL)
		printf("Empty stack!\n");
	while (stack != NULL)
	{
		printf("%d ", stack->key);
		stack = stack->next;
	}
	printf("\n");
}


int main()
{
	NodeT *stack = NULL; //this is the top of the stack (the reference to ...)

	push(&stack, 8);
	push(&stack, 4);
	push(&stack, 3);
	push(&stack, 6);

	print_stack_contents(stack); //6 3 4 8

	pop(&stack);
	pop(&stack);

	print_stack_contents(stack); //4 8

	push(&stack, 2);
	push(&stack, 6);

	print_stack_contents(stack); //6 2 4 8

	pop(&stack);
	pop(&stack);
	pop(&stack);

	print_stack_contents(stack); //8

	pop(&stack);
	pop(&stack);

	print_stack_contents(stack);

	printf("\n");
	system("pause");

	return 0;
}
