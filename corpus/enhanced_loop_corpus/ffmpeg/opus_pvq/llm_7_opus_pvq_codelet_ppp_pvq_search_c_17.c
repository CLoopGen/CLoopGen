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
    int local_max_idx = max_idx;
    float local_max_num = max_num;
    int local_max_den = max_den;
    for (i = 0; i < N; i += 2) {
        for (int j = 0; j < 2 && (i + j) < N; j++) {
            const int idx = i + j;
            const int ca = 1 ^ ((y[idx] == 0) & (phase < 0));
            const int y_new = y_norm + 2 * phase * ((y[idx]) >= 0 ? (y[idx]) : (-(y[idx])));
            float xy_new = xy_norm + 1 * phase * ((X[idx]) >= 0 ? (X[idx]) : (-(X[idx])));
            xy_new = xy_new * xy_new;
            if (ca && (local_max_den * xy_new) > (y_new * local_max_num)) {
                local_max_den = y_new;
                local_max_num = xy_new;
                local_max_idx = idx;
            }
        }
    }
    max_den = local_max_den;
    max_num = local_max_num;
    max_idx = local_max_idx;
}
