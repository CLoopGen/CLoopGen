#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *decvector;
extern int16_t veclen;
extern int16_t cbvec0[40];
extern int16_t cbvec1[40];
extern int16_t cbvec2[40];
extern unsigned int a32;
extern int16_t *gainPtr;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp0, temp1, temp2;
    for (j = 0; j < veclen; j++) {
        temp0 = cbvec0[j];
        temp1 = cbvec1[j];
        temp2 = cbvec2[j];
        a32 = ((int32_t)((*gainPtr) * temp0));
        a32 += ((int32_t)((*(gainPtr + 1)) * temp1));
        a32 += ((int32_t)((*(gainPtr + 2)) * temp2));
        decvector[j] = (int)(a32 + 8192) >> 14;
        gainPtr += 3;
        gainPtr -= 3;
    }
}
