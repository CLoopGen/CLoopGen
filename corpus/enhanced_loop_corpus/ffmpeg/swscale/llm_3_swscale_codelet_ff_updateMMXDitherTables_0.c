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
    // Variant 2: Strided memory access (access every second element in a mirrored pattern)
    int stride = 2;
    for (i = 0; i < neg; i += stride) {
        if (i + 1 < neg) {
            tmpY[i]     = lumSrcPtr[neg - 1];
            tmpY[i + 1] = lumSrcPtr[neg - 1];
        } else {
            tmpY[i] = lumSrcPtr[neg - 1];
        }
    }
    // Handle any remaining odd index when neg is odd
    if (neg % 2 == 1 && neg > 0) {
        tmpY[neg - 1] = lumSrcPtr[neg - 1];
    }
}
