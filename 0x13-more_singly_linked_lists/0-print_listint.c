#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 *
 */

size_t print_listint(const listint_t *s)
{
	size_t value = 0;

	while (s)
	{
		printf("%d\n", s->n);
		value++;
		s = s->next;
	}

	return (value);
}
