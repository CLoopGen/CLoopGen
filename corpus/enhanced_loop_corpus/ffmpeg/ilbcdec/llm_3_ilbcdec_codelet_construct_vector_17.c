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
    for (j = 0; j < veclen; j += 2) {
        int idx0 = j;
        int idx1 = (j + 1 < veclen) ? j + 1 : j;
        a32 = ((int32_t)(((int16_t)(*gainPtr++)) * ((int16_t)(cbvec0[idx0]))));
        a32 += ((int32_t)(((int16_t)(*gainPtr++)) * ((int16_t)(cbvec1[idx0]))));
        a32 += ((int32_t)(((int16_t)(*gainPtr)) * ((int16_t)(cbvec2[idx0]))));
        decvector[idx0] = (int)(a32 + 8192) >> 14;

        if (j + 1 < veclen) {
            a32 = ((int32_t)(((int16_t)(*gainPtr++)) * ((int16_t)(cbvec0[idx1]))));
            a32 += ((int32_t)(((int16_t)(*gainPtr++)) * ((int16_t)(cbvec1[idx1]))));
            a32 += ((int32_t)(((int16_t)(*gainPtr)) * ((int16_t)(cbvec2[idx1]))));
            decvector[idx1] = (int)(a32 + 8192) >> 14;
            gainPtr--;
        }
        gainPtr -= 2;
    }
}
