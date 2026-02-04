#include <stdio.h>

extern double ***z;
extern int mm1;
extern int mm2;
extern int mm3;
extern double ***u;
extern int i3;
extern int i2;
extern int i1;
extern int d1;
extern int d2;
extern int d3;
extern int t1;
extern int t2;



void loop(){
    // Variant 2: Reorder loops to increase cache efficiency and use consecutive-like access via index remapping
    // Also fuse similar computations where possible
    int offset_i3, offset_i2_d, offset_i2_t, offset_i1_d, offset_i1_t;
    for (i3 = d3; i3 <= mm3 - 1; i3++) {
        offset_i3 = 2 * i3 - d3 - 1;
        for (i2 = d2; i2 <= mm2 - 1; i2++) {
            offset_i2_d = 2 * i2 - d2 - 1;
            // First inner loop: full d1 to mm1-1 on i1 with direct dependencies
            for (i1 = d1; i1 <= mm1 - 1; i1++) {
                offset_i1_d = 2 * i1 - d1 - 1;
                u[offset_i3][offset_i2_d][offset_i1_d] += z[i3 - 1][i2 - 1][i1 - 1];
            }
            // Second inner loop: i1 from 1 to mm1-1 with averaging
            for (i1 = 1; i1 <= mm1 - 1; i1++) {
                offset_i1_t = 2 * i1 - t1 - 1;
                u[offset_i3][offset_i2_d][offset_i1_t] += 0.5 * (z[i3 - 1][i2 - 1][i1] + z[i3 - 1][i2 - 1][i1 - 1]);
            }
        }
        for (i2 = 1; i2 <= mm2 - 1; i2++) {
            offset_i2_t = 2 * i2 - t2 - 1;
            for (i1 = d1; i1 <= mm1 - 1; i1++) {
                offset_i1_d = 2 * i1 - d1 - 1;
                u[offset_i3][offset_i2_t][offset_i1_d] += 0.5 * (z[i3 - 1][i2][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
            }
            for (i1 = 1; i1 <= mm1 - 1; i1++) {
                offset_i1_t = 2 * i1 - t1 - 1;
                u[offset_i3][offset_i2_t][offset_i1_t] += 0.25 * (
                    z[i3 - 1][i2][i1] + 
                    z[i3 - 1][i2 - 1][i1] + 
                    z[i3 - 1][i2][i1 - 1] + 
                    z[i3 - 1][i2 - 1][i1 - 1]
                );
            }
        }
    }
}
