#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern int period;
extern int len;
extern  float g0;
extern  float g1;
extern  float g2;
extern float x4;
extern float x3;
extern float x2;
extern float x1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < len; i += 2) {
        float x0_1 = data[i - period + 2];
        float x0_2 = (i + 1 < len) ? data[i - period + 3] : x0_1;
        
        if (i < len) {
            data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0_1 + x4);
            x4 = x3;
            x3 = x2;
            x2 = x1;
            x1 = x0_1;
        }
        
        if (i + 1 < len) {
            float temp_x0 = x0_1;
            x0_1 = x0_2;
            data[i+1] += g0 * x1 + g1 * (x4 + x2) + g2 * (x0_1 + x3);
            x4 = x2;
            x3 = x1;
            x2 = temp_x0;
            x1 = x0_1;
        }
    }
}
