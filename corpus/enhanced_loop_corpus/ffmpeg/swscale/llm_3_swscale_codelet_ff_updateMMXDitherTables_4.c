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
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (int j = end - 1; j >= 0; j--)
        tmpA[j] = alpSrcPtr[j];
}
