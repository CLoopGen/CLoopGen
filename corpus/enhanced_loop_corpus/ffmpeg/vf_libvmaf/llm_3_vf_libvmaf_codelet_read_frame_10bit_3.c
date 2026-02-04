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
    // Variant 2: Strided memory access with reversed iteration order (reverse column traversal)
    for (i = 0; i < h; i++) {
        for (j = w - 1; j >= 0; j--) {
            ptr[j] = ref_ptr[j] * factor;
        }
        ref_ptr += ref_stride / sizeof(*ref_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
