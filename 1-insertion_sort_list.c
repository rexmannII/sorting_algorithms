#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sort.h"


/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order.
 *
 * @list: Pointer to the head of the doubly linked list to be sorted.
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *new, *old;

	if (!list || !(*list) || !(*list)->next)
		return;
	old = *list;
	new = *list;
	old = old->next;
	while (old != NULL)
	{
		new = old;
		old = old->next;
		while (new->prev != NULL && new->n < new->prev->n)
		{
			if (new->next != NULL)
				new->next->prev = new->prev;
			if (new->prev->prev != NULL)
				new->prev->prev->next = new;
			else
				*list = new;
			new->prev->next = new->next;
			new->next = new->prev;
			temp = new->prev->prev;
			new->prev->prev = new;
			new->prev = temp;
			print_list(*list);
		}
	}
}

