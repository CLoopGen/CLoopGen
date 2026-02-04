#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (buf_len > 0) {
        for (i = 0; i < buf_len; ++i)
            buf[i] ^= 255;
    }
}
