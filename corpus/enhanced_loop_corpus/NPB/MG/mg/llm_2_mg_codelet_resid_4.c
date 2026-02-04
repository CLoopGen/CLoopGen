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
    // Variant 1: Memory Access Pattern Modification - Use strided access with stride of 2 for u and v arrays (simulating reduced resolution or skipping elements)
    for (i3 = 2; i3 < n3 - 2; i3 += 2) {
        for (i2 = 2; i2 < n2 - 2; i2 += 2) {
            for (i1 = 0; i1 < n1; i1++) {
                u1[i1] = u[i3][i2 - 2][i1] + u[i3][i2 + 2][i1] + u[i3 - 2][i2][i1] + u[i3 + 2][i2][i1];
                u2[i1] = u[i3 - 2][i2 - 2][i1] + u[i3 - 2][i2 + 2][i1] + u[i3 + 2][i2 - 2][i1] + u[i3 + 2][i2 + 2][i1];
            }
            for (i1 = 2; i1 < n1 - 2; i1 += 2) {
                r[i3][i2][i1] = v[i3][i2][i1] - a[0] * u[i3][i2][i1] - a[2] * (u2[i1] + u1[i1 - 2] + u1[i1 + 2]) - a[3] * (u2[i1 - 2] + u2[i1 + 2]);
            }
        }
    }
}
