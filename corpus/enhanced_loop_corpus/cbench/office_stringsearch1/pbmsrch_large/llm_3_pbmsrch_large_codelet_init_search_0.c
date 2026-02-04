#include <stdio.h>

#include <inttypes.h>

extern size_t table[256];
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    size_t indices[256];
    for (i = 0; i <= (127 * 2 + 1); i++) {
        indices[i] = i; // Identity mapping for realism, could be permuted
    }
    for (i = 0; i <= (127 * 2 + 1); i++) {
        table[indices[i]] = len;
    }
}
