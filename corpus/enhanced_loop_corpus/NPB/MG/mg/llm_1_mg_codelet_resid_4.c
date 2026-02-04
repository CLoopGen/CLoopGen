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
        for (i1 = 0; i1 < n1; i1++) {
            u1[i1] = u[i3][i2 - 1][i1] + u[i3][i2 + 1][i1] + u[i3 - 1][i2][i1] + u[i3 + 1][i2][i1];
            if (i1 < n1) {
                u2[i1] = u[i3 - 1][i2 - 1][i1] + u[i3 - 1][i2 + 1][i1] + u[i3 + 1][i2 - 1][i1] + u[i3 + 1][i2 + 1][i1];
            }
        }
        for (i1 = 1; i1 < n1 - 1; i1++) {
            double temp_u2_prev = u2[i1 - 1];
            double temp_u2_next = u2[i1 + 1];
            r[i3][i2][i1] = v[i3][i2][i1] - a[0] * u[i3][i2][i1] 
                           - a[2] * (u2[i1] + u1[i1 - 1] + u1[i1 + 1]) 
                           - a[3] * (temp_u2_prev + temp_u2_next);
        }
    }
}
}
