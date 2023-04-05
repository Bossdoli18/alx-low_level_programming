#include "lists.h"

/**
 * sum_listint - addition of all the data in a listint_t list
 * @head: starting node in the linked list
 *
 * Return: addition of different elements of the list
 */
int sum_listint(listint_t *head)
{
	int add = 0;
	listint_t *temp = head;

	while (temp)
	{
		add += temp->n;
		temp = temp->next;
	}

	return (add);
}
