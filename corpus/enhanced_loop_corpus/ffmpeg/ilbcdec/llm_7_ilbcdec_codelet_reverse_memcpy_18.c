#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int length;
extern int16_t *destPtr;
extern int16_t *sourcePtr;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp;
    for (j = 0; j < length; j++) {
        temp = *sourcePtr++;
        *destPtr-- = temp;
    }
}
