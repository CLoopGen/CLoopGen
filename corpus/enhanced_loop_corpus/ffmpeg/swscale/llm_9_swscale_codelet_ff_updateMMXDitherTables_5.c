#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern int i;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 1; i < vLumFilterSize; i += step) {
        tmpA[i] = tmpA[i - 1];
        if (i + 1 < vLumFilterSize)
            tmpA[i + 1] = tmpA[i];
    }
}
