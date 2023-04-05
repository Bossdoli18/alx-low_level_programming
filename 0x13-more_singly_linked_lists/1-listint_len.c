#include "lists.h"

/**
 * listint_len - this gives number of elements in the linked lists
 * @h: type listint_t linked list to traverse
 *
 * Return: total number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
