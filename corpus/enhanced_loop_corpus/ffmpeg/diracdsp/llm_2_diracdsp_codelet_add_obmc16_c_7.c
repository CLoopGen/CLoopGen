#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint8_t *src;
extern  uint8_t *obmc_weight;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *d = dst;
    uint8_t *s = src;
    uint8_t *w = obmc_weight;
    for (x = 0; x < 16; x += 2) {
        *d++ += *s++ * *w++;
        *d++ += *s++ * *w++;
    }
}
