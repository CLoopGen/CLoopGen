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
    for (i = 0; i < h * w; i++) {
        int current_row = i / w;
        int current_col = i % w;
        if (current_col == 0 && current_row > 0) {
            main_ptr += main_stride / sizeof(*main_ptr);
            ptr += stride / sizeof(*ptr);
        }
        ptr[current_col] = main_ptr[current_col] * factor;
    }
}
