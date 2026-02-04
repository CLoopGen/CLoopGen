#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t v;
extern int zeroes;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward iteration using pointer arithmetic
    char* ptr = bits + i;
    for (int j = 0; j < zeroes; j++) {
        *ptr++ = ((v >> (zeroes - j - 1)) & 1) ? '1' : '0';
    }
    i += zeroes;  // Update index after bulk write
}
