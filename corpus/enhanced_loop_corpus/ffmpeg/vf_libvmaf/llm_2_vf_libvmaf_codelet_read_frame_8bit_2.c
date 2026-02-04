#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int main_stride;
extern  uint8_t *main_ptr;
extern float *ptr;
extern float factor;
extern int h;
extern int w;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2x
    for (i = 0; i < h; i++) {
        float *local_ptr = ptr;
        uint8_t *local_main = main_ptr;
        j = 0;
        // Unroll by 2 for consecutive access optimization
        for (; j + 1 < w; j += 2) {
            local_ptr[j]   = local_main[j] * factor;
            local_ptr[j+1] = local_main[j+1] * factor;
        }
        // Handle remaining element if width is odd
        if (j < w) {
            local_ptr[j] = local_main[j] * factor;
        }
        main_ptr += main_stride / sizeof(*main_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
