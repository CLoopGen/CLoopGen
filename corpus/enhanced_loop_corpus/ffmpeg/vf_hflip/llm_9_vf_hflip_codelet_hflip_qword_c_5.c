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
    uint64_t temp1, temp2;
    for (j = 0; j < w; j++) {
        temp1 = src[-j] ^ 0xAAAAAAAAAAAAAAAAULL;
        temp2 = src[-j] & 0xFFFFFFFF00000000ULL;
        dst[j] = (temp1 + temp2) >> 1;
    }
}
