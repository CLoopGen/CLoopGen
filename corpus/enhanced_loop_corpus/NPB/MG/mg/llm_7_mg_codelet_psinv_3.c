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
for (i3 = 1; i3 < n3 - 1; i3++) {
    for (i2 = 1; i2 < n2 - 1; i2++) {
        for (i1 = 1; i1 < n1 - 1; i1++) {
            double sum1 = r[i3][i2 - 1][i1] + r[i3][i2 + 1][i1] + r[i3 - 1][i2][i1] + r[i3 + 1][i2][i1];
            double sum2 = r[i3 - 1][i2 - 1][i1] + r[i3 - 1][i2 + 1][i1] + r[i3 + 1][i2 - 1][i1] + r[i3 + 1][i2 + 1][i1];
            double cross_term = c[1] * (r[i3][i2][i1 - 1] + r[i3][i2][i1 + 1] + sum1);
            double diag_term = c[2] * (sum2 + 
                (r[i3][i2 - 1][i1 - 1] + r[i3][i2 + 1][i1 - 1] + r[i3 - 1][i2][i1 - 1] + r[i3 + 1][i2][i1 - 1]) +
                (r[i3][i2 - 1][i1 + 1] + r[i3][i2 + 1][i1 + 1] + r[i3 - 1][i2][i1 + 1] + r[i3 + 1][i2][i1 + 1]));
            u[i3][i2][i1] = u[i3][i2][i1] + c[0] * r[i3][i2][i1] + cross_term + diag_term;
        }
    }
}
}
