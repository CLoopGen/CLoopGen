#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access with Linear Indexing
    // Flatten the 2D-like indexing into a fully linear, consecutive access pattern
    // Treat buf and ref_buf as linear arrays and update 16 elements consecutively
    int16_t *b = buf;
    int16_t *r = ref_buf;
    for (i = 0; i < 16; i++) {
        b[i] += r[i];
    }
}
