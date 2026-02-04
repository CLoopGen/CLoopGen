#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 1; depth++) {
        for (i = 0; i < 128; i++) {
            float SWAP_tmp = input[255 - i];
            input[255 - i] = input[i];
            input[i] = SWAP_tmp;
        }
    }
}
