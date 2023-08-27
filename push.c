#include "monty.h"

/**
 * push_to_stack - Add a new node to the stack
 * @head: Pointer to the stack head
 * @line_number: Line number in the script
 * Return: No return value
*/
void push_to_stack(stack_t **head, unsigned int line_number)
{
    int value, idx = 0, non_digit_found = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            idx++;
        while (bus.arg[idx] != '\0')
        {
            if (bus.arg[idx] < '0' || bus.arg[idx] > '9')
                non_digit_found = 1;
            idx++;
        }
        if (non_digit_found)
        {
            fprintf(stderr, "L%u: Usage: push integer\n", line_number);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%u: Usage: push integer\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    value = atoi(bus.arg);
    if (bus.lifo == 0)
        add_node_to_stack(head, value);
    else
        add_node_to_queue(head, value);
}
