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
    int j;
    for (j = 0; j < end; j++) {
        tmpA[i + j] = alpSrcPtr[i + j];
    }
}
