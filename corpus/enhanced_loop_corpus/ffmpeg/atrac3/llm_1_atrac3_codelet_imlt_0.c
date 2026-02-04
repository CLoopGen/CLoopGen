#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        float SWAP_tmp1 = input[255 - i];
        input[255 - i] = input[i];
        input[i] = SWAP_tmp1;

        float SWAP_tmp2 = input[255 - (i + 64)];
        input[255 - (i + 64)] = input[i + 64];
        input[i + 64] = SWAP_tmp2;
    }
}
