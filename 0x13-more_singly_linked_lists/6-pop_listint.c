#include "lists.h"

/**
 * pop_listint - will delete the head node of a linked list
 * @head: points to the first element in the linked list
 *
 * Return: data inside the elements that was deleted,
 * return 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int count;

	if (!head || !*head)
		return (0);

	count = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (count);
}
