#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node -  inserts a number into a sorted singly linked list.
 * @head: Pointer to pointer of first node of the list.
 * @number: Integer the new node.
 *
 * Return: the address of the new node, or NULL if it failed.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode;
	listint_t *previousNode;
	listint_t *auxNewNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = number;
	newNode->next = NULL;

	auxNewNode = *head;
	previousNode = NULL;
	while (auxNewNode && number >= auxNewNode->n)
	{
		previousNode = auxNewNode;
		auxNewNode = auxNewNode->next;
	}

	newNode->next = auxNewNode;
	previousNode->next = newNode;

	return (newNode);
}
