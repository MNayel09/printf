#include "main.h"
#include<string.h>
#include <unistd.h>
/**
 * _printf - produces the output according to format
 * @format: a charcter string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (*format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = (char)va_arg(args, int);

						count += write(STDOUT_FILENO, &c, sizeof(char));
					} break;
				case 's':
					{
						char *str = va_arg(args, char*);

						count += write(STDOUT_FILENO, str, strlen(str));
					} break;
				case '%':
					{
						char c = '%';

						count += write(STDOUT_FILENO, &c, sizeof(char));
					} break;
				default:
					{
						char *msg = "Invalid format specifier";

						count += write(STDOUT_FILENO, msg, strlen(msg));
					} break;
			}
		} else
		{
			count += write(STDOUT_FILENO, format, sizeof(char));
		} format++;
	} va_end(args);
	return (count);
}
