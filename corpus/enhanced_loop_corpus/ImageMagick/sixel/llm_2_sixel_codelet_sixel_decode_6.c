#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short sixel_pixel_t;

extern int background_color_index;
extern int i;
extern int imsx;
extern int imsy;
extern sixel_pixel_t *imbuf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling to process two elements per iteration
    int size = imsx * imsy;
    int stride = 2;
    int i;
    for (i = 0; i < size; i += stride) {
        imbuf[i] = (sixel_pixel_t)background_color_index;
        if (i + 1 < size) {
            imbuf[i + 1] = (sixel_pixel_t)background_color_index;
        }
    }
}
