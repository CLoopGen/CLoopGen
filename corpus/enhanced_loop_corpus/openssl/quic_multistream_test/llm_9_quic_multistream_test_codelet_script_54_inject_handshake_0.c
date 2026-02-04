#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < buf_len * 2; ++i) {
        size_t index = i % buf_len;
        buf[index] ^= (i % 2 == 0) ? 170 : 85;
    }
}
