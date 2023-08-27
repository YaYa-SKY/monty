#include "monty.h"

/**
 * print_stack - Prints all elements of the stack
 * @head: Pointer to the stack head
 * @line_number: Line number in the script (not used here)
 * Return: No return value
*/
void print_stack(stack_t **head, unsigned int line_number)
{
    stack_t *current_element;
    (void)line_number;

    current_element = *head;
    if (current_element == NULL)
        return;

    while (current_element)
    {
        printf("Stack element: %d\n", current_element->n);
        current_element = current_element->next;
    }
}
