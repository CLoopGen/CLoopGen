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
    for (i = 0; i < N; i += 2) {
        xavg += x[i];
        yavg += y[i];
        if (i + 1 < N) {
            xavg += x[i + 1];
            yavg += y[i + 1];
        }
    }
}
