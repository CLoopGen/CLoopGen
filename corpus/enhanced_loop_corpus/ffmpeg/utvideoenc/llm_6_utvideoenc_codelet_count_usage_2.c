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
    uint64_t *local_counts = counts; // Introduce pointer alias to modify data access pattern
    uint8_t *local_src = src;
    int w = width;
    int h = height;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            uint8_t val = local_src[i];
            local_counts[val] += 1; // RAW dependency: load `val` before indexing counts
        }
        local_src += w;
    }
}
