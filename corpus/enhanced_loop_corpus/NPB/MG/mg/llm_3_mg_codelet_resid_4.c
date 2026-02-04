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
    // Variant 2: Memory Access Pattern Modification - Consecutive access via loop interchange to improve spatial locality in i1 dimension first
    for (i1 = 1; i1 < n1 - 1; i1++) {
        for (i3 = 1; i3 < n3 - 1; i3++) {
            for (i2 = 1; i2 < n2 - 1; i2++) {
                // Precompute u1 and u2 values using original logic but now inner loop on i2 allows better reuse if u1/u2 are small
                u1[i1] = u[i3][i2 - 1][i1] + u[i3][i2 + 1][i1] + u[i3 - 1][i2][i1] + u[i3 + 1][i2][i1];
                u2[i1] = u[i3 - 1][i2 - 1][i1] + u[i3 - 1][i2 + 1][i1] + u[i3 + 1][i2 - 1][i1] + u[i3 + 1][i2 + 1][i1];
                
                r[i3][i2][i1] = v[i3][i2][i1] - a[0] * u[i3][i2][i1] - a[2] * (u2[i1] + u1[i1 - 1] + u1[i1 + 1]) - a[3] * (u2[i1 - 1] + u2[i1 + 1]);
            }
        }
    }
}
