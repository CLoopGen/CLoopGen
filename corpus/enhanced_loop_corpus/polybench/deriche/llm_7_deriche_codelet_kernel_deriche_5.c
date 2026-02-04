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
    float local_tp1 = 0.F;
    float local_tp2 = 0.F;
    float local_yp1 = 0.F;
    float local_yp2 = 0.F;
    for (i = w - 1; i >= 0; i--) {
        float prediction = a7 * local_tp1 + a8 * local_tp2 + b1 * local_yp1 + b2 * local_yp2;
        y2[i][j] = prediction;
        local_tp2 = local_tp1;
        local_tp1 = imgOut[i][j];
        local_yp2 = local_yp1;
        local_yp1 = prediction;
    }
    tp1 = local_tp1;
    tp2 = local_tp2;
    yp1 = local_yp1;
    yp2 = local_yp2;
}
}
