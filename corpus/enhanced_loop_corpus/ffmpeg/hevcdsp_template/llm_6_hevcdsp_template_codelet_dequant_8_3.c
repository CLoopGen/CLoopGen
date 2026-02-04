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
    int temp_offset = offset;
    int temp_shift = shift;
    int local_size = size;
    for (y = 0; y < local_size; y++) {
        for (x = 0; x < local_size; x++) {
            int16_t val = *local_coeffs;
            val = (val + temp_offset) >> temp_shift;
            *local_coeffs = val;
            local_coeffs++;
        }
    }
}
