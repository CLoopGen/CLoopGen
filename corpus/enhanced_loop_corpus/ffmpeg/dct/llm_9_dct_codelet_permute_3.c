#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified indexing and halved effective trip count via stride
    for (i = 0; i < 64; i += 8) {
        int reduced_index = i >> 3;
        dst[reduced_index] = src[i];
    }
}
