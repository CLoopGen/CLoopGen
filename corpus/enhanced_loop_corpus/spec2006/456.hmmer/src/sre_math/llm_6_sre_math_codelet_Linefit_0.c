#include <stdio.h>

#include <inttypes.h>

extern float *x;
extern float *y;
extern int N;
extern float xavg;
extern float yavg;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_xavg = 0.0f;
    float temp_yavg = 0.0f;
    for (i = 0; i < N; i++) {
        temp_xavg += x[i];
        temp_yavg += y[i];
    }
    xavg = temp_xavg;
    yavg = temp_yavg;
}
