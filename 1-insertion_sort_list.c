#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm
 *
 * @list: Pointer to a pointer to the head of the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *back;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		back = current->prev;
		while (back != NULL && back->n > current->n)
		{
			swap_nodes(&back, &current, list);
			print_list(*list);
			back = current->prev;
		}
		current = current->next;
	}
}

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 *
 * @back: Pointer to a pointer to the back node
 * @current: Pointer to a pointer to the current node
 * @list: Pointer to a pointer to the head of the list
 */
void swap_nodes(listint_t **back, listint_t **current, listint_t **list)
{
	listint_t *tmp = *back;

	/* Adjust the links */
	(*current)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *current;
	else
		*list = *current;
	tmp->next = (*current)->next;
	if ((*current)->next != NULL)
		(*current)->next->prev = tmp;
	(*current)->next = tmp;
	tmp->prev = *current;
	*back = *current;
	*current = tmp;
}

