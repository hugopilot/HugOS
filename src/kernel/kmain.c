#include <stdint.h>
#include <stdbool.h>
#include "kmain.h"
#include "vga.h"
#include "term.h"
#include "idt.h"
#include "pic.h"
#include "bthlp.h"
#include "panic.h"

void kmain(void)
{
	setup_idt();
	vga_clear_screen();
	pic_remap();
	term_putstr("Hey! Kernel here.\n\n", 15);
	asm("sti"); //enable hardware interrupts
	print_ok("Hardware interrupts enabled", true);
	term_putstr("Hugo is geweldig, nou goed?\n\n", 2);
	for(;;) asm("hlt"); //halt forever
}
