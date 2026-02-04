#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t **alpSrcPtr;
extern int neg;
extern int i;
extern  int16_t **tmpA;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (neg > 0) ? neg - 1 : 0;
    for (i = 1; i <= limit; i++) {
        tmpA[i] = alpSrcPtr[neg - i];
        tmpA[i-1] = alpSrcPtr[neg];
    }
}
