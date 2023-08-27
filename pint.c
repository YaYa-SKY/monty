#include "monty.h"

/**
 * print_top - Prints the top element of the stack
 * @head: Pointer to the stack head
 * @line_number: Line number in the script
 * Return: No return value
*/
void print_top(stack_t **head, unsigned int line_number)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: Unable to print, the stack is empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    printf("Top element: %d\n", (*head)->n);
}
