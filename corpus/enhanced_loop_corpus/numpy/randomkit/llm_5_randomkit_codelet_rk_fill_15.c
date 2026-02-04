#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t size;
extern unsigned long r;
extern unsigned char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; size > 0 && r != 0; size--, r >>= 8) {
        unsigned char val = (unsigned char)(r & 255);
        *(buf++) = val;
    }
    while (size > 0) {
        *(buf++) = 0;
        size--;
    }
}
