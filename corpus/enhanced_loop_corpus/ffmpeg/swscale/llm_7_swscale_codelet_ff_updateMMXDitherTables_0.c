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
    int16_t *temp_ref = lumSrcPtr[neg];
    for (i = 0; i < neg; i++) {
        tmpY[i] = temp_ref;
    }
}
