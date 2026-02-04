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
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            xavg += x[i] + x[i + 1];
            yavg += y[i] + y[i + 1];
        } else {
            xavg += x[i];
            yavg += y[i];
        }
    }
}
