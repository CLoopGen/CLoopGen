#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int ref_stride;
extern  uint16_t *ref_ptr;
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
        float *temp_ptr = ptr;
        uint16_t *temp_ref = ref_ptr;
        int remaining = w;
        
        // Unroll by 2 for consecutive access optimization
        for (j = 0; j < w - 1; j += 2) {
            temp_ptr[j]     = temp_ref[j] * factor;
            temp_ptr[j + 1] = temp_ref[j + 1] * factor;
        }
        
        // Handle odd width
        if (remaining % 2 == 1) {
            temp_ptr[w - 1] = temp_ref[w - 1] * factor;
        }

        ref_ptr += ref_stride / sizeof(*ref_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
