#include <stdio.h>

extern double ***z;
extern int mm1;
extern int mm2;
extern int mm3;
extern double ***u;
extern int i3;
extern int i2;
extern int i1;
extern double z1[1037];
extern double z2[1037];
extern double z3[1037];



void loop(){
for (i3 = 0; i3 < mm3 - 1; i3++) {
    for (i2 = 0; i2 < mm2 - 1; i2++) {
        // Eliminate temporary arrays' loop-carried dependencies by fusing computations
        // and removing separate accumulation phases — now all in one pass
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            double local_z1_curr = z[i3][i2 + 1][i1] + z[i3][i2][i1];
            double local_z1_next = z[i3][i2 + 1][i1 + 1] + z[i3][i2][i1 + 1];
            double local_z2_curr = z[i3 + 1][i2][i1] + z[i3][i2][i1];
            double local_z2_next = z[i3 + 1][i2][i1 + 1] + z[i3][i2][i1 + 1];
            double local_z3_curr = z[i3 + 1][i2 + 1][i1] + z[i3 + 1][i2][i1] + local_z1_curr;
            double local_z3_next = z[i3 + 1][i2 + 1][i1 + 1] + z[i3 + 1][i2][i1 + 1] + local_z1_next;

            u[2 * i3][2 * i2][2 * i1] += z[i3][i2][i1];
            u[2 * i3][2 * i2][2 * i1 + 1] += 0.5 * (z[i3][i2][i1 + 1] + z[i3][i2][i1]);

            u[2 * i3][2 * i2 + 1][2 * i1] += 0.5 * local_z1_curr;
            u[2 * i3][2 * i2 + 1][2 * i1 + 1] += 0.25 * (local_z1_curr + local_z1_next);

            u[2 * i3 + 1][2 * i2][2 * i1] += 0.5 * local_z2_curr;
            u[2 * i3 + 1][2 * i2][2 * i1 + 1] += 0.25 * (local_z2_curr + local_z2_next);

            u[2 * i3 + 1][2 * i2 + 1][2 * i1] += 0.25 * local_z3_curr;
            u[2 * i3 + 1][2 * i2 + 1][2 * i1 + 1] += 0.125 * (local_z3_curr + local_z3_next);
        }
        // Handle edge case for i1 = mm1 - 1 if needed, but skip update loops that require i1+1
        // Only perform non-overflowing operations
        if (mm1 > 0) {
            z1[mm1 - 1] = z[i3][i2 + 1][mm1 - 1] + z[i3][i2][mm1 - 1];
            z2[mm1 - 1] = z[i3 + 1][i2][mm1 - 1] + z[i3][i2][mm1 - 1];
            z3[mm1 - 1] = z[i3 + 1][i2 + 1][mm1 - 1] + z[i3 + 1][i2][mm1 - 1] + z1[mm1 - 1];
        }
    }
}
}
