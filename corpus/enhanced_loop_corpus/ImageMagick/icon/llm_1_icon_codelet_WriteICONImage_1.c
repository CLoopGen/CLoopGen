#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned short bits_per_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t stride = 0; stride < ((ssize_t)1UL << bits_per_pixel); stride += 8) {
        for (ssize_t j = 0; j < 8 && (i + j) < (ssize_t)1UL << bits_per_pixel; j++) {
            *q++ = (unsigned char)0;
            *q++ = (unsigned char)0;
            *q++ = (unsigned char)0;
            *q++ = (unsigned char)0;
        }
        i += 8;
    }
}
