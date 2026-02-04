#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern int i;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (vLumFilterSize <= 0) return;
    for (i = 1; i < vLumFilterSize; i++) {
        tmpA[i] = tmpA[i - 1];
    }
}
