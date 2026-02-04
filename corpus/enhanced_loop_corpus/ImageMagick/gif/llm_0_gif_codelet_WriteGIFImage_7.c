#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t bits_per_pixel;
extern size_t one;
extern ssize_t i;
extern unsigned char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < (ssize_t)(one >> (bits_per_pixel - 1)); outer++) {
        for (ssize_t inner = 0; inner < (ssize_t)(one << (bits_per_pixel - 1)); inner++) {
            *q++ = (unsigned char)0;
            *q++ = (unsigned char)0;
            *q++ = (unsigned char)0;
        }
    }
}
