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
    int16_t *local_coeffs = coeffs;
    int combined_shift = shift + 1;
    int adjusted_offset = offset + 1;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x += 2) {
            if (x + 1 < size) {
                int16_t val1 = (local_coeffs[0] + offset) >> shift;
                int16_t val2 = (local_coeffs[1] + adjusted_offset) >> combined_shift;
                local_coeffs[0] = val1;
                local_coeffs[1] = val2;
                local_coeffs += 2;
            } else {
                *local_coeffs = (*local_coeffs + offset) >> shift;
                local_coeffs++;
            }
        }
    }
    coeffs = local_coeffs;
}
