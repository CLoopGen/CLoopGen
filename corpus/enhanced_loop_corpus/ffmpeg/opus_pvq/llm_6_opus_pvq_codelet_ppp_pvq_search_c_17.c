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
    float temp_max_num = max_num;
    int temp_max_idx = max_idx;
    int temp_max_den = max_den;
    for (i = 0; i < N; i++) {
        const int ca = 1 ^ ((y[i] == 0) & (phase < 0));
        const int y_new = y_norm + 2 * phase * ((y[i]) >= 0 ? (y[i]) : (-(y[i])));
        float xy_new = xy_norm + 1 * phase * ((X[i]) >= 0 ? (X[i]) : (-(X[i])));
        xy_new = xy_new * xy_new;
        if (ca && (temp_max_den * xy_new) > (y_new * temp_max_num)) {
            temp_max_den = y_new;
            temp_max_num = xy_new;
            temp_max_idx = i;
        }
    }
    max_den = temp_max_den;
    max_num = temp_max_num;
    max_idx = temp_max_idx;
}
