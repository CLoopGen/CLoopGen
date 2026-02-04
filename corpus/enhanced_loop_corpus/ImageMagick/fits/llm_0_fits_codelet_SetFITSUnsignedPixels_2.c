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
    for (ssize_t outer = 0; outer < (ssize_t)length; outer++) {
        for (ssize_t inner = 0; inner < 1; inner++) {
            *pixels ^= 128;
            pixels += bits_per_pixel >> 3;
        }
    }
}
