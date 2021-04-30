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
	listint_t *auxNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = number;
	newNode->next = NULL;

	auxNode = *head;
	previousNode = NULL;
	while (auxNode && number >= auxNode->n)
	{
		previousNode = auxNode;
		auxNode = auxNode->next;
	}

	newNode->next = auxNode;
	if (previousNode)
	{
		previousNode->next = newNode;
	} else
	{
		*head = newNode;
		return (*head);
	}

	return (newNode);
}
