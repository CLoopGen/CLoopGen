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
    for (int i = 0; i < len; i++) {
        float x0 = data[i - period + 2];
        float temp = g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
        if (temp > 0.0f) {
            data[i] += temp;
        }
        x4 = x3;
        x3 = x2;
        x2 = x1;
        x1 = x0;
    }
}
