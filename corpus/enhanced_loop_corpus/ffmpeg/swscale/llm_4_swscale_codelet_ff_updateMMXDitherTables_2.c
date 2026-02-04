#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int vLumFilterSize;
extern  int16_t **tmpY;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (vLumFilterSize <= 0) return;
    for (int j = 1; j < vLumFilterSize; j++)
        tmpY[j] = tmpY[j - 1];
}
