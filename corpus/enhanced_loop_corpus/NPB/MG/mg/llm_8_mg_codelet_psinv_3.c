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
for (i3 = 2; i3 < n3 - 2; i3++) {
    for (i2 = 2; i2 < n2 - 2; i2++) {
        for (i1 = 0; i1 < n1; i1++) {
            r1[i1] = 2.0 * (r[i3][i2 - 1][i1] + r[i3][i2 + 1][i1] + r[i3 - 1][i2][i1] + r[i3 + 1][i2][i1]);
            r2[i1] = 1.5 * (r[i3 - 1][i2 - 1][i1] + r[i3 - 1][i2 + 1][i1] + r[i3 + 1][i2 - 1][i1] + r[i3 + 1][i2 + 1][i1]);
        }
        for (i1 = 2; i1 < n1 - 2; i1++) {
            double temp1 = r[i3][i2][i1 - 2] + r[i3][i2][i1 + 2];
            double temp2 = r1[i1 - 2] + r1[i1 + 2];
            u[i3][i2][i1] = u[i3][i2][i1] 
                          + c[0] * r[i3][i2][i1] 
                          + c[1] * (r[i3][i2][i1 - 1] + r[i3][i2][i1 + 1] + r1[i1]) 
                          + c[2] * (r2[i1] + r1[i1 - 1] + r1[i1 + 1])
                          + c[3] * (temp1 + temp2);
        }
    }
}
}
