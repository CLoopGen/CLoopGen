#include <stdio.h>

extern double ***u;
extern double ***v;
extern double ***r;
extern int n1;
extern int n2;
extern int n3;
extern double a[4];
extern int i3;
extern int i2;
extern int i1;
extern double u1[1037];
extern double u2[1037];



void loop(){
for (i3 = 1; i3 < n3 - 1; i3++) {
    for (i2 = 1; i2 < n2 - 1; i2++) {
        // Eliminate temporary array reuse by inlining computations and removing u1/u2 write-after-write dependencies
        // This removes the loop-carried dependence through u1 and u2 by recomputing directly
        for (i1 = 1; i1 < n1 - 1; i1++) {
            double u1_val = u[i3][i2 - 1][i1] + u[i3][i2 + 1][i1] +
                            u[i3 - 1][i2][i1] + u[i3 + 1][i2][i1];
            double u1_prev = u[i3][i2 - 1][i1 - 1] + u[i3][i2 + 1][i1 - 1] +
                             u[i3 - 1][i2][i1 - 1] + u[i3 + 1][i2][i1 - 1];
            double u1_next = u[i3][i2 - 1][i1 + 1] + u[i3][i2 + 1][i1 + 1] +
                             u[i3 - 1][i2][i1 + 1] + u[i3 + 1][i2][i1 + 1];

            double u2_val = u[i3 - 1][i2 - 1][i1] + u[i3 - 1][i2 + 1][i1] +
                            u[i3 + 1][i2 - 1][i1] + u[i3 + 1][i2 + 1][i1];
            double u2_prev = u[i3 - 1][i2 - 1][i1 - 1] + u[i3 - 1][i2 + 1][i1 - 1] +
                             u[i3 + 1][i2 - 1][i1 - 1] + u[i3 + 1][i2 + 1][i1 - 1];
            double u2_next = u[i3 - 1][i2 - 1][i1 + 1] + u[i3 - 1][i2 + 1][i1 + 1] +
                             u[i3 + 1][i2 - 1][i1 + 1] + u[i3 + 1][i2 + 1][i1 + 1];

            r[i3][i2][i1] = v[i3][i2][i1] - 
                            a[0] * u[i3][i2][i1] - 
                            a[2] * (u2_val + u1_prev + u1_next) - 
                            a[3] * (u2_prev + u2_next);
        }
    }
}
}
