#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t count;
extern size_t bits_per_pixel;
extern size_t one;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t access_pattern[64];
    for (size_t i = 0; i < 64; i++) {
        access_pattern[i] = (one << i);
    }
    for (bits_per_pixel = 1; (bits_per_pixel < 64) && (access_pattern[bits_per_pixel] < count); bits_per_pixel *= 2)
        ;
}
