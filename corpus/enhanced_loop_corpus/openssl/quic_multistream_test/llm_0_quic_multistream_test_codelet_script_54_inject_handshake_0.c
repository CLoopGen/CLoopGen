#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < buf_len; ++outer) {
        for (size_t inner = 0; inner < 1; ++inner) {
            buf[outer] ^= 255;
        }
    }
}
