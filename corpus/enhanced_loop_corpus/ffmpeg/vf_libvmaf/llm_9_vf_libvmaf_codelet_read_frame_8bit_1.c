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
    for (j = 0; j < w; j++) {
        float temp = ref_ptr[j] * factor;
        ptr[j] = temp + (temp * 0.1f); // Increase arithmetic intensity
    }
    ref_ptr += ref_stride / sizeof (*ref_ptr);
    ptr += stride / sizeof (*ptr);
}
}
