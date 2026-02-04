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
    // Variant 2: Memory Access Pattern Modification - Strided Access with Reverse Iteration
    for (y = 0; y < org_size_y_cr; y++) {
        for (x = img_size_x_cr - 1; x >= org_size_x_cr; x--) {
            // Introduce strided access by processing every second element first, then filling gaps
            if ((x - org_size_x_cr) % 2 == 0 && x > org_size_x_cr) {
                imgUV_org_frm[0][y][x] = imgUV_org_frm[0][y][x - 1];
                imgUV_org_frm[1][y][x] = imgUV_org_frm[1][y][x - 1];
            }
        }
        for (x = org_size_x_cr + 1; x < img_size_x_cr; x++) {
            if ((x - org_size_x_cr) % 2 == 1) {
                imgUV_org_frm[0][y][x] = imgUV_org_frm[0][y][x - 1];
                imgUV_org_frm[1][y][x] = imgUV_org_frm[1][y][x - 1];
            }
        }
    }
}
