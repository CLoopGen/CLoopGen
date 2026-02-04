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
    int local_shift = shift;
    int local_offset = offset;
    int local_size = size;
    int idx = 0;
    for (y = 0; y < local_size; y++) {
        for (x = 0; x < local_size; x++) {
            *(local_coeffs + idx) = (*(local_coeffs + idx) + local_offset) >> local_shift;
            idx++;
        }
    }
}
