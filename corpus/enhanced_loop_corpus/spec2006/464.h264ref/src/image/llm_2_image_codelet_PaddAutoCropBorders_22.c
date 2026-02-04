#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgY_org_frm;
extern int org_size_y;
extern int img_size_x;
extern int img_size_y;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing row by row in natural order, access elements with a stride of 2,
    // then come back to fill the skipped elements. This changes spatial locality.
    for (int stride = 0; stride < 2; stride++) {
        for (y = org_size_y + stride; y < img_size_y; y += 2)
            for (x = 0; x < img_size_x; x++)
                imgY_org_frm[y][x] = imgY_org_frm[y - 1][x];
    }
}
