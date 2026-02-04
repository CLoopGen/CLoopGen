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
    j = 0;
    if (j < w) {
        do {
            ptr[j] = ref_ptr[j] * factor;
            j++;
        } while (j < w);
    }
    ref_ptr += ref_stride / sizeof (*ref_ptr);
    ptr += stride / sizeof (*ptr);
}
}
