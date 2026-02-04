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
    for (int k = 0; k < 1; k++)
        for (j = 0; j < length; j++)
            *destPtr-- = *sourcePtr++;
}
