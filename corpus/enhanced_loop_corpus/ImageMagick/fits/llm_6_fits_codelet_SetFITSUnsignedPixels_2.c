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
    ssize_t idx = 0;
    unsigned char mask = 128;
    for (i = 0; i < (ssize_t)length; i++) {
        pixels[idx] ^= mask;
        idx += bits_per_pixel >> 3;
    }
}
