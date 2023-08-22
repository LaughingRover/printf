#include "main.h"

/**
 * flush_buffer - prints out the contents of buffer to stdout
 *
 * Description: write any remaining data in the buffer to the output
 * (e.g., a file or standard output) and resetting the buffer to an
 * empty state so that it can be used again
 *
 * @buffer: local buffer
 * @buf_index: buffer index
 *
 * Return: num of printed characters
 */
int flush_buffer(char buffer[], size_t *buf_index)
{
	int num_of_printed_chars = *buf_index;

	if (*buf_index > 0)
	{
		write(STDOUT_FILENO, buffer, *buf_index);
		*buf_index = 0;
	}

	return (num_of_printed_chars);
}

/**
 * write_buffer - Writes to the local buffer
 *
 * @c: character to write to buffer
 * @buffer: local buffer
 * @buf_index: buffer index
 */
void write_buffer(char c, char buffer[], size_t *buf_index)
{
	/*Prevent buffer overflow*/
	if (*buf_index < (BUFSIZE - 1))
	{
		buffer[(*buf_index)++] = c;
	}
	else
	{
		/*Clear buffer and write again*/
		flush_buffer(buffer, buf_index);
		write_buffer(c, buffer, buf_index);
	}
}


/**
 * _memset - reset memory block to specified value
 *
 * @dest: pointer to the memory block to be filled
 * @value: value to set
 * @block_size: number of bytes to set
 *
 * Return: destination pointer
 */
void *_memset(void *dest, int value, size_t block_size)
{
	size_t i = 0;
	unsigned char *p = dest;

	while (i < block_size)
	{
		p[i++] = (unsigned char)value;
	}
	return (dest);
}
