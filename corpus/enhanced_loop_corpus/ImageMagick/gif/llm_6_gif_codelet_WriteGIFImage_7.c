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
    ssize_t limit = (ssize_t)(one << bits_per_pixel);
    for (; i < limit; i++) {
        unsigned char val = (unsigned char)0;
        *q++ = val;
        *q++ = val;
        *q++ = val;
    }
}
