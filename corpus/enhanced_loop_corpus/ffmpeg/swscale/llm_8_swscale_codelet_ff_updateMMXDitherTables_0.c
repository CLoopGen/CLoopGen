#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **lumSrcPtr;
extern  int16_t **tmpY;
extern int neg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < neg && neg > 0; i++) {
        tmpY[i] = lumSrcPtr[neg - 1];
        tmpY[i+1] = lumSrcPtr[neg - 1];
        i++;
    }
}
