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
        float temp = 0.0f;
        for (j = i; j < n; j++) {
            int idx = stride * i + j;
            temp = c_local[idx] * beta_local;
            c_local[idx] = temp;
        }
    }
}
