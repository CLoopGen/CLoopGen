#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t sample;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_sample = sample;
    for (bits = 0; bits < 24 && !(temp_sample & (1 << bits)); bits++) {
        temp_sample = sample; // Reintroduce dependency on sample each iteration (WAW-like pattern)
    }
}
