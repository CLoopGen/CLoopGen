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
    int j;
    for (j = 0; i < end && j < 5; i++, j++) {
        tmpY[i] = lumSrcPtr[i];
        tmpY[i+1] = lumSrcPtr[i+1]; // Unrolled: two assignments per iteration
        j++;
    }
}
