#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned int *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pre-computed pointer bounds
    ssize_t limit = i + (32 / 4);
    for (; i < limit; i++) {
        unsigned int val = *p++;
        *q++ = (unsigned char)((val >> 24) & 255);
        *q++ = (unsigned char)((val >> 16) & 255);
        *q++ = (unsigned char)((val >> 8) & 255);
        *q++ = (unsigned char)(val & 255);
    }
}
