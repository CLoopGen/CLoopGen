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
    for (; i < end; i++) {
        if (lumSrcPtr[i] != NULL)
            tmpY[i] = lumSrcPtr[i];
        else
            tmpY[i] = NULL;
    }
}
