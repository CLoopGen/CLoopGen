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
    int i;
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            float dx1 = x[i] - xavg;
            float dy1 = y[i] - yavg;
            float dx2 = x[i+1] - xavg;
            float dy2 = y[i+1] - yavg;

            sxx += dx1 * dx1 + dx2 * dx2;
            syy += (y[i] - yavg) * (y[i] - xavg) + (y[i+1] - yavg) * (y[i+1] - xavg);
            sxy += dx1 * dy1 + dx2 * dy2;
        } else {
            float dx = x[i] - xavg;
            float dy = y[i] - yavg;
            sxx += dx * dx;
            syy += (y[i] - yavg) * (y[i] - xavg);
            sxy += dx * dy;
        }
    }
}
