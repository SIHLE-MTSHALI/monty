#include "monty.h"

/* Main entry point of the Monty bytecode interpreter */
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
