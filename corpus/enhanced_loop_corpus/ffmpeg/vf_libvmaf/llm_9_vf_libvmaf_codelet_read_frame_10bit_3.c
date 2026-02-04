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
    int i, j;
    float local_factor = factor * 0.5f;
    for (i = 0; i < h; i += 2) {
        if (i + 1 < h) {
            for (j = 0; j < w; j++) {
                ptr[j] = (ref_ptr[j] + ref_ptr[j + ref_stride/sizeof(*ref_ptr)]) * local_factor;
            }
        } else {
            for (j = 0; j < w; j++) {
                ptr[j] = ref_ptr[j] * local_factor;
            }
        }
        ref_ptr += 2 * (ref_stride / sizeof(*ref_ptr));
        ptr += 2 * (stride / sizeof(*ptr));
    }
}
