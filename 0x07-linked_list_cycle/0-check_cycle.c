#include "lists.h"

/**
 * check_cycle - check the linked list if is a cycle or not.
 * @list: is the linked list.
 * 
 * Return: Always 0.
 */

int check_cycle(listint_t *list)
{
	listint_t *current, *next;

	if (!list) return (0);

	current = list;
	next = list->next;
	while (current != next)
	{
		current = current->next;
		if (!current) return (0);

		next = next->next;
		if (!next) return (0);

		next = next->next;
		if (!next) return (0);
	}
	return (1);
}
