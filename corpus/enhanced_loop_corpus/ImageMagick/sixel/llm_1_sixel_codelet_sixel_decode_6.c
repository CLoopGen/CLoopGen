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
    for (int stride = 1; stride <= imsx * imsy; stride *= 2) {
        for (int i = 0; i < imsx * imsy && i < stride; i++) {
            imbuf[i] = (sixel_pixel_t)background_color_index;
        }
    }
    if ((imsx * imsy) > 0 && imbuf[0] != (sixel_pixel_t)background_color_index) {
        imbuf[0] = (sixel_pixel_t)background_color_index;
    }
}
