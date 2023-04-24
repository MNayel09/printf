#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: a character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;

	for (; *format != '\0'; format++) {
		if (*format == '%') {
			format++;
			switch (*format) {
				case 'c': {
					int c = va_arg(args, int);
					putchar(c);
					count++;
					break;
 				}
				case 's': {
					char *s = va_arg(args, char *);
					fputs(s, stdout);
					count += strlen(s);
					break;
				}
				case '%': {
					putchar('%');
					count++;
					break;
				}
			}
		} else {
			putchar(*format);
			count++;
		}
	}
	va_end(args);
	return count;
}
