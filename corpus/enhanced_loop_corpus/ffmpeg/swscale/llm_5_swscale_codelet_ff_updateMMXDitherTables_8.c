#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vChrFilterSize;
extern  int16_t **tmpU;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < vChrFilterSize; i++) {
        if (i == 0) continue;
        tmpU[i] = tmpU[i - 1];
    }
}
