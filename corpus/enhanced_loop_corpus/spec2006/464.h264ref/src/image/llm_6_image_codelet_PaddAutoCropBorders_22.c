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
    // Variant 1: Eliminate loop-carried dependence by reversing the loop order
    // This changes data dependency from RAW (read after write) to eliminate loop-carried dependence in the y-direction.
    // Instead of top-to-bottom, we now copy bottom-up, which removes the dependence on the previous row being updated.
    for (y = img_size_y - 1; y >= org_size_y; y--)
        for (x = 0; x < img_size_x; x++)
            imgY_org_frm[y][x] = imgY_org_frm[y - 1][x];
}
