#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *data[4];
extern int size[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step of 2 (simulated via index scaling)
    // Access pattern changed to non-consecutive: using i*2 for indirect-like indexing within bounds
    int j;
    for (i = 0; (j = i * 2) < 2 && data[j + 1]; i++) {
        size[j] = data[j + 1] - data[j];
    }
}
