#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples;
extern int count;
extern int stride;
extern int i;
extern int shft;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int double_count = count << 1; // Double the trip count
    for (i = 0; i < double_count; i += 2) {
        if (i < count) {
            samples[i * stride] <<= shft;
        }
        if (i + 1 < count) {
            samples[(i + 1) * stride] <<= shft; // Unrolled body with two operations per iteration
        }
    }
}
