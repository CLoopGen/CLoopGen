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
if (N > 0) {
    for (i = 0; i < N; i += 2) {
        int upper = (i + 1 < N) ? i + 2 : i + 1;
        for (int k = i; k < upper; k++) {
            const int ca = 1 ^ ((y[k] == 0) & (phase < 0));
            const int y_new = y_norm + 2 * phase * ((y[k]) >= 0 ? (y[k]) : (-(y[k])));
            float xy_new = xy_norm + 1 * phase * ((X[k]) >= 0 ? (X[k]) : (-(X[k])));
            xy_new = xy_new * xy_new;
            if (ca && (max_den * xy_new) > (y_new * max_num)) {
                max_den = y_new;
                max_num = xy_new;
                max_idx = k;
            }
        }
    }
}
}
