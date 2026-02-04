#include <stdio.h>

#include <inttypes.h>

extern unsigned short ***imgUV_org_frm;
extern int org_size_x_cr;
extern int org_size_y_cr;
extern int img_size_x_cr;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Consecutive Access via Pointer Arithmetic
    for (y = 0; y < org_size_y_cr; y++) {
        unsigned short *row0 = imgUV_org_frm[0][y];
        unsigned short *row1 = imgUV_org_frm[1][y];
        for (x = org_size_x_cr; x < img_size_x_cr; x++) {
            row0[x] = row0[x - 1];
            row1[x] = row1[x - 1];
        }
    }
}
