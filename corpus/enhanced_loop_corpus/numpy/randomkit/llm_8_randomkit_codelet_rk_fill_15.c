#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t size;
extern unsigned long r;
extern unsigned char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; size >= 2; r >>= 16, size -= 2) {
        *(buf++) = (unsigned char)(r & 255);
        *(buf++) = (unsigned char)((r >> 8) & 255);
    }
    if (size == 1) {
        *(buf++) = (unsigned char)(r & 255);
        r >>= 8;
        size--;
    }
}
