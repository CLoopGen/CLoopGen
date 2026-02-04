#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < buf_len; ++i) {
        if ((i & 1) == 0)
            buf[i] ^= 255;
    }
}
