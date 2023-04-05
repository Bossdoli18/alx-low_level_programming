#include "lists.h"

/**
 * get_nodeint_at_index - prints the node at a given index in a linked list
 * @head: starting node in the linked list
 * @index: given node to return
 *
 * Return: pointer to the index node, or NULL if no given index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int x = 0;
	listint_t *temp = head;

	while (temp && x < index)
	{
		temp = temp->next;
		x++;
	}

	return (temp ? temp : NULL);
}
