#include "lists.h"

/**
 * add_nodeint - will add new node at the start of a linked list
 * @head: points to the first node in the list
 * @n: data to add in the new node
 *
 * Return: pointer to the new node, will return NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newPtr;

	newPtr = malloc(sizeof(listint_t));
	if (!newPtr)
		return (NULL);

	newPtr->n = n;
	newPtr->next = *head;
	*head = newPtr;

	return (newPtr);
}
