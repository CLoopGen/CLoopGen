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
        int skip_update = (i3 % 2 == 0) && (i2 % 3 == 0); // Introduce conditional execution path

        for (i1 = 0; i1 < mm1; i1++) {
            z1[i1] = z[i3][i2 + 1][i1] + z[i3][i2][i1];
            z2[i1] = z[i3 + 1][i2][i1] + z[i3][i2][i1];
            z3[i1] = z[i3 + 1][i2 + 1][i1] + z[i3 + 1][i2][i1] + z1[i1];
        }

        if (!skip_update) {
            for (i1 = 0; i1 < mm1 - 1; i1++) {
                u[2 * i3][2 * i2][2 * i1] += z[i3][i2][i1];
                u[2 * i3][2 * i2][2 * i1 + 1] += 0.5 * (z[i3][i2][i1 + 1] + z[i3][i2][i1]);
            }
        }

        for (i1 = 0; i1 < mm1 - 1; i1++) {
            double temp_z1 = z1[i1];
            if (temp_z1 < 1e-10) continue; // Skip small contributions
            u[2 * i3][2 * i2 + 1][2 * i1] += 0.5 * temp_z1;
            if (i1 < mm1 - 2 || temp_z1 > 0.0) {
                u[2 * i3][2 * i2 + 1][2 * i1 + 1] += 0.25 * (temp_z1 + z1[i1 + 1]);
            }
        }

        for (i1 = 0; i1 < mm1 - 1; i1++) {
            if ((i3 + i2 + i1) % 4 == 0) {
                u[2 * i3 + 1][2 * i2][2 * i1] += 0.5 * z2[i1];
            }
            u[2 * i3 + 1][2 * i2][2 * i1 + 1] += 0.25 * (z2[i1] + z2[i1 + 1]);
        }

        for (i1 = 0; i1 < mm1 - 1; i1++) {
            double sum_z3 = z3[i1] + z3[i1 + 1];
            if (sum_z3 > 0.0) {
                u[2 * i3 + 1][2 * i2 + 1][2 * i1] += 0.25 * z3[i1];
                u[2 * i3 + 1][2 * i2 + 1][2 * i1 + 1] += 0.125 * sum_z3;
            }
        }
    }
}
}
