#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t bits_per_pixel;
extern size_t one;
extern ssize_t i;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t step = 3;
    ssize_t limit = (ssize_t)(one << bits_per_pixel);
    size_t offset = 0;
    for (; i < limit; i++) {
        q[offset] = (unsigned char)0;
        q[offset + 1] = (unsigned char)0;
        q[offset + 2] = (unsigned char)0;
        offset += step;
    }
    q += offset;
}
