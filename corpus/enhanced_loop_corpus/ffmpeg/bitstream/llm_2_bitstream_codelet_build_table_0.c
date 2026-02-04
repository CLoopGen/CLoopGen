#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int table_size;
extern int i;
extern volatile int16_t (*volatile table)[2];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (step by 2)
    for (i = 0; i < table_size; i += 2) {
        if (table[i][1] == 0)
            table[i][0] = -1;
    }
    // Handle odd-sized table if needed by processing last element
    if (table_size > 0 && (table_size % 2) == 1) {
        i = table_size - 1;
        if (table[i][1] == 0)
            table[i][0] = -1;
    }
}
