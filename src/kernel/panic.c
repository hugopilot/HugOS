#include "bthlp.h"

void panic(const char* msg){
    print_err(msg, false);
    asm("cli");
    asm("hlt");
}