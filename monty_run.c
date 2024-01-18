#include "monty.h"

/* Custom function to read a line from a file */
int read_line(char **lineptr, size_t *n, FILE *stream)
{
    char *buffer;
    size_t capacity = 1024;
    size_t len = 0;

    if (*lineptr == NULL)
    {
        *lineptr = malloc(capacity);
        if (*lineptr == NULL)
            return -1;
        *n = capacity;
    }

    buffer = *lineptr;
    while (fgets(buffer + len, capacity - len, stream))
    {
        len = strlen(*lineptr);
        if ((*lineptr)[len - 1] == '\n')
            return len;

        capacity *= 2;
        *lineptr = realloc(*lineptr, capacity);
        if (*lineptr == NULL)
            return -1;
        buffer = *lineptr;
    }

    return -1;
}

/* Runs the Monty bytecode interpreter */
void monty_run(const char *file_path)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    file = fopen(file_path, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    while (read_line(&line, &len, file) != -1)
    {
        line_number++;
        /* Parse and execute instructions */
    }

    free(line);
    fclose(file);
    free_stack(&stack);
}
