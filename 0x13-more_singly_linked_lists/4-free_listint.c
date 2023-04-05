#include "lists.h"

/**
 * free_listint - frees memory of a linked list
 * @head: listint_t list memory to free
 */

void free_listint(listint_t *head)
{
	listint_t *tempPtr;

	while (head)
	{
		tempPtr = head->next;
		free(head);
		head = tempPtr;
	}
}
