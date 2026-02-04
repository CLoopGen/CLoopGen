#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *hist;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with reversed traversal (backward access pattern)
    for (i = (3 * 256) - 1; i >= 256; i--) {
        hist[i] = 4 * hist[i];
    }
}
