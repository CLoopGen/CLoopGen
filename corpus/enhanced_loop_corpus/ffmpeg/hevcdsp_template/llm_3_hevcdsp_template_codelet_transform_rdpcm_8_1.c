#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive memory access using pointer arithmetic without indexing
    int16_t *ptr = coeffs;
    for (y = 0; y < size - 1; y++) {
        int16_t *current_row = ptr;
        int16_t *prev_row = ptr - size;
        for (x = 0; x < size; x++) {
            current_row[x] += prev_row[x];
        }
        ptr += size;
    }
    coeffs = ptr;
}
