#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse order)
    // This modifies the original pattern by introducing a stride of 2, processing only even indices.
    for (i = (2 * size - 2) & ~1; i >= 0; i -= 2) {
        if (i + 1 < 2 * size - 1 && i - 1 >= 0) {
            filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
        }
    }
    // Fill skipped indices with a safe fallback (copy central value) to maintain completeness
    for (i = (2 * size - 3) & ~1; i >= 1; i -= 2) {
        filtered_top[i] = (top[i] * 4) >> 2; // Equivalent to top[i], simple copy
    }
}
