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
    // Variant 2: Introduce additional artificial loop-carried dependency via temporary accumulation
    // Adds a cumulative dependency across iterations (chain of values), creating a strict sequential (loop-carried) dependency.
    // This increases RAW hazards and prevents any parallelization across y or x.

    unsigned short temp_accum_0 = 0;
    unsigned short temp_accum_1 = 0;

    for (y = org_size_y_cr; y < img_size_y_cr; y++)
        for (x = 0; x < img_size_x_cr; x++) {
            // Introduce dependency on previous computed value (not just source array)
            temp_accum_0 = imgUV_org_frm[0][y - 1][x] + temp_accum_0;
            temp_accum_1 = imgUV_org_frm[1][y - 1][x] + temp_accum_1;

            imgUV_org_frm[0][y][x] = temp_accum_0;
            imgUV_org_frm[1][y][x] = temp_accum_1;
        }
}
