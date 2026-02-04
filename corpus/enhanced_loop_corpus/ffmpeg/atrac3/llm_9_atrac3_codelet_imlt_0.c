#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i += 2) {
        float SWAP_tmp1 = input[255 - i];
        input[255 - i] = input[i];
        input[i] = SWAP_tmp1;

        if (i + 1 < 128) {
            float SWAP_tmp2 = input[254 - i];
            input[254 - i] = input[i + 1];
            input[i + 1] = SWAP_tmp2;
        }
    }
}
