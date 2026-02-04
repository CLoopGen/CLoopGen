#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern  int16_t **tmpY;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k = 0;
    for (; k < vLumFilterSize; k++) {
        if (k == 0) continue;
        tmpY[k] = tmpY[k - 1];
    }
}
