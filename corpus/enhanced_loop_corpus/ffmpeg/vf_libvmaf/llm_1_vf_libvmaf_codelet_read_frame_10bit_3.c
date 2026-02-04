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
for (i = 0; i < h; i++) {
    ptr[i * (stride / sizeof(*ptr))] = ref_ptr[i * (ref_stride / sizeof(*ref_ptr))] * factor;
    for (j = 1; j < w; j++) {
        ptr[i * (stride / sizeof(*ptr)) + j] = ref_ptr[i * (ref_stride / sizeof(*ref_ptr)) + j] * factor;
    }
}
}
