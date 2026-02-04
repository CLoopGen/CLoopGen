#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t size;
extern unsigned long r;
extern unsigned char *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_size = size;
    unsigned long temp_r = r;
    unsigned char *temp_buf = buf;
    for (; temp_size > 0; temp_size--) {
        if (temp_r == 0) {
            *(temp_buf++) = 0;
        } else {
            *(temp_buf++) = (unsigned char)(temp_r & 255);
            temp_r >>= 8;
        }
    }
    size = 0;
    buf = temp_buf;
}
