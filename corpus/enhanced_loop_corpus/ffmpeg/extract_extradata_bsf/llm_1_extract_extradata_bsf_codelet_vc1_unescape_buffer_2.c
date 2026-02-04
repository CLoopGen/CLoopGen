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
    for (int stride = 1; stride <= size; stride <<= 1) {
        for (dsize = stride - 1; dsize < size && dsize < stride; dsize++) {
            *dst++ = *src++;
        }
    }
}
