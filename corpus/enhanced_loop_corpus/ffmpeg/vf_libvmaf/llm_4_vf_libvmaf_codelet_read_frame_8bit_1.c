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
    for (i = 0; i < h; i++) {
        if (factor == 0.0f) {
            for (j = 0; j < w; j++) {
                ptr[j] = 0.0f;
            }
        } else {
            for (j = 0; j < w; j++) {
                ptr[j] = ref_ptr[j] * factor;
            }
        }
        ref_ptr += ref_stride / sizeof(*ref_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
