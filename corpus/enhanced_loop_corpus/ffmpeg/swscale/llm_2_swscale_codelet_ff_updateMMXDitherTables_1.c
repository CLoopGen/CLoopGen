#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **lumSrcPtr;
extern  int16_t **tmpY;
extern int i;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (; i < end; i += 2)
        tmpY[i] = lumSrcPtr[i];
}
