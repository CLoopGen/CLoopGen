#include <stdio.h>

#include <inttypes.h>

extern unsigned short ***imgUV_org_frm;
extern int org_size_y_cr;
extern int img_size_x_cr;
extern int img_size_y_cr;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index arrays to simulate irregular access pattern
    // Simulate indirect addressing via pointer-like indexing (avoiding actual pointers for clarity)
    int *index_map_x = (int*)__builtin_alloca(img_size_x_cr * sizeof(int));
    for (int i = 0; i < img_size_x_cr; i++) {
        index_map_x[i] = i; // Identity mapping, could be randomized in real use cases
    }

    for (y = org_size_y_cr; y < img_size_y_cr; y++)
        for (int ix = 0; ix < img_size_x_cr; ix++) {
            x = index_map_x[ix]; // Use indirect index
            imgUV_org_frm[0][y][x] = imgUV_org_frm[0][y - 1][x];
            imgUV_org_frm[1][y][x] = imgUV_org_frm[1][y - 1][x];
        }
}
