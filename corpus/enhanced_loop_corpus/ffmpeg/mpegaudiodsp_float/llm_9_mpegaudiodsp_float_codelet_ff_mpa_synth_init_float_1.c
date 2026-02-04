#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified access pattern and increased loop iterations
    // Flattened indexing with single loop and simpler address calculation, higher iteration count
    int idx = 0;
    for (i = 0; i < 128; i++) {
        idx = 512 + i;
        window[idx] = window[64 * (i / 16) + 32 - (i % 16)];
    }
}
