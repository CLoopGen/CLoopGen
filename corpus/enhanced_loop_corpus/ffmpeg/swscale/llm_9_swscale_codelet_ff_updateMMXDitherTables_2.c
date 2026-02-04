#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern  int16_t **tmpY;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (; i < vLumFilterSize; i += step) {
        if (i + 1 < vLumFilterSize) {
            tmpY[i] = tmpY[i - 1];
            tmpY[i + 1] = tmpY[i];
        }
    }
}
