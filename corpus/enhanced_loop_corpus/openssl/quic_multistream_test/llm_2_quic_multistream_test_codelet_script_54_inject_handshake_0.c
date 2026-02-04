#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < buf_len; i += 2)
        buf[i] ^= 255;
}
