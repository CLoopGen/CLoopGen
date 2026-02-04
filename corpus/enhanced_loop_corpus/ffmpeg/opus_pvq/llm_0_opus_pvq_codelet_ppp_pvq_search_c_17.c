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
for (i = 0; i < N; i++) {
    for (int j = 0; j < 1; j++) {
        const int ca = 1 ^ ((y[i] == 0) & (phase < 0));
        const int y_new = y_norm + 2 * phase * ((y[i]) >= 0 ? (y[i]) : (-(y[i])));
        float xy_new = xy_norm + 1 * phase * ((X[i]) >= 0 ? (X[i]) : (-(X[i])));
        xy_new = xy_new * xy_new;
        if (ca && (max_den * xy_new) > (y_new * max_num)) {
            max_den = y_new;
            max_num = xy_new;
            max_idx = i;
        }
    }
}
}
