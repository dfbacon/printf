#ifndef HOLBERTON
#define HOLBERTON
#include <stdarg.h>

char *string_app(char *base, char *str);
char *_strcat(char *dest, char *src);
char *num_app(char *base, int num);
int _abs(int i);
int itoa(int num, char s[]);
int switchf(const char *format, char *buffer, int i, int n, va_list args);
int _strlen(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
int _putchar(char c);
int _printstring(char *string);
int _printf(const char *format, ...);

#endif /* ifndef HOLBERTON */
