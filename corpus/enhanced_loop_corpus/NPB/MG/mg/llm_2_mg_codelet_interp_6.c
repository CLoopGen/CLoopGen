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
        double *z_ptr0 = z[i3][i2];
        double *z_ptr1 = z[i3][i2 + 1];
        double *z_ptr2 = z[i3 + 1][i2];
        double *z_ptr3 = z[i3 + 1][i2 + 1];
        for (i1 = 0; i1 < mm1; i1++) {
            z1[i1] = z_ptr1[i1] + z_ptr0[i1];
            z2[i1] = z_ptr2[i1] + z_ptr0[i1];
            z3[i1] = z_ptr3[i1] + z_ptr2[i1] + z1[i1];
        }
        double *u00 = u[2 * i3][2 * i2];
        double *u01 = u[2 * i3][2 * i2 + 1];
        double *u10 = u[2 * i3 + 1][2 * i2];
        double *u11 = u[2 * i3 + 1][2 * i2 + 1];
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u00[2 * i1] += z_ptr0[i1];
            u00[2 * i1 + 1] += 0.5 * (z_ptr0[i1 + 1] + z_ptr0[i1]);
        }
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u01[2 * i1] += 0.5 * z1[i1];
            u01[2 * i1 + 1] += 0.25 * (z1[i1] + z1[i1 + 1]);
        }
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u10[2 * i1] += 0.5 * z2[i1];
            u10[2 * i1 + 1] += 0.25 * (z2[i1] + z2[i1 + 1]);
        }
        for (i1 = 0; i1 < mm1 - 1; i1++) {
            u11[2 * i1] += 0.25 * z3[i1];
            u11[2 * i1 + 1] += 0.125 * (z3[i1] + z3[i1 + 1]);
        }
    }
}
}
