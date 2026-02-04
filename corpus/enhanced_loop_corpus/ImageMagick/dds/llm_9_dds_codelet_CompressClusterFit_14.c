#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t count;
extern ssize_t bestk;
extern ssize_t i;
extern unsigned char *o;
extern unsigned char unordered[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t step = (bestk & 1) ? 3 : 2;
    for (i = bestk; i < (ssize_t)count; i += step) {
        unordered[o[i] ^ 0x0F] = 1;
        unordered[o[i]] = 1;
    }
}
