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
    int32_t local_accum[40];
    for (j = 0; j < veclen; j++) {
        int32_t g0 = (int32_t)(*gainPtr++);
        int32_t g1 = (int32_t)(*gainPtr++);
        int32_t g2 = (int32_t)(*gainPtr);
        local_accum[j] = g0 * cbvec0[j];
        local_accum[j] += g1 * cbvec1[j];
        local_accum[j] += g2 * cbvec2[j];
    }
    for (j = 0; j < veclen; j++) {
        gainPtr--;
        decvector[j] = (int)(local_accum[j] + 8192) >> 14;
    }
}
