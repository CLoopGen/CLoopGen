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
    for (int j = 0; j < 1; j++)
        for (i = 0; i < 10; i++)
            block_coefs[4 - 1][i] = -lpc_coefs[10 - 1][i] * (1 << (12 - shift[10 - 1]));
}
