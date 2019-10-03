#ifndef __VGA_H__
#define __VGA_H__

#include <stdint.h>
#include <stddef.h>

#define VGA_HEIGHT 100
#define VGA_WIDTH 160

void vga_print_char(uint64_t offset, uint8_t color, uint8_t character);
void vga_copy_line(size_t line, size_t newpos);
void vga_clear_line(size_t line);
void vga_clear_screen(void);

#endif //__VGA_H__
