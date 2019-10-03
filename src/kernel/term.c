
#include "term.h"
#include "vga.h"

struct term_state {
	size_t col;
	size_t row;
	uint8_t color;
};

//Terminal state variable. This is modified by the terminal functions.
struct term_state state = {0, 0, 0x0f};

void term_putchar(char c, uint8_t col) {
	state.color = col;
	if (c == '\n') {
		term_newline();
	}else if(c == '\b'){
		term_backsp();
	} else {
		size_t offset = (state.row * VGA_WIDTH) + state.col;
		vga_print_char(offset, state.color, (uint8_t)c);
		if (++state.col >= VGA_WIDTH)
			term_newline();
	}
}

void term_newline(void) {
	state.col = 0;
	if (++state.row >= VGA_HEIGHT) {
		for (size_t i = 1; i <= VGA_HEIGHT; i++)
			vga_copy_line(i, i-1);
		state.row = VGA_HEIGHT - 1;
		vga_clear_line(VGA_HEIGHT - 1);
	}
}
void term_backsp(void){
	if(state.col > 0){	
		--state.col;
		size_t offset = (state.row * VGA_WIDTH) + state.col;
		vga_print_char(offset, 0, 0);
	}
}
void term_putstr(const char* str, uint8_t col) {
	while(*str != '\0')
		term_putchar(*(str++), col);
}
void term_rst(void){
	state.col = 0;
	state.row = 0;
	state.color = 0;
}
