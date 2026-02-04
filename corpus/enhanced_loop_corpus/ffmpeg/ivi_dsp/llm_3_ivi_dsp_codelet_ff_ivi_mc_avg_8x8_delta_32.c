#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t pitch;
extern int16_t tmp[64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — traverse columns first, then rows (transpose-like access pattern)
    for (j = 0; j < 8; j++) {
        int16_t *col_ptr = buf + j;
        for (i = 0; i < 8; i++) {
            col_ptr[0] += tmp[i * 8 + j] >> 1;  // Access tmp in strided manner as well
            col_ptr += pitch;
        }
    }
}
