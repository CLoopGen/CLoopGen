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
    int i;
    for (dsize = 0, i = 0; i < size * 3; i += 3, dsize++) {
        uint8_t temp = src[dsize];
        temp ^= 0xFF;
        temp += 1;
        dst[dsize] = temp;
    }
    dsize = size;
}
