#include <stdio.h>

#include <inttypes.h>

extern int w;
extern int h;
extern float imgIn[4096][2160];
extern float y2[4096][2160];
extern int i;
extern int j;
extern float xp1;
extern float xp2;
extern float yp1;
extern float yp2;
extern float a3;
extern float a4;
extern float b1;
extern float b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i += 2) {
    for (j = h - 1; j >= 0; j--) {
        if (i < w) {
            yp1 = 0.F;
            yp2 = 0.F;
            xp1 = 0.F;
            xp2 = 0.F;
            for (int k = h - 1; k >= j; k--) {
                y2[i][k] = a3 * xp1 + a4 * xp2 + b1 * yp1 + b2 * yp2;
                xp2 = xp1;
                xp1 = imgIn[i][k];
                yp2 = yp1;
                yp1 = y2[i][k];
            }
        }
        if (i + 1 < w) {
            yp1 = 0.F;
            yp2 = 0.F;
            xp1 = 0.F;
            xp2 = 0.F;
            for (int k = h - 1; k >= j; k--) {
                y2[i+1][k] = a3 * xp1 + a4 * xp2 + b1 * yp1 + b2 * yp2;
                xp2 = xp1;
                xp1 = imgIn[i+1][k];
                yp2 = yp1;
                yp1 = y2[i+1][k];
            }
        }
    }
}
}
