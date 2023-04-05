#include "lists.h"

/**
 * add_nodeint_end - inserts a node at the end of a linked list
 * @head: points to the first element in the list
 * @n: data to add in the new element
 *
 * Return: pointer to the new node, returns NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newPtr;
	listint_t *temp = *head;

	newPtr = malloc(sizeof(listint_t));
	if (!newPtr)
		return (NULL);

	newPtr->n = n;
	newPtr->next = NULL;

	if (*head == NULL)
	{
		*head = newPtr;
		return (newPtr);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = newPtr;

	return (newPtr);
}
