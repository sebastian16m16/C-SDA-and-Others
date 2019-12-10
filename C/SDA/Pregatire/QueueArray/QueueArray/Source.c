#include <stdlib.h>
#include <stdio.h>

#define CAPACITY 7

struct queue {
	int array[CAPACITY];
	int nr_elem;
	int head;
	int tail;
};

void enqueue(struct queue* my_queue, int key)
{
	//TODO add code here
	if (my_queue->nr_elem < CAPACITY) {
		my_queue->array[my_queue->tail] = key;
		my_queue->tail++;
		my_queue->nr_elem++;

		if (my_queue->tail == CAPACITY) {
			my_queue->tail = 0;
		}
	}
	else {
		printf("Overflow!\n");
	}

}


int dequeue(struct queue* my_queue)
{
	if (my_queue->nr_elem > 0) {

		int x = my_queue->head;
		my_queue->head++;
		my_queue->nr_elem--;
		if (my_queue->head == CAPACITY)
			my_queue->head = 0;

		return x;

	} else{
		printf("Nothing to dequeue!\n");
	}
	return -1;
}

void print_queue_contents(struct queue my_queue)
{
	//TODO add code here
	int pos = my_queue.head;

	for (int i = 0; i < my_queue.nr_elem; i++) {
		printf("%d ", my_queue.array[pos++]);
		if (pos == CAPACITY)
			pos = 0;
	}
	printf("\n");
}



int main() {

	struct queue a_queue = { {0},0,0,0 };

	enqueue(&a_queue, 1);
	enqueue(&a_queue, 3);
	enqueue(&a_queue, 5);
	enqueue(&a_queue, 2);

	print_queue_contents(a_queue); // 1 3 5 2

	dequeue(&a_queue);
	dequeue(&a_queue);

	print_queue_contents(a_queue); // 5 2

	enqueue(&a_queue, 4);
	enqueue(&a_queue, 9);
	enqueue(&a_queue, 2);
	enqueue(&a_queue, 6);

	print_queue_contents(a_queue); // 5 2 4 9 2 6

	dequeue(&a_queue);

	print_queue_contents(a_queue); // 2 4 9 2 6

	enqueue(&a_queue, 3);
	enqueue(&a_queue, 7);

	print_queue_contents(a_queue); // 2 4 9 2 6 3 7

	enqueue(&a_queue, 9); //overflow

	return 0;
}
