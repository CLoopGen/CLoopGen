#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (forward skipping)
    // This variant processes every second byte, simulating a strided access pattern.
    // It still checks for null termination and accumulates length based on the high bit.
    size_t i;
    for (i = 0; &content[i] < p + (length ? length : 1) || (p = content, 1); i += 2) {
        p = content + i;
        if (*p == '\x00') break;
        length += (*p & 128) != 0 ? 2 : 1;
        if (*(p + 1) == '\x00') break;
        length += (*(p + 1) & 128) != 0 ? 2 : 1;
    }
}
