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
        // Precompute and store intermediate values with modified dependency chain
        for (i1 = 0; i1 < mm1; i1++) {
            z1[i1] = z[i3][i2][i1];
            z2[i1] = z[i3 + 1][i2][i1];
            z3[i1] = z[i3 + 1][i2 + 1][i1];
        }
        // Introduce artificial loop-carried dependence by chaining updates
        double temp = 0.0;
        for (i1 = 0; i1 < mm1; i1++) {
            z1[i1] += z[i3][i2 + 1][i1] + temp;
            temp = z1[i1] * 0.1;  // WAW and RAW dependency introduced
        }
        temp = 0.0;
        for (i1 = 0; i1 < mm1; i1++) {
            z2[i1] += z2[i1] + z[i3][i2][i1] + temp;
            temp = z2[i1] * 0.1;
        }
        for (i1 = 0; i1 < mm1; i1++) {
            z3[i1] = z3[i1] + z[i3 + 1][i2][i1] + z1[i1];
        }
        // Update u using the delayed z-values with split loops to break dependencies
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u[2 * i3][2 * i2][2 * i1] += z[i3][i2][i1];
            u[2 * i3][2 * i2][2 * i1 + 1] += 0.5 * (z[i3][i2][i1 + 1] + z[i3][i2][i1]);
        }
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u[2 * i3][2 * i2 + 1][2 * i1] += 0.5 * z1[i1];
            u[2 * i3][2 * i2 + 1][2 * i1 + 1] += 0.25 * (z1[i1] + z1[i1 + 1]);
        }
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u[2 * i3 + 1][2 * i2][2 * i1] += 0.5 * z2[i1];
            u[2 * i3 + 1][2 * i2][2 * i1 + 1] += 0.25 * (z2[i1] + z2[i1 + 1]);
        }
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u[2 * i3 + 1][2 * i2 + 1][2 * i1] += 0.25 * z3[i1];
            u[2 * i3 + 1][2 * i2 + 1][2 * i1 + 1] += 0.125 * (z3[i1] + z3[i1 + 1]);
        }
    }
}
}
