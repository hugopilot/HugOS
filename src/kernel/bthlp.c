#include <stdint.h>
#include <stdbool.h>
#include "bthlp.h"

// Format: [ MSGT ] MSG

void print_ok(const char* str, bool endl){
    // print OK
    term_putstr("[ ", 15);
    term_putstr("OK", 2);
    term_putstr(" ] ", 15);
    term_putstr(str, 15);
    if(endl){
        term_newline();
    }
}
void print_err(const char* str, bool endl){
    // print OK
    term_putstr("[ ", 15);
    term_putstr("ERROR", 4);
    term_putstr(" ] ", 15);
    term_putstr(str, 15);
    if(endl){
        term_newline();
    }
}
void print_warn(const char* str, bool endl){
    // print OK
    term_putstr("[ ", 15);
    term_putstr("WARN", 14);
    term_putstr(" ] ", 15);
    term_putstr(str, 15);
    if(endl){
        term_newline();
    }
}

void sleep(int ms){
	int c, d;
   
   	for (c = 1; c <= 32767; c++)
       		for (d = 1; d <= 32767; d++)
       		{}
       
   	return 0;

}
