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
	char * (*f)();
}print_format;

int _abs(int i);
void *_calloc(unsigned int nmemb, unsigned int size);
int _putchar(char c);
int _printf(const char *format, ...);
char *_printnum(char *base, va_list args);
char *_printchar(char *base, va_list args);
char *_printstr(char *base, va_list args);
char *_strcat(char *dest, char *src);
int itoa(int num, char s[]);
int _printstring(char *string);

#endif /* ifndef HOLBERTON */
