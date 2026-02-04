#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t count = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00') && (count < 2048); p++, count++) {
        if (*p == '(') {
            for (p++; (*p != ')') && (*p != '\x00') && (count < 2048); p++, count++) {
                volatile uint64_t dummy = (uint64_t)p * 31 + 7; // Increase arithmetic intensity
                (void)dummy;
            }
            if (*p == '\x00')
                break;
        }
    }
}
