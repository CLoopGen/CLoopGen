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
extern int t1;
extern int t2;
extern int t3;



void loop(){
for (i3 = 2; i3 <= mm3 - 2; i3 += 2) {
    for (i2 = d2; i2 <= mm2 - 2; i2++) {
        for (i1 = d1; i1 <= mm1 - 2; i1++) {
            u[2 * i3 - t3 - 1][2 * i2 - d2 - 1][2 * i1 - d1 - 1] = u[2 * i3 - t3 - 1][2 * i2 - d2 - 1][2 * i1 - d1 - 1] + 0.5 * (z[i3][i2 - 1][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
        }
        for (i1 = 2; i1 <= mm1 - 2; i1 += 2) {
            u[2 * i3 - t3 - 1][2 * i2 - d2 - 1][2 * i1 - t1 - 1] = u[2 * i3 - t3 - 1][2 * i2 - d2 - 1][2 * i1 - t1 - 1] + 0.25 * (z[i3][i2 - 1][i1] + z[i3][i2 - 1][i1 - 1] + z[i3 - 1][i2 - 1][i1] + z[i3 - 1][i2 - 1][i1 - 1]);
        }
    }
    for (i2 = 2; i2 <= mm2 - 2; i2 += 2) {
        for (i1 = d1; i1 <= mm1 - 2; i1++) {
            u[2 * i3 - t3 - 1][2 * i2 - t2 - 1][2 * i1 - d1 - 1] = u[2 * i3 - t3 - 1][2 * i2 - t2 - 1][2 * i1 - d1 - 1] + 0.25 * (z[i3][i2][i1 - 1] + z[i3][i2 - 1][i1 - 1] + z[i3 - 1][i2][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
        }
        for (i1 = 2; i1 <= mm1 - 2; i1 += 2) {
            u[2 * i3 - t3 - 1][2 * i2 - t2 - 1][2 * i1 - t1 - 1] = u[2 * i3 - t3 - 1][2 * i2 - t2 - 1][2 * i1 - t1 - 1] + 0.125 * (z[i3][i2][i1] + z[i3][i2 - 1][i1] + z[i3][i2][i1 - 1] + z[i3][i2 - 1][i1 - 1] + z[i3 - 1][i2][i1] + z[i3 - 1][i2 - 1][i1] + z[i3 - 1][i2][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
        }
    }
}
}
