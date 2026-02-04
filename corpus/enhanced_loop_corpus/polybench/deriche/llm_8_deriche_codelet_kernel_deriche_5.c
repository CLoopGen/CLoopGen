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
    for (i = w - 1; i >= 0; i -= 2) {
        // Unroll loop by factor of 2 to increase computational intensity
        if (i == 0) {
            y2[i][j] = a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2;
            yp1 = y2[i][j];
            tp2 = tp1;
            tp1 = imgOut[i][j];
        } else {
            // First element
            y2[i][j] = a7 * tp1 + a8 * tp2 + b1 * yp1 + b2 * yp2;
            float temp_tp1_1 = imgOut[i][j];
            float temp_yp1_1 = y2[i][j];

            // Second element using updated states
            y2[i-1][j] = a7 * tp1 + a8 * tp2 + b1 * temp_yp1_1 + b2 * yp1;

            // Update state variables accordingly
            tp2 = tp1;
            tp1 = imgOut[i-1][j];
            yp2 = yp1;
            yp1 = y2[i-1][j];
        }
    }
}
}
