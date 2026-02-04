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
    int32_t sum1 = ((int32_t)(((int16_t)(*gainPtr)) * ((int16_t)(cbvec0[j]))));
    int32_t sum2 = ((int32_t)(((int16_t)(*(gainPtr + 1))) * ((int16_t)(cbvec1[j]))));
    int32_t sum3 = ((int32_t)(((int16_t)(*(gainPtr + 2))) * ((int16_t)(cbvec2[j]))));
    a32 = sum1 + sum2 + sum3;
    decvector[j] = (int)((a32 + 8192) >> 14);
    gainPtr += 3;
    gainPtr -= 3;
}
}
