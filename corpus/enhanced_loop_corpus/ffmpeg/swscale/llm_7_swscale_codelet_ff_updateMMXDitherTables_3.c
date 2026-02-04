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
    int16_t *temp_ref = alpSrcPtr[neg];
    for (i = 0; i < neg; i++) {
        tmpA[i] = temp_ref;
    }
}
