#ifndef HOLBERTON
#define HOLBERTON
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* string functions */
int _strlen(char *s);
int string_app(char *base, char *str, int location);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

/* math functions */
int num_app(char *base, int num, int location);
int _abs(int i);
int itoa(int num, char s[]);

/* switch function */
int switchf(const char *format, char *buffer, int i, int n, va_list args, int *size);

/* memory functions */
void *_calloc(unsigned int nmemb, unsigned int size);
char *_str_duplicate(char *str);

/* print functions */
int _putchar(char c);
int _printstring(char *string);
int _printf(const char *format, ...);

#endif /* ifndef HOLBERTON */
