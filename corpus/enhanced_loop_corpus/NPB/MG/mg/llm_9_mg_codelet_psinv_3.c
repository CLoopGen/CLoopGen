#include <stdio.h>

extern double ***r;
extern double ***u;
extern int n1;
extern int n2;
extern int n3;
extern double c[4];
extern int i3;
extern int i2;
extern int i1;
extern double r1[1037];
extern double r2[1037];



void loop(){
for (i3 = 1; i3 < n3 - 1; i3 += 2) {
    for (i2 = 1; i2 < n2 - 1; i2 += 2) {
        for (i1 = 0; i1 < n1; i1++) {
            double sum_cross = r[i3][i2 - 1][i1] + r[i3][i2 + 1][i1] + r[i3 - 1][i2][i1] + r[i3 + 1][i2][i1];
            r1[i1] = sum_cross;
            r2[i1] = 0.5 * sum_cross;
        }
        for (i1 = 1; i1 < n1 - 1; i1 += 2) {
            u[i3][i2][i1] = u[i3][i2][i1] 
                          + c[0] * r[i3][i2][i1] 
                          + c[1] * (r[i3][i2][i1 - 1] + r[i3][i2][i1 + 1] + r1[i1]);
        }
        if (i2 + 1 < n2 - 1) {
            for (i1 = 1; i1 < n1 - 1; i1 += 2) {
                u[i3][i2 + 1][i1] = u[i3][i2 + 1][i1] 
                                  + c[0] * r[i3][i2 + 1][i1] 
                                  + c[1] * (r[i3][i2 + 1][i1 - 1] + r[i3][i2 + 1][i1 + 1] + r1[i1]);
            }
        }
    }
}
}
