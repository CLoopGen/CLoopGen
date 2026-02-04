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
    int y_start = org_size_y_cr + 1;
    for (y = y_start; y < img_size_y_cr; y++) {
        for (x = 0; x < img_size_x_cr; x += 2) {
            if (y - 2 >= 0) {
                imgUV_org_frm[0][y][x] = imgUV_org_frm[0][y - 2][x];
                imgUV_org_frm[1][y][x] = imgUV_org_frm[1][y - 2][x];
                if (x + 1 < img_size_x_cr) {
                    imgUV_org_frm[0][y][x+1] = imgUV_org_frm[0][y - 2][x+1];
                    imgUV_org_frm[1][y][x+1] = imgUV_org_frm[1][y - 2][x+1];
                }
            } else {
                imgUV_org_frm[0][y][x] = 0;
                imgUV_org_frm[1][y][x] = 0;
                if (x + 1 < img_size_x_cr) {
                    imgUV_org_frm[0][y][x+1] = 0;
                    imgUV_org_frm[1][y][x+1] = 0;
                }
            }
        }
    }
}
