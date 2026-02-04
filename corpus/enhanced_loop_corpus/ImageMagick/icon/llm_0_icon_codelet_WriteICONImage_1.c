#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *q;
extern unsigned short bits_per_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < ((ssize_t)1UL << bits_per_pixel) / 4 + 1; outer++) {
        for (ssize_t inner = 0; inner < 4; inner++) {
            if (i >= (ssize_t)1UL << bits_per_pixel) break;
            *q++ = (unsigned char)0;
            *q++ = (unsigned char)0;
            *q++ = (unsigned char)0;
            *q++ = (unsigned char)0;
            i++;
        }
    }
}
