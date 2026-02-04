#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // This changes the access pattern to non-consecutive, reading every second element
    ptrdiff_t offset = 0;
    char *base = start_color;
    for (offset = 0; (base[offset] != '-') && (base[offset] != '\x00') && (offset < 4096); offset += 2) {
        if (base[offset] == '(') {
            for (offset++; (base[offset] != ')') && (base[offset] != '\x00') && (offset < 4096); offset++) {
                // Skip until matching ')'
            }
            if (base[offset] == '\x00' || offset >= 4096)
                break;
        }
    }
    // Adjust p to reflect final position in original pointer logic
    p = base + offset;
}
