#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **alpSrcPtr;
extern int i;
extern int end;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element forward, then handle remainder)
    int stride = 2;
    int j;
    for (j = 0; j < end; j += stride) {
        if (j < end) tmpA[j] = alpSrcPtr[j];
        if (j + 1 < end) tmpA[j + 1] = alpSrcPtr[j + 1];
    }
}
