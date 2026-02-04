#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t size;
extern unsigned long r;
extern unsigned char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (; size; size--) {
        unsigned char val = (unsigned char)(r & 255);
        r >>= 8;
        *(buf++) = val;
    }
}
