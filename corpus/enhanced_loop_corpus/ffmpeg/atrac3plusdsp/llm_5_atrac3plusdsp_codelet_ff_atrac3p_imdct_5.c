#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pIn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int left = i;
        int right = 128 - 1 - i;
        if (left >= right) continue;
        float SWAP_tmp = pIn[right];
        pIn[right] = pIn[left];
        pIn[left] = SWAP_tmp;
    }
}
