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
        // Precompute offsets to reduce redundant calculations
        int base_i3 = 2 * i3;
        int base_i3p1 = 2 * i3 + 1;
        int base_i2 = 2 * i2;
        int base_i2p1 = 2 * i2 + 1;

        for (i1 = 0; i1 < mm1; i1++) {
            z1[i1] = z[i3][i2 + 1][i1] + z[i3][i2][i1];
            z2[i1] = z[i3 + 1][i2][i1] + z[i3][i2][i1];
            z3[i1] = z[i3 + 1][i2 + 1][i1] + z[i3 + 1][i2][i1] + z1[i1];
        }

        for (i1 = 0; i1 < mm1 - 1; i1++) {
            if (i1 % 2 == 0) {
                u[base_i3][base_i2][2 * i1] += z[i3][i2][i1];
            } else {
                u[base_i3][base_i2][2 * i1] = u[base_i3][base_i2][2 * i1]; // No-op branch to alter control flow
            }
            u[base_i3][base_i2][2 * i1 + 1] += 0.5 * (z[i3][i2][i1 + 1] + z[i3][i2][i1]);
        }

        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u[base_i3][base_i2p1][2 * i1] += 0.5 * z1[i1];
            if (z1[i1] > 0.0) {
                u[base_i3][base_i2p1][2 * i1 + 1] += 0.25 * (z1[i1] + z1[i1 + 1]);
            }
        }

        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u[base_i3p1][base_i2][2 * i1] += 0.5 * z2[i1];
            if (z2[i1] < 1e-8) continue;
            u[base_i3p1][base_i2][2 * i1 + 1] += 0.25 * (z2[i1] + z2[i1 + 1]);
        }

        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u[base_i3p1][base_i2p1][2 * i1] += 0.25 * z3[i1];
            if (z3[i1] >= 0.0 && z3[i1 + 1] >= 0.0) {
                u[base_i3p1][base_i2p1][2 * i1 + 1] += 0.125 * (z3[i1] + z3[i1 + 1]);
            }
        }
    }
}
}
