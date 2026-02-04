#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern  size_t bits_per_pixel;
extern unsigned char *pixels;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)length; i++) {
        if ((i & 1) == 0) {
            *pixels ^= 128;
        }
        pixels += bits_per_pixel >> 3;
    }
}
