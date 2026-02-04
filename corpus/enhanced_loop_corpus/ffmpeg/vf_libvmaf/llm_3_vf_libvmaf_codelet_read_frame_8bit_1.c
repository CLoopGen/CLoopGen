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
    // Variant 2: Strided memory access — process every 2nd element first, then the others
    for (i = 0; i < h; i++) {
        float *p = ptr;
        uint8_t *r = ref_ptr;
        // First pass: even indices (strided access with step 2)
        for (j = 0; j < w; j += 2) {
            p[j] = r[j] * factor;
        }
        // Second pass: odd indices (strided access)
        for (j = 1; j < w; j += 2) {
            p[j] = r[j] * factor;
        }
        ref_ptr += ref_stride / sizeof(*ref_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
