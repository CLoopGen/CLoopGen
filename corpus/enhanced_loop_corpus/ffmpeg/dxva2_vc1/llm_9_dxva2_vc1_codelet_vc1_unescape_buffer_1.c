#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (dsize = 0; dsize < size * 2; dsize++) {
        j = dsize >> 1;
        if (j < size) dst[j] = src[j];
    }
}
