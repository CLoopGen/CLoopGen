#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int shift;
extern int x;
extern int y;
extern int size;
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *base = coeffs;
    int combined_step = size * size;
    int temp_shift = shift;
    int temp_offset = offset;
    for (int idx = 0; idx < combined_step; idx++) {
        int16_t current = base[idx];
        int16_t updated = (current + temp_offset) >> temp_shift;
        base[idx] = updated;
    }
    coeffs += combined_step;
}
