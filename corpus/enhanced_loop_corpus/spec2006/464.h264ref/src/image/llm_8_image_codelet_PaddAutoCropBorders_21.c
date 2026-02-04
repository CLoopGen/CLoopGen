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
    int y, x;
    for (y = 0; y < org_size_y; y++) {
        unsigned short *row = imgY_org_frm[y];
        for (x = org_size_x; x < img_size_x; x += 2) {
            row[x] = row[x - 1];
            if (x + 1 < img_size_x) {
                row[x + 1] = row[x];
            }
        }
    }
}
