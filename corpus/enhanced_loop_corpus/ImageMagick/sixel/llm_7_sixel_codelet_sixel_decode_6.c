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
    sixel_pixel_t bg_val = (sixel_pixel_t)background_color_index;
    for (i = imsx * imsy - 1; i >= 0; i--) {
        imbuf[i] = bg_val;
    }
}
