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
    float temp_x1 = x1;
    float temp_x2 = x2;
    float temp_x3 = x3;
    float temp_x4 = x4;
    for (int i = 0; i < len; i++) {
        float x0 = data[i - period + 2];
        data[i] += g0 * temp_x2 + g1 * (temp_x1 + temp_x3) + g2 * (x0 + temp_x4);
        temp_x4 = temp_x3;
        temp_x3 = temp_x2;
        temp_x2 = temp_x1;
        temp_x1 = x0;
    }
    x4 = temp_x4;
    x3 = temp_x3;
    x2 = temp_x2;
    x1 = temp_x1;
}
