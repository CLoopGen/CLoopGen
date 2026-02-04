#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int16_t *base = coeffs + y * size;  // Flatten indexing using base pointer
for (y = 0; y < size; y++) {
    int16_t *row = base + y * size;
    for (x = 1; x < size; x++)
        row[x] += row[x - 1];  // Consecutive, direct row-wise access with explicit base
}
}
