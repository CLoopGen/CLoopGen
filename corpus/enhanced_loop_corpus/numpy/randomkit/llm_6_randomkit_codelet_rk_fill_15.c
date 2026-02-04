#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t size;
extern unsigned long r;
extern unsigned char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    size_t temp_size = size;
    unsigned long temp_r = r;
    unsigned char *temp_buf = buf;
    for (; temp_size; temp_size--) {
        temp_r >>= 8;
        *(temp_buf++) = (unsigned char)(temp_r & 255);
    }
    r = temp_r;
    buf = temp_buf;
}
