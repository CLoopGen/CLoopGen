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
for (i = 0; i < N; i++) {
    if (x[i] == 0 && y[i] == 0) {
        continue;
    }
    xavg += x[i];
    yavg += y[i];
}
}
