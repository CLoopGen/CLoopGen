#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned short bits_per_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t limit = (ssize_t)1UL << bits_per_pixel;
    for (; i < limit; i++) {
        *q = (unsigned char)0;
        *(q + 1) = (unsigned char)0;
        *(q + 2) = (unsigned char)0;
        *(q + 3) = (unsigned char)0;
        q += 4;
    }
}
