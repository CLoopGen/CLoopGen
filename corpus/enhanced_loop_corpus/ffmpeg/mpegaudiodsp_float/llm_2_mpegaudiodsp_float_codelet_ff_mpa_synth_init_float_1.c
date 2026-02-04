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
    // Variant 1: Consecutive memory access with precomputed base indices
    // Instead of scattering accesses across window, reorganize to write in consecutive order
    // by swapping loop order and adjusting indexing accordingly.
    for (j = 0; j < 16; j++)
        for (i = 0; i < 8; i++)
            window[512 + 16 * i + j] = window[64 * i + 32 - j];
}
