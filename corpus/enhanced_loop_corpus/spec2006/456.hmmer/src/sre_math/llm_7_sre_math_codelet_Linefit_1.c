#include <stdio.h>

#include <inttypes.h>

extern float *x;
extern float *y;
extern int N;
extern float xavg;
extern float yavg;
extern float sxx;
extern float syy;
extern float sxy;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        float dx1 = x[i] - xavg;
        float dy1 = y[i] - yavg;
        sxx += dx1 * dx1;
        syy += dy1 * dy1;
        sxy += dx1 * dy1;

        if (i + 1 < N) {
            float dx2 = x[i+1] - xavg;
            float dy2 = y[i+1] - yavg;
            sxx += dx2 * dx2;
            syy += dy2 * dy2;
            sxy += dx2 * dy2;
        }
    }
}
