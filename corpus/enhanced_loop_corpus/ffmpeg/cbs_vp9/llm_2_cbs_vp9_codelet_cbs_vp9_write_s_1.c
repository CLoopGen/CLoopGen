#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t magnitude;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse iteration (backward traversal)
    for (i = width - 1; i >= 0; i--) {
        bits[i] = (magnitude >> (width - i - 1)) & 1 ? '1' : '0';
    }
}
