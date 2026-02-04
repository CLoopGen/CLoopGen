#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2 (forward striding)
    // Access every second element, still checking for null terminator at each accessed position
    size_t i;
    for (i = 0; content[i] != '\x00'; i += 2) {
        unsigned char val = content[i];
        length += (val & 128) ? 2 : 1;
        // Ensure we don't skip past the null without checking next if needed
        if (i + 1 < SIZE_MAX && content[i + 1] == '\x00') break;
    }
}
