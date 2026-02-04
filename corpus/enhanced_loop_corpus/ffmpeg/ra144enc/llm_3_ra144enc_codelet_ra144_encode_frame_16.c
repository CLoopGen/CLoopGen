#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t lpc_coefs[10][32];
extern int shift[10];
extern int16_t block_coefs[4][10];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration order (still using for loop)
    for (i = 9; i >= 0; i -= 1) {
        block_coefs[3][9 - i] = -lpc_coefs[9][i] * (1 << (12 - shift[9]));
    }
}
