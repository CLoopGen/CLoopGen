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
    for (i = 0; i < count; i += 2) {
        samples[i * stride] <<= shft;
        if (i + 1 < count) {
            samples[(i + 1) * stride] <<= shft;
        }
    }
}
