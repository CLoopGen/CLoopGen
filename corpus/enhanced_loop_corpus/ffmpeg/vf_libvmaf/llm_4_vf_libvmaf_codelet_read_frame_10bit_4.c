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
    for (i = 0; i < h; i++) {
        if (w > 0) {
            ptr[0] = main_ptr[0] * factor;
            for (j = 1; j < w; j++) {
                ptr[j] = main_ptr[j] * factor;
            }
        }
        main_ptr += main_stride / sizeof(*main_ptr);
        ptr += stride / sizeof(*ptr);
    }
}
