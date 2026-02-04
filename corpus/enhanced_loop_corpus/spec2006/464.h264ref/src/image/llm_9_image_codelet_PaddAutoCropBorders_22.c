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
    int step = 1;
    int limit = img_size_y - 1;
    for (y = org_size_y; y < limit; y += step) {
        for (x = 0; x < img_size_x; x++) {
            unsigned short temp1 = imgY_org_frm[y - 0][x];
            unsigned short temp2 = imgY_org_frm[y + 1][x];
            imgY_org_frm[y + 1][x] = temp1;
        }
    }
    // Handle remaining rows with reduced trip count and increased operation density
    if (img_size_y > org_size_y) {
        y = img_size_y - 1;
        for (x = 0; x < img_size_x; x++) {
            imgY_org_frm[y][x] = imgY_org_frm[org_size_y][x];
        }
    }
}
