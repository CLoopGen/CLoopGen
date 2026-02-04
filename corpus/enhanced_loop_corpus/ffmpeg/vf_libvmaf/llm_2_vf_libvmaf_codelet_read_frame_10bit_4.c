#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int main_stride;
extern  uint16_t *main_ptr;
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
        uint16_t *main_row = main_ptr;
        float *p = ptr;
        j = 0;
        // Process two elements at a time for better spatial locality
        for (; j + 1 < w; j += 2) {
            p[j]     = main_row[j] * factor;
            p[j + 1] = main_row[j + 1] * factor;
        }
        // Handle remaining element if width is odd
        if (j < w) {
            p[j] = main_row[j] * factor;
        }
        main_ptr += main_stride / sizeof(*main_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
