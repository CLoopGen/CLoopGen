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
extern  int16_t *wptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing (unrolled stride simulation)
    int16_t *b = buf;
    int16_t *r = ref_buf;
    int16_t *w = wptr;
    for (i = 0; i < 4; i++) {
        int offset = i * dpitch / sizeof(int16_t); // assuming dpitch in bytes, convert to element count
        int roff = i * pitch / sizeof(int16_t);
        for (j = 0; j < 4; j++) {
            b[offset + j] = (r[roff + j] + w[roff + j]) >> 1;
        }
    }
}
