#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint64_t *src;
extern uint64_t *dst;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp;
    for (j = 0; j < w; j++) {
        temp = src[-j];
        dst[j] = temp;
    }
}
