#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int width;
extern int height;
extern uint64_t *counts;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < height && width > 0; j++) { // Add early exit condition based on width
        for (i = 0; i < width; i++) {
            uint8_t val = src[i];
            if (val % 2 == 0) { // Control dependency: only update counts for even values
                counts[val]++;
            }
        }
        src += width;
    }
}
