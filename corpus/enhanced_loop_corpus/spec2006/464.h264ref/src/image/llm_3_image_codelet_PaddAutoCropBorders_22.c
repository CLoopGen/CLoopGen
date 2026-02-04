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
    // Variant 2: Reverse Consecutive Memory Access Pattern
    // Traverse the rows in reverse order to modify memory access direction,
    // promoting backward temporal and spatial locality while maintaining correctness.
    for (y = img_size_y - 1; y >= org_size_y; y--)
        for (x = 0; x < img_size_x; x++)
            imgY_org_frm[y][x] = imgY_org_frm[y - 1][x];
}
