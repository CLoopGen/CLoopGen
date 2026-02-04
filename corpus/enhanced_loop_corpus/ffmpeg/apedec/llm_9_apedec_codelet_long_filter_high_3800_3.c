#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *buffer;
extern int order;
extern int i;
extern int32_t delay[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < order; i += step) {
        delay[i] = buffer[i];
        if (i + 1 < order) {
            delay[i + 1] = buffer[i + 1]; // Unrolled loop by factor of 2 to reduce trip count and increase per-iteration work
        }
    }
}
