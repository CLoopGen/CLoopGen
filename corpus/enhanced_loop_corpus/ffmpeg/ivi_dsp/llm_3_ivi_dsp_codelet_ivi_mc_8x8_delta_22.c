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
    // Variant 2: Strided memory access – traverse columns first, then rows (transpose-like access pattern)
    int16_t *b = buf;
    int16_t *r = ref_buf;
    // Access memory in column-major order: fix column j, iterate over rows i
    for (j = 0; j < 8; j++) {
        int16_t *col_b = b + j;
        int16_t *col_r = r + j;
        for (i = 0; i < 8; i++) {
            col_b[i * dpitch] += (col_r[i * pitch] + col_r[i * pitch + 1]) >> 1;
        }
    }
}
