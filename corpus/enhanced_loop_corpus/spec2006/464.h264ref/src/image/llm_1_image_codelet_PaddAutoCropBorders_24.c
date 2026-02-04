#include <stdio.h>

#include <inttypes.h>

extern unsigned short ***imgUV_org_frm;
extern int org_size_y_cr;
extern int img_size_x_cr;
extern int img_size_y_cr;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = org_size_y_cr; y < img_size_y_cr; y++)
        for (int plane = 0; plane < 2; plane++)
            for (x = 0; x < img_size_x_cr; x++) {
                imgUV_org_frm[plane][y][x] = imgUV_org_frm[plane][y - 1][x];
            }
}
