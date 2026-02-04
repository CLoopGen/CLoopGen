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
    // Variant 2: Strided memory access pattern
    // We reverse the loop order and access memory with a stride corresponding to column-major traversal.
    // This changes access from row-dominant to column-dominant, altering cache behavior.
    int16_t *b = buf;
    int16_t *r = ref_buf;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            b[j + i * dpitch] = (r[j + i * pitch] + r[j + i * pitch + 1]) >> 1;
        }
    }
}
