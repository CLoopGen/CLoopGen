#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int ref_stride;
extern  uint8_t *ref_ptr;
extern float *ptr;
extern float factor;
extern int h;
extern int w;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    for (i = 0; i < h; i++) {
        float *p = ptr;
        uint8_t *r = ref_ptr;
        j = 0;
        // Unroll by 2 for consecutive access optimization
        for (; j + 1 < w; j += 2) {
            p[j]     = r[j] * factor;
            p[j + 1] = r[j + 1] * factor;
        }
        // Handle remaining element if width is odd
        if (j < w) {
            p[j] = r[j] * factor;
        }
        ref_ptr += ref_stride / sizeof(*ref_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
