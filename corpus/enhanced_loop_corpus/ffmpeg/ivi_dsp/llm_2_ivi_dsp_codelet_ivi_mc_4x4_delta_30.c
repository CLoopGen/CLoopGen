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
    // Variant 1: Consecutive memory access with array reindexing to access elements in row-major order
    int16_t *b = buf;
    int16_t *r = ref_buf;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            b[j] += ((r[j] + r[j + 1]) >> 1);
        }
        b += dpitch;
        r += pitch;
    }
}
