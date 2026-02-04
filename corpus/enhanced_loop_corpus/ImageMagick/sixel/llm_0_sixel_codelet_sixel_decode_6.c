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
    for (int y = 0; y < imsy; y++) {
        for (int x = 0; x < imsx; x++) {
            imbuf[y * imsx + x] = (sixel_pixel_t)background_color_index;
        }
    }
}
