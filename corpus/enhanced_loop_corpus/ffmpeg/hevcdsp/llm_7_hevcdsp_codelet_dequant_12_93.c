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
    int local_shift = shift;
    int local_offset = offset;
    for (int i = 0; i < combined_step; i++) {
        int16_t val = base[i];
        base[i] = ((val + local_offset) >> local_shift);
    }
}
