#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access
    for (i = buf_len - 1; i != (size_t)-1; --i)
        buf[i] ^= 255;
}
