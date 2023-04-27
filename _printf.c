#include "main.h"
#include <unistd.h>
#include <string.h>
/**
 * _vprintf - produces the output count according to format
 * @format: a charcter string
 * @args: the format specifier
 *
 * Return: the number of characters printed
 */
int _vprintf(const char *format, va_list args)
{
	int count = 0;

	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{ format++;
			switch (*format)
			{	case 'c':
					{ char c = (char)va_arg(args, int);

						count += write(STDOUT_FILENO, &c, sizeof(char));
					} break;
				case 's':
					{ char *str = va_arg(args, char*);

					if (str == NULL)
					{ str = "(null)";
						count += write(STDOUT_FILENO, str, strlen(str));
					} else
						count += write(STDOUT_FILENO, str, strlen(str));
					} break;
				case '%':
					{ char c = '%';

						count += write(STDOUT_FILENO, &c, sizeof(char));
					} break;
				default:
					{
					if (*format == '\0')
						return (-1);
					count += write(STDOUT_FILENO, --format, sizeof(char));
					} break;
			}
		} else
		{
			count += write(STDOUT_FILENO, format, sizeof(char));
		} format++;
	} return (count);
}
/**
 * _printf - produces the output according to format
 * @format: a charcter string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);
	count = _vprintf(format, args);
	va_end(args);
	return (count);
}

