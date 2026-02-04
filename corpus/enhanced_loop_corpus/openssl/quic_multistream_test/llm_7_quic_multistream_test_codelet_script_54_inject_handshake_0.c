#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern size_t buf_len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    size_t step = 2;
    size_t limit = buf_len - (buf_len % step);
    size_t j;
    for (j = 0; j < limit; j += step) {
        buf[j] ^= 255;
        if (j + 1 < buf_len) {
            buf[j + 1] ^= 255;
        }
    }
    for (; j < buf_len; ++j) {
        buf[j] ^= 255;
    }
}
