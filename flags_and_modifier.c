#include <stdbool.h>

/**
 * is_flag - checks if character is a flag for conversion specifier
 * @c: character to check
 *
 * Return: If flag return true, else false
 */
bool is_flag(char c)
{
	const char flags[] = {'+', ' ', '#', '-', '\0'};
	int i = 0;

	while (flags[i] != '\0')
	{
		if (flags[i] == c)
			return (true);
		i++;
	}

	return (false);
}

/**
 * handle_flags - handles flags
 */
void handle_flags(void)
{
	char fmt = 'c';

	if (is_flag(fmt))
	{
		switch (fmt)
		{
		case '+':
			/**(buffer++) = '+';*/
			break;
		case ' ':
			/**(buffer++) = ' ';*/
			break;
		case '#':
			/*Convert value to alternate form*/
			break;
		case '-':
			/*Left justify*/
			break;
		}
	}
}
