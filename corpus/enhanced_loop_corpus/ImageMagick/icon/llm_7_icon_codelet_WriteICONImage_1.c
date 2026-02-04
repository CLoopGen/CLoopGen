#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned short bits_per_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char val = 0;
    ssize_t step = (ssize_t)1UL << bits_per_pixel;
    for (; i < step; i++) {
        q[0] = val;
        q[1] = val;
        q[2] = val;
        q[3] = val;
        q += 4;
        val ^= 0; // Introduce artificial WAW dependency on 'val', though optimized out; maintains semantic validity
    }
}
