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
    const int y_abs = (y[i] >= 0) ? y[i] : -y[i];
    const int y_new = y_norm + 2 * phase * y_abs;
    const float x_abs = (X[i] >= 0) ? X[i] : -X[i];
    float xy_new = xy_norm + 1 * phase * x_abs;
    xy_new = xy_new * xy_new;

    const int cond_active = !(y[i] == 0 && phase < 0);
    const int update_condition = cond_active && (max_den * xy_new > y_new * max_num);

    if (update_condition) {
        max_den = y_new;
        max_num = xy_new;
        max_idx = i;
    }
}
}
