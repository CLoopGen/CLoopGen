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
    int32_t prev = 0;
    for (i = 0; i < count; i++) {
        int32_t current = samples[i * stride];
        samples[i * stride] = (current << shft) ^ prev;
        prev = current;
    }
}
