#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dstU;
extern int16_t *dstV;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)alloca(width * sizeof(int));
    for (int j = 0; j < width; j++) {
        indices[j] = width - 1 - j; // reverse access pattern
    }
    for (i = 0; i < width; i++) {
        int idx = indices[i];
        dstU[idx] = (dstU[idx] * 1799 + 4081085) >> 11;
        dstV[idx] = (dstV[idx] * 1799 + 4081085) >> 11;
    }
}
