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
    for (i = 0; i < 5; i++) {
        int32_t temp1 = lpc_coefs[9][i] * (1 << (6 - shift[9]));
        int32_t temp2 = lpc_coefs[9][i + 5] * (1 << (6 - shift[9]));
        block_coefs[3][i] = -(temp1 >> 6);
        block_coefs[3][i + 5] = -(temp2 >> 6);
    }
}
