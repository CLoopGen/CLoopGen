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
        // Introduce forward reuse: precompute shared terms across iterations to create WAW and RAW dependencies
        double prev_x2 = 0.0, prev_y2 = 0.0;
        for (j1 = 1; j1 < m1j; j1++) {
            i1 = 2 * j1 - d1;
            // Reuse previous iteration's x2/y2 as prediction-like input (artificial dependency introduced)
            if (j1 > 1) {
                x1[i1] = r[i3 + 1][i2][i1] + r[i3 + 1][i2 + 2][i1] + r[i3][i2 + 1][i1] + r[i3 + 2][i2 + 1][i1] + 0.01 * prev_x2;
                y1[i1] = r[i3][i2][i1] + r[i3 + 2][i2][i1] + r[i3][i2 + 2][i1] + r[i3 + 2][i2 + 2][i1] + 0.01 * prev_y2;
            } else {
                x1[i1] = r[i3 + 1][i2][i1] + r[i3 + 1][i2 + 2][i1] + r[i3][i2 + 1][i1] + r[i3 + 2][i2 + 1][i1];
                y1[i1] = r[i3][i2][i1] + r[i3 + 2][i2][i1] + r[i3][i2 + 2][i1] + r[i3 + 2][i2 + 2][i1];
            }
        }
        for (j1 = 1; j1 < m1j - 1; j1++) {
            i1 = 2 * j1 - d1;
            // Carry forward dependency via updated x2/y2 used in next iteration
            y2 = r[i3][i2][i1 + 1] + r[i3 + 2][i2][i1 + 1] + r[i3][i2 + 2][i1 + 1] + r[i3 + 2][i2 + 2][i1 + 1];
            x2 = r[i3 + 1][i2][i1 + 1] + r[i3 + 1][i2 + 2][i1 + 1] + r[i3][i2 + 1][i1 + 1] + r[i3 + 2][i2 + 1][i1 + 1];
            // Add artificial feedback from prior x2/y2 (introducing loop-carried RAW/WAR dependencies)
            s[j3][j2][j1] = 0.5 * r[i3 + 1][i2 + 1][i1 + 1] 
                          + 0.25 * (r[i3 + 1][i2 + 1][i1] + r[i3 + 1][i2 + 1][i1 + 2] + x2 + 0.05 * prev_x2) 
                          + 0.125 * (x1[i1] + x1[i1 + 2] + y2 + 0.05 * prev_y2) 
                          + 0.0625 * (y1[i1] + y1[i1 + 2]);
            // Update state for next iteration
            prev_x2 = x2;
            prev_y2 = y2;
        }
    }
}
}
