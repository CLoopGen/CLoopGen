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



void loop() {
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Assume indirect access pattern: access elements in reverse order (a form of indirect indexing)
    for (i = 0; i < N; i++) {
        const int idx = N - 1 - i; // Reverse traversal as a representative indirect access
        const int ca = 1 ^ ((y[idx] == 0) & (phase < 0));
        const int y_new = y_norm + 2 * phase * ((y[idx]) >= 0 ? (y[idx]) : (-(y[idx])));
        float xy_new = xy_norm + 1 * phase * ((X[idx]) >= 0 ? (X[idx]) : (-(X[idx])));
        xy_new = xy_new * xy_new;
        if (ca && (max_den * xy_new) > (y_new * max_num)) {
            max_den = y_new;
            max_num = xy_new;
            max_idx = idx;
        }
    }
}
