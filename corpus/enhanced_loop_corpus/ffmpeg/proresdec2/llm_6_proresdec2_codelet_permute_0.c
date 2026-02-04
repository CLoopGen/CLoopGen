#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern  uint8_t permutation[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[64];
    for (i = 0; i < 64; i++)
        temp[i] = src[i];
    for (i = 0; i < 64; i++)
        dst[i] = permutation[temp[i]];
}
