#include "lists.h"

/**
 * free_listint2 - frees memory of a linked list
 * @head: pointer to the memory of  listint_t list to free
 */
void free_listint2(listint_t **head)
{
	listint_t *tempPtr;

	if (head == NULL)
		return;

	while (*head)
	{
		tempPtr = (*head)->next;
		free(*head);
		*head = tempPtr;
	}

	*head = NULL;
}
