#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t count;
extern size_t bits_per_pixel;
extern size_t one;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (bits_per_pixel = 1; (bits_per_pixel < 64) && ((one << bits_per_pixel) + (one >> (bits_per_pixel / 2))) < count; bits_per_pixel *= 2)
        ;
}
