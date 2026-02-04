#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i <= (127 * 2 + 1); i += 2) {
        table[i] = len;
    }
    // Fill in odd indices in a second pass to maintain full coverage
    for (i = 1; i <= (127 * 2 + 1); i += 2) {
        table[i] = len;
    }
}
