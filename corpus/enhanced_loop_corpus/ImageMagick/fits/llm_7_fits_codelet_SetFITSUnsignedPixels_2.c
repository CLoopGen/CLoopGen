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
    unsigned char temp = 0;
    for (i = 0; i < (ssize_t)length; i++) {
        temp = *pixels;
        temp ^= 128;
        *pixels = temp;
        pixels += bits_per_pixel >> 3;
    }
}
