#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < buf_len; i += 2) {
        if (i + 1 < buf_len) {
            buf[i] ^= 255;
            buf[i+1] ^= 255;
        } else {
            buf[i] ^= 255;
        }
    }
}
