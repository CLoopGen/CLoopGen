#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int is_ac;
extern uint16_t huff_sym[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulating non-sequential access)
    int indices[256];
    for (int j = 0; j < 256; j++) {
        indices[j] = 255 - j; // Reverse order access
    }
    for (i = 0; i < 256; i++) {
        int idx = indices[i];
        huff_sym[idx] = idx + 16 * is_ac;
    }
}
