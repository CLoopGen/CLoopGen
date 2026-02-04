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
    int y_start = org_size_y + 1;
    for (y = y_start; y < img_size_y; y++) {
        for (x = 0; x < img_size_x; x += 2) {
            if (y - 2 >= org_size_y) {
                imgY_org_frm[y][x] = imgY_org_frm[y - 2][x];
            } else {
                imgY_org_frm[y][x] = imgY_org_frm[y - 1][x];
            }
            if (x + 1 < img_size_x) {
                imgY_org_frm[y][x + 1] = imgY_org_frm[y - 1][x + 1];
            }
        }
    }
}
