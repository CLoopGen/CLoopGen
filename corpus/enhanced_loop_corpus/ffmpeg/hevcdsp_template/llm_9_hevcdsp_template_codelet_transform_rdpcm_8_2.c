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
for (y = 0; y < size; y += 2) {
    int16_t *row_start = coeffs + y * size;
    for (x = 1; x < size; x++) {
        row_start[x] = (int16_t)(row_start[x] + row_start[x - 1] / 2);
    }
    if (y + 1 < size) {
        int16_t *next_row = row_start + size;
        for (x = 1; x < size; x++) {
            next_row[x] = (int16_t)(next_row[x] + next_row[x - 1] * 2);
        }
    }
}
}
