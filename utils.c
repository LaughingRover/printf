#include "main.h"

/**
 * flush_buffer - prints out the contents of buffer to stdout
 * @context: data store for formatting options and arguments
 *
 * Description: write any remaining data in the buffer to the output
 * (e.g., a file or standard output) and resetting the buffer to an
 * empty state so that it can be used again
 *
 * Return: num of printed characters
 */
int flush_buffer(FormatContext *context)
{
	int num_of_printed_chars = context->buf_index;

	/**
	 * TODO:
	 * Handle edge case for when buffer limit is exceeded
	 * and flush_buffer is called multiple times. print the
	 * appropraite num_of_printed_chars
	 */

	if ((context->buf_index > 0) && context->buf_index < (BUFSIZE - 1))
	{
		/*Write data to output*/
		write(STDOUT_FILENO, context->buffer, context->buf_index);
		/*Reset buffer*/
		_memset(context->buffer, '0', BUFSIZE);
		context->buf_index = 0;
	}
	return (num_of_printed_chars);
}

/**
 * write_buffer - Writes to the local buffer
 *
 * @c: character to write to buffer
 * @context: data store for formatting options and arguments
 */
void write_buffer(char c, FormatContext *context)
{
	/*Check if buffer is full*/
	if (context->buf_index >= (BUFSIZE - 1))
		flush_buffer(context);

	/*Prevent buffer overflow*/
	if (context->buf_index < (BUFSIZE - 1))
		context->buffer[context->buf_index++] = c;
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

	if (p == NULL)
		return (NULL);

	while (i < block_size)
	{
		p[i++] = (unsigned char)value;
	}
	return (dest);
}

/**
 * initialize_format_context - function to initialize FormatContext struct
 *
 * Return: FormatContext
*/
FormatContext initialize_format_context(void)
{
	FormatContext context;

	context.flags = 0;
	context.width = 0;
	context.precision = 0;
	context.size = 0;
	context.length_modifier = LENGTH_MODIFIER_NONE;
	context.buf_index = 0; /*Initialize buf_index to NULL or a valid pointer*/
	_memset(context.buffer, 0, BUFSIZE); /*Initialize buffer with zeros*/

	return (context);
}

/**
 * reset_flags_modifiers - resets format flags, width, etc.
 * @context: data store for formatting options and arguments
 *
 * Return: void
*/
void reset_flags_modifiers(FormatContext *context)
{
	context->flags = 0;
	context->width = 0;
	context->precision  = 0;
	context->size = 0;
	context->length_modifier = LENGTH_MODIFIER_NONE;
}
