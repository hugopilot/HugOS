#ifndef __TERM_H__
#define __TERM_H__
#include <stdint.h>
void term_putchar(char c, uint8_t col);
void term_newline(void);
void term_putstr(const char* str, uint8_t col);
void term_backsp(void);
void term_rst(void);
#endif //__TERM_H__
