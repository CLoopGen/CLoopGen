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
    float local_xp1 = 0.F;
    float local_xp2 = 0.F;
    float local_yp1 = 0.F;
    float local_yp2 = 0.F;
    for (j = h - 1; j >= 0; j--) {
        float temp = a3 * local_xp1 + a4 * local_xp2 + b1 * local_yp1 + b2 * local_yp2;
        y2[i][j] = temp;
        local_xp2 = local_xp1;
        local_xp1 = imgIn[i][j];
        local_yp2 = local_yp1;
        local_yp1 = temp;
    }
}
}
