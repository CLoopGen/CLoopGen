#include <stdio.h>

extern double ***r;
extern double ***s;
extern int m1j;
extern int m2j;
extern int m3j;
extern int j3;
extern int j2;
extern int j1;
extern int i3;
extern int i2;
extern int i1;
extern int d1;
extern int d2;
extern int d3;
extern double x1[1037];
extern double y1[1037];
extern double x2;
extern double y2;



void loop(){
for (j3 = 1; j3 < m3j - 1; j3++) {
    i3 = 2 * j3 - d3;
    for (j2 = 1; j2 < m2j - 1; j2++) {
        i2 = 2 * j2 - d2;
        for (j1 = 1; j1 < m1j; j1++) {
            i1 = 2 * j1 - d1;
            x1[i1] = r[i3 + 1][i2][i1] + r[i3 + 1][i2 + 2][i1] + r[i3][i2 + 1][i1] + r[i3 + 2][i2 + 1][i1];
            y1[i1] = r[i3][i2][i1] + r[i3 + 2][i2][i1] + r[i3][i2 + 2][i1] + r[i3 + 2][i2 + 2][i1];
            if (j1 < m1j - 1) {
                y2 = r[i3][i2][i1 + 1] + r[i3 + 2][i2][i1 + 1] + r[i3][i2 + 2][i1 + 1] + r[i3 + 2][i2 + 2][i1 + 1];
                x2 = r[i3 + 1][i2][i1 + 1] + r[i3 + 1][i2 + 2][i1 + 1] + r[i3][i2 + 1][i1 + 1] + r[i3 + 2][i2 + 1][i1 + 1];
                s[j3][j2][j1] = 0.5 * r[i3 + 1][i2 + 1][i1 + 1] + 0.25 * (r[i3 + 1][i2 + 1][i1] + r[i3 + 1][i2 + 1][i1 + 2] + x2) + 0.125 * (x1[i1] + x1[i1 + 2] + y2) + 0.0625 * (y1[i1] + y1[i1 + 2]);
            }
        }
    }
}
}
