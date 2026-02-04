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
    int i;
    float xsum_local = 0.0f, ysum_local = 0.0f;
    for (i = 0; i < N; i++) {
        xsum_local += x[i] * x[i];  
        ysum_local += y[i] * y[i];  
    }
    xavg = xsum_local / N;
    yavg = ysum_local / N;
}
