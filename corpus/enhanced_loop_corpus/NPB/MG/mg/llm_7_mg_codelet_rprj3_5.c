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
for (j3 = 1; j3 < m3j - 1; j3 += 2) {
    i3 = 2 * j3 - d3;
    for (j2 = 1; j2 < m2j - 1; j2 += 2) {
        i2 = 2 * j2 - d2;
        for (j1 = 1; j1 < m1j; j1++) {
            i1 = 2 * j1 - d1;
            double temp1 = r[i3 + 1][i2][i1] + r[i3 + 1][i2 + 2][i1];
            double temp2 = r[i3][i2 + 1][i1] + r[i3 + 2][i2 + 1][i1];
            x1[i1] = temp1 + temp2;
            y1[i1] = r[i3][i2][i1] + r[i3 + 2][i2][i1] + r[i3][i2 + 2][i1] + r[i3 + 2][i2 + 2][i1];
        }
        for (j1 = 1; j1 < m1j - 1; j1++) {
            i1 = 2 * j1 - d1;
            double sum_corner_y = r[i3][i2][i1 + 1] + r[i3 + 2][i2][i1 + 1] + r[i3][i2 + 2][i1 + 1] + r[i3 + 2][i2 + 2][i1 + 1];
            double sum_edge_x = r[i3 + 1][i2][i1 + 1] + r[i3 + 1][i2 + 2][i1 + 1] + r[i3][i2 + 1][i1 + 1] + r[i3 + 2][i2 + 1][i1 + 1];
            s[j3][j2][j1] = 0.5 * r[i3 + 1][i2 + 1][i1 + 1] + 
                           0.25 * (r[i3 + 1][i2 + 1][i1] + r[i3 + 1][i2 + 1][i1 + 2] + sum_edge_x) + 
                           0.125 * (x1[i1] + x1[i1 + 2] + sum_corner_y) + 
                           0.0625 * (y1[i1] + y1[i1 + 2]);
        }
    }
}
}
