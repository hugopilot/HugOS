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
	// boot
	setup_idt();
	vga_clear_screen();
	pic_remap();
	term_putstr("Hey! Kernel here (0.0.0.0.12c)\n\n", 15);

	print_ok("Initial boot success.", true);
	sleep(2500);
	asm("sti"); //enable hardware interrupts
	
	print_ok("Hardware interrupts enabled", true);
	print_warn("Kernel is in pre-alpha.", true);

	print_ok("Boot success!", true);
	sleep(2000);

	vga_clear_screen();
	term_rst();






	term_putstr("Hugo Woesthuis is great\n\n", 2);
	for(;;) asm("hlt"); //halt forever
}
