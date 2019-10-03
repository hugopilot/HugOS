#ifndef BOOTMSGS_H
#define BOOTMSGS_H

#include "term.h"
#include <stdbool.h>
void print_ok(const char* str, bool endl);
void print_warn(const char* str, bool endl);
void print_err(const char* str, bool endl);

#endif
