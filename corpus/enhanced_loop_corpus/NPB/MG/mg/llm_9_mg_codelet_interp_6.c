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
for (i3 = 0; i3 < mm3 - 2; i3++) {
    for (i2 = 0; i2 < mm2 - 2; i2++) {
        double temp_z1, temp_z2, temp_z3;
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            temp_z1 = z[i3][i2 + 1][i1] + z[i3][i2][i1];
            temp_z2 = z[i3 + 1][i2][i1] + z[i3][i2][i1];
            temp_z3 = z[i3 + 1][i2 + 1][i1] + z[i3 + 1][i2][i1] + temp_z1;

            u[2 * i3][2 * i2][2 * i1] += z[i3][i2][i1];
            u[2 * i3][2 * i2][2 * i1 + 1] += 0.5 * (z[i3][i2][i1 + 1] + z[i3][i2][i1]);

            if (i1 < mm1 - 1) {
                u[2 * i3][2 * i2 + 1][2 * i1] += 0.5 * temp_z1;
                u[2 * i3][2 * i2 + 1][2 * i1 + 1] += 0.25 * (temp_z1 + z[i3][i2 + 1][i1 + 1] + z[i3][i2][i1 + 1]);
                u[2 * i3 + 1][2 * i2][2 * i1] += 0.5 * temp_z2;
                u[2 * i3 + 1][2 * i2][2 * i1 + 1] += 0.25 * (temp_z2 + z[i3 + 1][i2][i1 + 1] + z[i3][i2][i1 + 1]);
                u[2 * i3 + 1][2 * i2 + 1][2 * i1] += 0.25 * temp_z3;
                u[2 * i3 + 1][2 * i2 + 1][2 * i1 + 1] += 0.125 * (temp_z3 + z[i3 + 1][i2 + 1][i1 + 1] + z[i3 + 1][i2][i1 + 1] + temp_z1 + z[i3][i2 + 1][i1 + 1] + z[i3][i2][i1 + 1]);
            }
        }
    }
}
}
