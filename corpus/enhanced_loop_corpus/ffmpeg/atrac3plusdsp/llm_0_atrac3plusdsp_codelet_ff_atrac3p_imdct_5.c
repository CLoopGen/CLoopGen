#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pIn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 128 / 2; i++) {
        float SWAP_tmp = pIn[128 - 1 - i];
        pIn[128 - 1 - i] = pIn[i];
        pIn[i] = SWAP_tmp;
    }
}
