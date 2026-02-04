#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp = 0;
    for (i = 0; i < 64; i++) {
        temp = dst[i] - 512;
        dst[i] = temp;
    }
}
