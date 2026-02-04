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
    float *local_X = X;
    int local_ix = ix;
    float local_alpha = alpha;
    int local_N = N;
    int local_incX = incX;
    for (i = 0; i < local_N; i++) {
        local_X[local_ix] *= local_alpha;
        local_ix += local_incX;
    }
    ix = local_ix;
}
