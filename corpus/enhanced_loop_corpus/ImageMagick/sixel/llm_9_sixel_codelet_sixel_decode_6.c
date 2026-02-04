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
    int step = 2;
    int limit = imsx * imsy;
    for (i = 0; i < limit; i += step) {
        imbuf[i] = (sixel_pixel_t)background_color_index;
        if (i + 1 < limit) {
            imbuf[i + 1] = (sixel_pixel_t)background_color_index;
        }
    }
}
