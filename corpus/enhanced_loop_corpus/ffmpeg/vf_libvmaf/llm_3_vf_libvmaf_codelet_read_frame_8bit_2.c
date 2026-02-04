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
    // Variant 2: Strided (non-unit stride) memory access - process every 2nd element first, then the others
    for (i = 0; i < h; i++) {
        float *local_ptr = ptr;
        uint8_t *local_main = main_ptr;

        // First pass: process even indices (strided access with step 2)
        for (j = 0; j < w; j += 2) {
            local_ptr[j] = local_main[j] * factor;
        }
        // Second pass: process odd indices (strided access, offset by 1)
        for (j = 1; j < w; j += 2) {
            local_ptr[j] = local_main[j] * factor;
        }

        main_ptr += main_stride / sizeof(*main_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
