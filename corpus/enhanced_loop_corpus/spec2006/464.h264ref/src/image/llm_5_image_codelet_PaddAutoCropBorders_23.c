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
    for (y = 0; y < org_size_y_cr; y++) {
        for (x = org_size_x_cr; x < img_size_x_cr; x++) {
            if (y % 2 == 0)
                continue;
            imgUV_org_frm[0][y][x] = imgUV_org_frm[0][y][x - 1];
            imgUV_org_frm[1][y][x] = imgUV_org_frm[1][y][x - 1];
        }
    }
}
