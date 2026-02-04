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
    // Variant 2: Reverse consecutive memory access — traverse array from last to first element
    int size = imsx * imsy;
    int i;
    for (i = size - 1; i >= 0; i--) {
        imbuf[i] = (sixel_pixel_t)background_color_index;
    }
}
