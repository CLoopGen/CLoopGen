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
for (i = 0; i < w; i++) {
    yp1 = 0.F;
    yp2 = 0.F;
    xp1 = 0.F;
    xp2 = 0.F;
    for (j = h - 1; j >= 0; j -= 2) {
        // Unroll loop by factor of 2 to increase computational intensity per iteration
        y2[i][j] = a3 * xp1 + a4 * xp2 + b1 * yp1 + b2 * yp2;
        if (j - 1 >= 0) {
            y2[i][j-1] = a3 * imgIn[i][j] + a4 * xp1 + b1 * y2[i][j] + b2 * yp1;
        }
        yp2 = (j - 1 >= 0) ? y2[i][j-1] : yp2;
        yp1 = (j - 1 >= 0) ? y2[i][j] : yp1;
        xp2 = (j - 1 >= 0) ? imgIn[i][j] : xp2;
        xp1 = (j - 1 >= 0) ? imgIn[i][j-1] : xp1;
    }
}
}
