#include "monty.h"

/* Monty.c: Main program file for the Monty interpreter */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    monty_run(argv[1]);
    return (EXIT_SUCCESS);
}
