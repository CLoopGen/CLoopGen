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
    for (j = 0; j < veclen; j++) {
        int idx = j;
        a32 = ((int32_t)(((int16_t)(gainPtr[0])) * ((int16_t)(cbvec0[idx]))));
        a32 += ((int32_t)(((int16_t)(gainPtr[1])) * ((int16_t)(cbvec1[idx]))));
        a32 += ((int32_t)(((int16_t)(gainPtr[2])) * ((int16_t)(cbvec2[idx]))));
        gainPtr += 3;
        decvector[idx] = (int)(a32 + 8192) >> 14;
        gainPtr -= 2;
    }
}
