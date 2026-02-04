#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t size;
extern unsigned long r;
extern unsigned char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; i < size / 4; i++, r >>= 32) {
        *buf++ = (unsigned char)(r & 255);
        *buf++ = (unsigned char)((r >> 8) & 255);
        *buf++ = (unsigned char)((r >> 16) & 255);
        *buf++ = (unsigned char)((r >> 24) & 255);
    }
    // Handle remainder
    for (size_t rem = size % 4; rem > 0; rem--, r >>= 8) {
        *buf++ = (unsigned char)(r & 255);
    }
}
