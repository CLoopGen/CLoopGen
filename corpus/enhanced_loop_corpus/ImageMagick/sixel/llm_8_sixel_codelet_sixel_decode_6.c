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
    int idx;
    for (i = 0; i < imsx; i++) {
        for (int j = 0; j < imsy; j++) {
            idx = i * imsy + j;
            imbuf[idx] = (sixel_pixel_t)background_color_index;
        }
    }
}
