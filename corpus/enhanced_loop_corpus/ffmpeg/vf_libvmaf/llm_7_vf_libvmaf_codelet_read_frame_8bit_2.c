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
    for (i = 0; i < h; i++) {
        float acc = 0.0f;
        for (j = 0; j < w; j++) {
            acc += main_ptr[j] * factor;
            ptr[j] = acc;
        }
        main_ptr += main_stride / sizeof (*main_ptr);
        ptr += stride / sizeof (*ptr);
    }
}
