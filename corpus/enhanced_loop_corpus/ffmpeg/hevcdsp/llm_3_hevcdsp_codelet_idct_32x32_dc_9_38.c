#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride pattern (stride of 8)
    int stride = 8;
    int idx = 0;
    for (j = 0; j < 4; j++) {  // 32 / 8 = 4 iterations per dimension
        for (i = 0; i < 4; i++) {
            for (int sj = 0; sj < 8; sj++) {
                for (int si = 0; si < 8; si++) {
                    idx = (i*8 + si) + (j*8 + sj) * 32;
                    coeffs[idx] = coeff;
                }
            }
        }
    }
}
