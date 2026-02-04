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
    // Variant 1: Memory Access Pattern Modification - Strided Access with Reverse Traversal
    // Instead of left-to-right propagation, we traverse from right to left in strides of 2,
    // updating every second element first, then filling in the gaps. This changes spatial locality.
    for (y = 0; y < org_size_y; y++) {
        // First pass: update even offsets from the right (strided by 2)
        for (x = img_size_x - 2; x >= org_size_x; x -= 2) {
            if (x - 2 >= org_size_x) {
                imgY_org_frm[y][x] = imgY_org_frm[y][x - 2];
            } else if (x - 1 >= org_size_x) {
                imgY_org_frm[y][x] = imgY_org_frm[y][x - 1];
            }
        }
        // Second pass: fill in odd offsets using previous element
        for (x = img_size_x - 1; x >= org_size_x; x -= 2) {
            if (x - 1 >= org_size_x) {
                imgY_org_frm[y][x] = imgY_org_frm[y][x - 1];
            }
        }
    }
}
