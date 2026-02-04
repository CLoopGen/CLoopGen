#include <stdio.h>

#include <inttypes.h>

extern int w;
extern int h;
extern float imgOut[4096][2160];
extern float y2[4096][2160];
extern int i;
extern int j;
extern float tp1;
extern float tp2;
extern float yp1;
extern float yp2;
extern float a7;
extern float a8;
extern float b1;
extern float b2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j++) {
    tp1 = 0.F;
    tp2 = 0.F;
    yp1 = 0.F;
    yp2 = 0.F;
    for (i = w - 1; i >= 0; i--) {
        int idx = i * 4096 + j; // Row-major linearization for strided access
        y2[i][j] = a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2;
        tp2 = tp1;
        tp1 = imgOut[i][j];
        yp2 = yp1;
        yp1 = y2[i][j];
    }
}
}
