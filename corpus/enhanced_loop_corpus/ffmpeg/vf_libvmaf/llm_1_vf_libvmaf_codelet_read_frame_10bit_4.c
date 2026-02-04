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
    int idx = 0;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            for (int k = 0; k < 1; k++) {
                ptr[j] = main_ptr[j] * factor;
            }
        }
        main_ptr += main_stride / sizeof (*main_ptr);
        ptr += stride / sizeof (*ptr);
    }
}
