#include "main.h"

/**
 * _printf - is a function that produces an output according to a format.
 * @format: character string
 *
 * Return: integer
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count_char = 0;
	int x;
	char *str;
	char ch;

	va_start(args, format);
	for (x = 0; format[x]; x++)
	{
		if (format[x] == '%')
		{
			switch (format[x] + 1)
			{
				case 'c':
					ch = (char) va_arg(args, int);
					write(1, &c, 1);
					count_char++;
					x++;
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str)
					{
						write(1, str, 1);
						count_char++;
						str++;
					}
					x++;
					break;
				case '%':
					write(1, &format[x], 1);
					count_char++;
					x++;
					break;
				default:
					write(1, &format[x], 1);
					count_char++;
					break;
			}
		}
		else
		{
			write(1, &format[x], 1);
			count_char++;
		}
	}
}
	va_end(args);
	return (count_char);

