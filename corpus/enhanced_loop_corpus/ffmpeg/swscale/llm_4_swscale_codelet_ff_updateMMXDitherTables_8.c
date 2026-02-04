#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vChrFilterSize;
extern  int16_t **tmpU;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (vChrFilterSize <= 0) return;
    for (int j = 1; j < vChrFilterSize; j++) {
        tmpU[j] = tmpU[j - 1];
    }
}
