#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int shift;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *base = coeffs;
    int total_elements = size * size;
    int shift_val = -shift;
    for (int i = 0; i < total_elements; i++) {
        int16_t shifted = (int16_t)((uint16_t)base[i] << shift_val);
        base[i] = shifted;
    }
    coeffs = base + total_elements;
}
