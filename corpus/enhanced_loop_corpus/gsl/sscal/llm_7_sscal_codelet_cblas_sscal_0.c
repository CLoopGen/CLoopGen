#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern float *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 1.0f;
    float *local_X = X;
    int local_ix = ix;
    for (i = 0; i < N; i++) {
        temp = local_X[local_ix] * alpha;
        local_X[local_ix] = temp;
        local_ix += incX;
    }
    ix = local_ix;
}
