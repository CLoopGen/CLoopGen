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
    int temp_val0, temp_val1;
    for (y = 0; y < org_size_y_cr; y++) {
        temp_val0 = imgUV_org_frm[0][y][org_size_x_cr - 1];
        temp_val1 = imgUV_org_frm[1][y][org_size_x_cr - 1];
        for (x = org_size_x_cr; x < img_size_x_cr; x++) {
            imgUV_org_frm[0][y][x] = temp_val0;
            imgUV_org_frm[1][y][x] = temp_val1;
        }
    }
}
