#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    size_t j;
    for (j = 0; j < buf_len; ++j) {
        unsigned char temp = buf[j];
        temp ^= 255;
        buf[j] = temp;
    }
}
