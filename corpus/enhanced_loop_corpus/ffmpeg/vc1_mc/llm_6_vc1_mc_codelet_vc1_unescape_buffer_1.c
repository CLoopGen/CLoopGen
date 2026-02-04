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
    uint8_t temp;
    for (dsize = 0; dsize < size; dsize++) {
        temp = src[dsize];
        dst[dsize] = temp;
    }
}
