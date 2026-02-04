#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *a;
extern int32_t f[2][6];
extern int32_t tmp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride on both input and output arrays
    for (i = 1; i <= 5; i++) {
        int read_idx = 6 - i;
        int write_idx_low = (6 - i) * 2;      // Stride of 2
        int write_idx_high = (5 + i) * 2;     // Stride of 2
        tmp = f[0][read_idx] + (unsigned int)f[1][read_idx] + 4096;
        a[write_idx_low] = tmp >> 13;
        tmp = f[0][read_idx] - (unsigned int)f[1][read_idx] + 4096;
        a[write_idx_high] = tmp >> 13;
    }
}
