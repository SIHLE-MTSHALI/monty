#include "monty.h"

/**
 * check_if_string_is_int - checks if a string is a valid integer
 * @str: string to check
 *
 * Description: This function checks each character of the string to determine
 * if it is a valid integer. It handles optional '+' or '-' signs at the
 * beginning and ensures the rest of the characters are digits.
 * Return: 1 if string is a valid integer, 0 otherwise
 */
int check_if_string_is_int(char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}

	return (1);
}
