#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *quant_table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using a pointer to traverse the array symmetrically
    int16_t *base = quant_table;
    for (i = 1; i < 128; i++) {
        *(base + 256 - i) = -*(base + i);
    }
}
