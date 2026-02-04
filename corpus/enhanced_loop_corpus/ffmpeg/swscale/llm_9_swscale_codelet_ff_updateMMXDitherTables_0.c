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
    int step = 2;
    for (i = 0; i < neg; i += step) {
        tmpY[i] = lumSrcPtr[neg];
        if (i + 1 < neg) {
            tmpY[i + 1] = lumSrcPtr[neg];
        }
    }
}
