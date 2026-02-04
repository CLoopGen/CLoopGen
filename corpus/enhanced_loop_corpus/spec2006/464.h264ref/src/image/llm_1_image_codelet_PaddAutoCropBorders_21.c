#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imgY_org_frm;
extern int org_size_x;
extern int org_size_y;
extern int img_size_x;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int idx = 0; idx < org_size_y * (img_size_x - org_size_x); idx++) {
        y = idx / (img_size_x - org_size_x);
        x = org_size_x + (idx % (img_size_x - org_size_x));
        imgY_org_frm[y][x] = imgY_org_frm[y][x - 1];
    }
}
