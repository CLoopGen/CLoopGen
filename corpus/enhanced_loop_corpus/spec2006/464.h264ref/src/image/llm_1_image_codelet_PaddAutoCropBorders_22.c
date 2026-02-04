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
if (org_size_y < img_size_y) {
    for (int i = org_size_y; i < img_size_y; i++)
        for (int j = 0; j < img_size_x; j++)
            imgY_org_frm[i][j] = imgY_org_frm[i - 1][j];
}
}
