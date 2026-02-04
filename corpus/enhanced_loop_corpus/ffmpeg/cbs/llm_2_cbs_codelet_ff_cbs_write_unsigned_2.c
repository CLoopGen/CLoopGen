#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t value;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal using pointer arithmetic
    char *ptr = bits;
    for (i = 0; i < width; i++) {
        *ptr++ = (value >> (width - i - 1)) & 1 ? '1' : '0';
    }
}
