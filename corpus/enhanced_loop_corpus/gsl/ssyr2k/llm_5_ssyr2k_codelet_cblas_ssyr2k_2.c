#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *c_local = C;
    int stride = ldc;
    int n = N;
    float beta_local = beta;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            int idx_prev = stride * i + (j > i ? j - 1 : j);
            int idx_curr = stride * i + j;
            if (j > i) {
                c_local[idx_curr] = c_local[idx_prev] * beta_local;
            } else {
                c_local[idx_curr] *= beta_local;
            }
        }
    }
}
