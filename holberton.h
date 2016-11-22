#ifndef HOLBERTON
#define HOLBERTON
#include <stdarg.h>
/**
 * struct switchormat - structure
 * @s: format
 * @f: function
 */
typedef struct print_format_t
{
	char *s;
	int(*f)();
}print_format;

int _abs(int i);
void *_calloc(unsigned int nmemb, unsigned int size);
int _putchar(char c);
int _printf(const char *format, ...);
int _printnum(va_list args, char *b);
int _printchar(va_list args, char *b);
int _printstr(va_list args, char *b);

#endif /* ifndef HOLBERTON */
