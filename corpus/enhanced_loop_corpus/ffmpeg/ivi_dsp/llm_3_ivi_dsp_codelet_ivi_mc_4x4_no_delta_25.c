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
    // Variant 2: Consecutive Linear Access with Pointer Arithmetic
    // Flatten the 2D-like access into a single sequential access pattern
    // by treating the buffer as a linear array of 16 elements accessed consecutively.
    int16_t *b = buf;
    int16_t *r = ref_buf;
    for (j = 0; j < 16; j++) {
        b[j] = r[j];
    }
}
