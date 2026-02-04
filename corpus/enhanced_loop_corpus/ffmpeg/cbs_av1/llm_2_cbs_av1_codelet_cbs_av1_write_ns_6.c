#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t w;
extern uint32_t v;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every second element forward, then fill in reverse)
    // We use a stride of 2 for writing, then handle remaining indices in a second pass.
    int stride = 2;
    int j;
    // First pass: strided access forward
    for (j = 0; j < w - 1; j += stride)
        bits[j] = ((v >> j) & 1) ? '1' : '0';
    // Second pass: fill in the gaps with same logic but offset start
    for (j = 1; j < w - 1; j += stride)
        bits[j] = ((v >> j) & 1) ? '1' : '0';
}
