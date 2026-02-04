#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int table_size;
extern int i;
extern volatile int16_t (*volatile table)[2];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (process every 2nd element in two passes)
    // First pass: even indices
    for (i = 0; i < table_size; i += 2) {
        if (table[i][1] == 0)
            table[i][0] = -1;
    }
    // Second pass: odd indices
    for (i = 1; i < table_size; i += 2) {
        if (table[i][1] == 0)
            table[i][0] = -1;
    }
}
