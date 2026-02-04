#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned short bits_per_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled writes (4 elements at a time)
    ssize_t limit = (ssize_t)1UL << bits_per_pixel;
    for (; i < limit; i++) {
        unsigned char *base = q;
        q += 4;
        base[0] = 0;
        base[1] = 0;
        base[2] = 0;
        base[3] = 0;
    }
}
