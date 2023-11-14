#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

void _putchar(char c);
int _printf(const char *format, ...);
int format_char(char c);
int format_percent();
int format_string(char* s);

#endif
