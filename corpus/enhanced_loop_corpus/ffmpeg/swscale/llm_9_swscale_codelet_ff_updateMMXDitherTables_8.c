#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vChrFilterSize;
extern  int16_t **tmpU;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (; i < vChrFilterSize; i += step) {
        if (i + 1 < vChrFilterSize) {
            tmpU[i] = tmpU[i - 1];
            tmpU[i + 1] = tmpU[i];
        }
    }
}
