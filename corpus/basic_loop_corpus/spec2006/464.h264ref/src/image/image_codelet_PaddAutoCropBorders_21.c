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
for (y = 0; y < org_size_y; y++)
    for (x = org_size_x; x < img_size_x; x++)
        imgY_org_frm[y][x] = imgY_org_frm[y][x - 1];

}
