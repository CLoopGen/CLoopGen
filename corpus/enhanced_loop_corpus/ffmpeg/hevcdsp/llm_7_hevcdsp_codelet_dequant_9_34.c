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
    int offset = 0;
    int total_elements = size * size;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            int idx = offset + x;
            base[idx] = (int16_t)((uint16_t)base[idx] << -shift);
        }
        offset += size;
    }
    coeffs += total_elements;
}
