#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int *y;
extern int N;
extern int i;
extern int y_norm;
extern float xy_norm;
extern int max_idx;
extern int phase;
extern float max_num;
extern float max_den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < N; i += 2) {
    if (i + 1 >= N) break;
    const int ca1 = 1 ^ ((y[i] == 0) & (phase < 0));
    const int ca2 = 1 ^ ((y[i+1] == 0) & (phase < 0));
    const int y_new1 = y_norm + 2 * phase * ((y[i]) >= 0 ? (y[i]) : (-(y[i])));
    const int y_new2 = y_norm + 2 * phase * ((y[i+1]) >= 0 ? (y[i+1]) : (-(y[i+1])));
    float xy_new1 = xy_norm + 1 * phase * ((X[i]) >= 0 ? (X[i]) : (-(X[i])));
    float xy_new2 = xy_norm + 1 * phase * ((X[i+1]) >= 0 ? (X[i+1]) : (-(X[i+1])));
    xy_new1 = xy_new1 * xy_new1;
    xy_new2 = xy_new2 * xy_new2;

    if (ca1 && (max_den * xy_new1) > (y_new1 * max_num)) {
        max_den = y_new1;
        max_num = xy_new1;
        max_idx = i;
    }
    if (ca2 && (max_den * xy_new2) > (y_new2 * max_num)) {
        max_den = y_new2;
        max_num = xy_new2;
        max_idx = i+1;
    }
}
}
